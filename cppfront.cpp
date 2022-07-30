
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  cppfront
//===========================================================================

#include "sema.h"
#include <iostream>


namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  Stringingizing helpers
// 
//-----------------------------------------------------------------------

auto pad(int padding) -> std::string_view
{
    static std::string indent_str = std::string( 1024, ' ' );    // "1K should be enough for everyone"

    if (padding < 1) { 
        return "";
    }

    return {
        indent_str.c_str(),
        as<size_t>( std::min( padding, as<int>(std::ssize(indent_str))) )
    };
}


//-----------------------------------------------------------------------
// 
//  cppfront: a compiler instance
// 
//-----------------------------------------------------------------------
//
class cppfront
{
    std::string sourcefile;
    std::vector<error> errors;

    //  For building
    //
    source source;
    tokens tokens;
    parser parser;
    sema   sema;
    bool   source_loaded = true;

    //  For lowering
    //    
    bool            declarations_only   = true;  // print declarations only in first pass
    bool            in_definite_init    = false;
    bool            in_parameter_list   = false;
    bool            ignore_align        = false;
    int             ignore_align_indent = 0;
    lineno_t        ignore_align_lineno = 0;
    std::string*    emit_string_target  = nullptr;
    std::ofstream   out                 = {};    // Cpp1 syntax output file
    int             next_comment        = 0;     // index of the next comment not yet printed
    int             pad_for_this_line   = 0;
    source_position last_pos            = {};
    source_position preempt_pos         = {};

    std::vector<parameter_declaration_list_node*> function_returns = {};

public:
    //-----------------------------------------------------------------------
    //  Constructor
    // 
    //  filename    the source file to be processed
    //
    cppfront(std::string const& filename)
        : sourcefile{filename}
        , source{errors}
        , tokens{errors}
        , parser{errors}
        , sema  {errors}
    {
        //  "Constraints enable creativity in the right directions"
        //  sort of applies here
        //
        if (!sourcefile.ends_with(".cpp2"))
        {
            errors.emplace_back(
                source_position{-1, -1}, 
                "source filename must end with .cpp2: " + sourcefile
            );
        }

        //  Load the program file into memory
        //
        else if (!source.load(sourcefile))
        {
            if (errors.empty()) {
                errors.emplace_back(
                    source_position{-1, -1}, 
                    "file not found: " + sourcefile
                );
            }
            source_loaded = false;
        }

        else
        {
            //  Tokenize
            //
            tokens.lex( source.get_lines() );

            //  Parse
            //
            for (auto const& [line, entry] : tokens.get_map()) {
                if (!parser.parse(entry)) {
                    errors.emplace_back(
                        source_position{line, 0}, 
                        "parse failed for section starting here"
                    );
                }
            }

            //  Sema
            parser.visit( sema );

            //debug_print();

            if (!sema.apply_local_rules()) {
                errors.emplace_back(
                    source_position{-1, -1}, 
                    "program violates initialization safety guarantee - see previous errors"
                );
            }
        }
    }


    //-----------------------------------------------------------------------
    //  In the first pass we will print only declarations (the default).
    //  For the second pass this function enables printing definitions.
    //
    auto enable_definitions() -> void {
        declarations_only = false;
    }


    //-----------------------------------------------------------------------
    //  Printing helpers so we can track number of chars emitted so far in current line
    //
    auto emit_to_string( std::string* target = nullptr ) -> void {
        emit_string_target = target;
    }

    auto print_line_directive(source_position pos) -> void {
        if (last_pos.colno > 1) {
            out << "\n";
        }
        out << "#line " << pos.lineno << "\n";
    }

    auto on_newline() -> void {
        last_pos.colno    = 1;
        pad_for_this_line = 0;
    }

    auto print(std::string_view s) -> void {
        //  Option to emit everything to the specified string instead
        if (emit_string_target) {
            *emit_string_target += s;
            return;
        }

        out << s;

        auto last_newline = std::string::npos;
        auto newline_pos  = 0;
        while ((newline_pos = s.find('\n', newline_pos)) != std::string::npos) {
            pad_for_this_line = 0;
            ++last_pos.lineno;
            on_newline();
            last_newline = newline_pos;
            ++newline_pos;
        }

        if (last_newline != std::string::npos) {
            last_pos.colno = s.length() - last_newline;
        }
        else {
            last_pos.colno += s.length();
        }
    }

    auto preempt_position(source_position pos) -> void {
        preempt_pos = pos;
    }

    auto ignore_alignment(bool ignore, int indent = 0) -> void {
        //  We'll only ever call this in local non-nested true/false pairs.
        //  If we ever want to generalize (support nesting, or make it non-brittle),
        //  wrap this in a push/pop stack.
        if (ignore) {
            ignore_align        = true;
            ignore_align_indent = indent;
            ignore_align_lineno = last_pos.lineno;      // push state
        }
        else {
            ignore_align        = false;
            ignore_align_indent = 0;
            last_pos.lineno     = ignore_align_lineno;  // pop state
        }
    }

    auto add_pad_in_this_line(colno_t extra) -> void {
        pad_for_this_line += extra;
    }

    auto print(std::string_view s, source_position pos) -> void {
        //  For now, the preempt position use cases are about overriding colno
        //  and only on the same line. In the future, we might have more use cases.
        auto adjusted_pos = pos;
        if (preempt_pos != source_position{} && preempt_pos.lineno == pos.lineno) {
            adjusted_pos.colno = preempt_pos.colno;
        }

        align_to(adjusted_pos);
        print(s);
        preempt_pos = {};
    }


    //-----------------------------------------------------------------------
    //  Catch up with comment/blank lines
    // 
    auto flush_comments( source_position pos ) -> void
    {
        auto& comments = tokens.get_comments(); // for readability

        //  Add unprinted comments and blank lines as needed to catch up vertically
        //
        while (last_pos.lineno < pos.lineno)
        {
            //  If a comment goes on this line, print it
            if (next_comment < std::ssize(comments) && comments[next_comment].start.lineno == last_pos.lineno)
            {
                //  For a line comment, start it at the right indentation and print it
                //  with a newline end
                if (comments[next_comment].kind == comment::comment_kind::line_comment) {
                    //  Don't print comments in the declarations pass, to avoid duplication
                    if (declarations_only) {
                        ++last_pos.lineno;
                    }
                    else {
                        print( pad( comments[next_comment].start.colno - last_pos.colno + 1 ) );
                        print( comments[next_comment].text );
                        assert( comments[next_comment].text.find("\n") == std::string::npos );  // we shouldn't have newlines
                        print("\n");
                    }
                }

                //  For a stream comment, pad out to its column (if we haven't passed it already)
                //  and emit it there
                else {
                    //  Don't print comments in the declarations pass, to avoid duplication
                    if (declarations_only) {
                        last_pos.lineno += 
                            std::count(
                                comments[next_comment].text.begin(), 
                                comments[next_comment].text.end(), 
                                '\n');
                    }
                    else {
                        print( pad( comments[next_comment].start.colno - last_pos.colno ) );
                        print( comments[next_comment].text );
                        assert(last_pos.lineno <= pos.lineno);  // we shouldn't have overshot
                    }
                }

                ++next_comment;
            }

            //  Otherwise, just print a blank line
            else {
                print("\n");
 
                //  Don't print multiple successive blank lines in the declarations pass, they're not needed
                if (declarations_only) {
                    last_pos = {pos.lineno, 1};
                    break;
                }
            }
        }

        //  In case we emitted extra lines, such as for a multi return
        //  value structs, re-sync with the original source
        if (!ignore_align && ignore_align_lineno > 0) {
            print_line_directive(pos.lineno);
            ignore_align_lineno = 0;
            //last_pos.lineno = pos.lineno;
            //on_newline();
        }
    }


    //-----------------------------------------------------------------------
    //  To position ourselves as close to the programmer's original location
    //  as possible, and to catch up with displaying comments
    //
    auto align_to( source_position pos ) -> void
    {
        //  This is used when we're generating new code sections,
        //  such as return value structs
        if (ignore_align) {
            print( pad( ignore_align_indent - last_pos.colno ) );
            return;
        }

        flush_comments( pos );

        //  Finally, align to the target column
        //
        pos.colno += pad_for_this_line;
        print( pad( pos.colno - last_pos.colno ) );
    }


    //-----------------------------------------------------------------------
    //  lower_to_cpp1
    // 
    //  Emits the target file with the last '2' stripped -> .cpp
    //
    auto lower_to_cpp1() -> void
    {
        out.open( sourcefile.substr(0, std::ssize(sourcefile) - 1) );

        //  First, echo the non-Cpp2 parts
        //
        auto cpp2_found    = false;
        auto prev_line_cat = source_line::category::cpp1;

        for (lineno_t curr_lineno = 0; auto const& line : source.get_lines())
        {
            //  Skip dummy line we added to make 0-vs-1-based offsets readable
            if (curr_lineno != 0) {

                //  If it's a non-Cpp2 line, emit it
                if (line.cat != source_line::category::cpp2) {
                    //  If the previous line was Cpp2, emit a #line directive
                    if (prev_line_cat == source_line::category::cpp2) {
                        out << "#line " << curr_lineno << "\n";
                    }

                    //  Emit the original line
                    out << line.text << "\n";
                }
                else {
                    cpp2_found = true;
                }

                prev_line_cat = line.cat;
            }
            ++curr_lineno;
        }

        //  We can stop here if there's no Cpp2 code -- a file with no Cpp2
        //  should have perfect passthrough verifiable with diff, including
        //  that we didn't misidentify anything as Cpp2 including in the
        //  presence of nonstandard vendor extensions
        //
        if (!cpp2_found) {
            return;
        }

        //  If there is Cpp2 code, we have more to do...
        //  Next, bring in the Cpp2 helpers
        //
        out << "\n\n//=== Cpp2 ======================================================================"
            << "\n\n#include \"cpp2util.h\"\n";

        //  Next, emit the Cpp2 forward declarations
        //
        emit( parser.get_parse_tree() );  // starts at translation_unit_node

        out << "\n//-------------------------------------------------------------------------------\n";

        //  Next, emit the Cpp2 definitions
        //
        enable_definitions();
        emit( parser.get_parse_tree() );  // starts at translation_unit_node
    }


    //-----------------------------------------------------------------------
    //
    //  emit() functions - each emits a kind of node
    // 
    //  The body often mirrors the node's visit() function, unless customization
    //  is needed where Cpp1 and Cpp2 have different grammar orders
    //

    //-----------------------------------------------------------------------
    //  try_emit
    // 
    //  Helper to emit whatever is in a variant where each
    //  alternative is a smart pointer
    //
    template <int I>
    auto try_emit(auto& v, auto... more) -> void {
        if (v.index() == I) {
            auto const& alt = std::get<I>(v);
            assert (alt);
            emit (*alt, more...);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(token const& n) -> void
    {
        if (n.type() == lexeme::StringLiteral) {
            print("\"");
            print(n, n.position());
            print("\"");
        }
        else if (n.type() == lexeme::CharacterLiteral) {
            print("\'");
            print(n, n.position());
            print("\'");
        }
        else {
            print(n, n.position());
        }

        if (is_definite_initialization(&n)) {
            in_definite_init = true;
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(unqualified_id_node const& n) -> void
    {
        if (is_definite_last_use(n.identifier)) {
            print( "std::move(", n.position() );
            print( *n.identifier );
            print( ")" );
            return;
        }

        print( *n.identifier, n.position() );
        in_definite_init = is_definite_initialization(n.identifier);

        if (!in_definite_init && !in_parameter_list) {
            if (auto decl = sema.get_declaration_of(*n.identifier); decl && !decl->initializer) {
                print( ".value()" );
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(qualified_id_node const& n) -> void
    {
        for (bool first = true; auto const& id : n.ids)
        {
            if (first) {
                print( *id->identifier, id->identifier->position() );
                first = false;
            }
            else {
                print( "::" );
                print( *id->identifier );   // no position, we don't want to create gaps
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(id_expression_node const& n) -> void
    {
        try_emit<id_expression_node::qualified  >(n.id);
        try_emit<id_expression_node::unqualified>(n.id);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        compound_statement_node const&  n, 
        std::vector<std::string> const& function_ret_locals = {},
        colno_t                         function_indent     = 1
    ) 
        -> void
    {
        print( "{", n.open_brace );

        if (!function_ret_locals.empty()) {
            ignore_alignment( true, function_indent + 4 );
            auto pos = source_position{};
            if (!n.statements.empty()) {
                pos = n.statements.front()->position();
            }
            for (auto& loc : function_ret_locals) {
                print("\n");
                print(loc, pos);
            }
            ignore_alignment( false );
        }

        for (auto const& x : n.statements) {
            assert(x);
            emit(*x);
        }

        print( "}", n.close_brace );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(selection_statement_node const& n) -> void
    {
        assert(n.identifier);
        emit(*n.identifier);

        print (" (");
        add_pad_in_this_line(1);

        assert(n.expression);
        emit(*n.expression);

        print (") ");
        add_pad_in_this_line(1);

        assert(n.true_branch);
        emit(*n.true_branch);

        if (n.has_source_false_branch) {
            print ("else ", n.else_pos);
            emit(*n.false_branch);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(return_statement_node const& n) -> void
    {
        assert(n.identifier);
        emit(*n.identifier);

        //std::vector<parameter_declaration_list_node*> function_returns = {};
        assert (!function_returns.empty());
        if (function_returns.back()) {
            ignore_alignment( true );
            print(" { ");
            auto& parameters = function_returns.back()->parameters;
            for (bool first = true; auto& param : parameters) {
                if (!first) {
                    print(", ");
                }
                first = false;
                assert(param->declaration->identifier);
                emit (*param->declaration->identifier);
            }
            print(" }");
            ignore_alignment( false );
        }

        print(";");
    }


    //-----------------------------------------------------------------------
    //
    auto emit(primary_expression_node const& n) -> void
    {
        try_emit<primary_expression_node::identifier     >(n.expr);
        try_emit<primary_expression_node::expression_list>(n.expr);
        try_emit<primary_expression_node::id_expression  >(n.expr);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(postfix_expression_node const& n) -> void
    {
        assert(n.expr);

        auto suffix            = std::string{};
        auto emitted_n         = false;
        auto last_was_prefixed = false;
        auto all_prefix        = true;

        std::vector<std::string> stack;

        auto emit_as_prefixed = [&](std::string_view sv) -> void {
            std::string s;
            if (!all_prefix && !last_was_prefixed) { s += "("; }
            s += sv;
            stack.push_back(s);

            if (!all_prefix && !last_was_prefixed) { suffix += ")"; }

            last_was_prefixed = true;
        };

        auto flush = [&] () -> void {
            for (auto i = std::rbegin(stack); i != std::rend(stack); ++i) {
                print(*i);
            }
            stack = {};
            if (!emitted_n) {
                emit(*n.expr);
                emitted_n = true;
            }
            print(suffix);
            suffix = "";
        };

        auto op_switches_to_prefix = [&](auto const& op) -> bool {
            return op == "--" || op == "++" || op == "^"  || op == "&"  || op == "~";
        };

        for (auto const& x : n.ops) {
            if (!op_switches_to_prefix(*x.op)) {
                all_prefix = false;
            }
        }

        align_to(n.position());

        for (auto const& x : n.ops) {
            assert(x.op);

            //  Handle the Cpp2 postfix operators to emit in Cpp1 as prefix
            //
            if (op_switches_to_prefix(*x.op)) {
                if (*x.op == "^") {
                    emit_as_prefixed("*"); }
                else {
                    emit_as_prefixed(*x.op);
                }
            }

            //  If we have a legit suffix operator, it's time to flush
            //
            else {
                flush();

                emit(*x.op);
                if (x.expr_list) {
                    emit(*x.expr_list);
                    assert(x.op_close);
                    emit(*x.op_close);
                }

                last_was_prefixed = false;
            }
        }

        flush();
    }


    //-----------------------------------------------------------------------
    //
    auto emit(prefix_expression_node const& n) -> void
    {
        for (auto const& x : n.ops) {
            assert(x);
            emit(*x);
        }
        assert(n.expr);
        emit(*n.expr);
    }


    //-----------------------------------------------------------------------
    //
    template<
        String   Name,
        typename Term
    >
    auto emit(binary_expression_node<Name,Term> const& n) -> void
    {
        assert(n.expr);
        emit(*n.expr);

        for (auto const& x : n.terms) {
            assert(x.op);
            assert(x.expr);

            //  Normally we'll just emit the operator, but if this is an
            //  assignment that's a definite initialization, change it to
            //  a .construct() call
            if (x.op->type() == lexeme::Assignment && in_definite_init) {
                print( ".construct(" );
                emit(*x.expr);
                print( ")" );
            }
            else {
                emit(*x.op);
                emit(*x.expr);
            }

        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_node const& n) -> void
    {
        assert(n.expr);
        emit(*n.expr);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_list_node const& n) -> void
    {
        for (auto const& x : n.expressions) {
            if (x.pass != passing_style::in) {
                assert(to_string_view(x.pass) == "out");
                print("&");
                add_pad_in_this_line(-3);
            }
            assert(x.expr);
            emit(*x.expr);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_statement_node const& n, bool can_have_semicolon, bool function_body = false ) -> void
    {
        assert(n.expr);

        if (function_body) {
            print("{ return ");
        }

        emit(*n.expr);
        if (n.has_semicolon && can_have_semicolon) {
            print(";");
        }

        if (function_body) {
            print("}");
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(
        statement_node const&           n, 
        bool                            can_have_semicolon  = true, 
        bool                            function_body       = false,
        std::vector<std::string> const& function_ret_locals = {},
        colno_t                         function_indent     = 1
    )
        -> void
    {
        try_emit<statement_node::expression >(n.statement, can_have_semicolon, function_body);
        try_emit<statement_node::compound   >(n.statement, function_ret_locals, function_indent);
        try_emit<statement_node::selection  >(n.statement);
        try_emit<statement_node::declaration>(n.statement);
        try_emit<statement_node::return_    >(n.statement);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_node const& n, bool returns = false) -> void
    {
        //  Can't declare functions as parameters -- only pointers to functions which are objects
        assert( n.declaration );
        assert( n.declaration->is(declaration_node::object) );

        auto const& id_expr = *std::get<declaration_node::object>(n.declaration->type);

        //  First any prefix
        if (!returns)
        {
            switch (n.pass) {
            using enum passing_style;
            break;case in     : print ( "cpp2::in<",  n.position() );
            break;case out    : print ( "cpp2::out<", n.position() );
            }
        }

        preempt_position( n.position() );
        emit( id_expr );

        //  Then any suffix
        if (!returns)
        {
            switch (n.pass) {
            using enum passing_style;
            break;case in     : print ( ">" );
            break;case copy   : print ( " const" );
            break;case inout  : print ( "&" );
            break;case out    : print ( ">" );
            break;case move   : print ( "&&" );
            break;case forward: print ( "&&" ); assert(false); // TODO: support forward parameters
            }

            preempt_position( n.position() );
        }

        print( " " );
        emit( *n.declaration->identifier );

        if (!returns && n.declaration->initializer) {
            print ( " = " );
            emit(*n.declaration->initializer);
        }

        //TODO - when we get to classes and inheritance
        //o << pre(indent+1);
        //using enum parameter_declaration_node::modifier;
        //switch (n.mod) {
        //break;case implicit  : o << "implicit";
        //break;case virtual_  : o << "virtual";
        //break;case override_ : o << "override";
        //break;case final_    : o << "final";
        //}
        //o << "\n";
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_list_node const& n, bool returns = false) -> void
    {
        in_parameter_list = true;

        if (returns) {
            print( "{\n" );
        }
        else {
            print( "(", n.pos_open_paren );
        }

        for (auto first = true; auto const& x : n.parameters) {
            if (!first && !returns) {
                print( ", " );
            }
            assert(x);
            emit(*x, returns);
            first = false;
            if (returns) {
                print( ";\n" );
            }
        }

        if (returns) {
            print( "};" );
        }
        else {
            //  Position heuristic (aka hack): Avoid emitting extra whitespace before )
            //  beyond column 10
            auto col = std::min( n.pos_close_paren.colno, colno_t{10} );
            print( ")", { n.pos_close_paren.lineno, col } );
        }

        in_parameter_list = false;
    }


    //-----------------------------------------------------------------------
    //
    auto emit(function_type_node const& n, token const* ident) -> void
    {
        assert(n.parameters);
        emit(*n.parameters);

        if (!n.throws) {
            print( " noexcept" );
        }

        print( " -> " );

        if (!n.returns || std::ssize(n.returns->parameters) == 0) {
            print( "void" );
        }
        else if (std::ssize(n.returns->parameters) == 1) {
            //  For a single return, get its declaration node from its type
            auto& param   = n.returns->parameters.front();
            assert(param && param->declaration);
            auto& decl    = *param->declaration;
            assert (decl.type.index() == declaration_node::object);
            auto& id_expr = *std::get<declaration_node::object>(decl.type);

            emit( id_expr );

            if (param->pass == passing_style::forward) {
                print("&");
            }
        }
        else {
            print( *ident );
            print( "__ret");
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(declaration_node const& n) -> void
    {
        //  If this is a function that has multiple return values,
        //  first we need to emit the struct that contains the returns
        if (declarations_only && n.is(declaration_node::function)) 
        {
            auto& func = std::get<declaration_node::function>(n.type);
            assert(func);
            if (func->returns && std::ssize(func->returns->parameters) >= 1) {
                ignore_alignment( true, n.position().colno + 4 );
                print( "struct ");
                print( *n.identifier->identifier );
                print( "__ret ");
                emit(*func->returns, true);
                ignore_alignment( false );
            }
        }

        //  Common to functions and objects
        print( "auto ", n.position() );
        print( *n.identifier->identifier );

        //  Function
        if (n.is(declaration_node::function))
        {
            auto& func = std::get<declaration_node::function>(n.type);
            assert(func);

            //  Function declaration
            emit( *func, n.identifier->identifier );
            if (declarations_only) {
                print( ";" );
                last_pos = n.decl_end;
                print("\n");
                return;
            }

            if (func->returns && std::ssize(func->returns->parameters) >= 1) {
                function_returns.push_back(func->returns.get());
            }
            else {
                function_returns.push_back(nullptr);
            }

            //  Function body
            assert( n.initializer );
            preempt_position(n.equal_sign);
            print( " " );

            auto function_return_locals = std::vector<std::string>{};
            if (func->returns && std::ssize(func->returns->parameters) >= 1)
            {
                for (auto& param : func->returns->parameters)
                {
                    assert(param && param->declaration);
                    auto& decl    = *param->declaration;
                    assert(decl.type.index() == declaration_node::object);
                    auto& id_expr = *std::get<declaration_node::object>(decl.type);
                    assert(id_expr.id.index() == id_expression_node::unqualified);
                    auto& type_id = std::get<id_expression_node::unqualified>(id_expr.id);
                    assert(type_id);

                    auto loc = std::string{};
                    if (!decl.initializer) {
                        loc += ("cpp2::deferred_init<");
                    }
                    loc += ((std::string_view)*type_id->identifier);
                    if (!decl.initializer) {
                        loc += (">");
                    }
                    loc += " ";
                    loc += ((std::string_view)*decl.identifier->identifier);
                    if (decl.initializer)
                    {
                        std::string init;
                        emit_to_string(&init);
                        print ( " = " );
                        if (decl.initializer->statement.index() != statement_node::expression) {
                            errors.emplace_back(
                                decl.initializer->position(),
                                "return value initializer must be an expression"
                            );
                            return;
                        }
                        auto& expr = std::get<statement_node::expression>(decl.initializer->statement);
                        assert(expr);

                        emit(*decl.initializer);
                        emit_to_string();

                        loc += init;
                    }
                    loc += ";";
                    function_return_locals.push_back(loc);
                }
            }

            emit( *n.initializer, true, true, function_return_locals, n.position().colno );

            function_returns.pop_back();
        }

        //  Object with initializer
        else if (n.is(declaration_node::object)) {

            auto& type = std::get<declaration_node::object>(n.type);

            //  If there's an initializer, emit it
            if (n.initializer)
            {
                print( " = ", n.equal_sign );
                if (type->id.index() != id_expression_node::empty) {
                    emit( *type );
                    print( " { ", n.equal_sign );
                }

                assert( n.initializer );
                emit( *n.initializer, false );

                if (!type->id.index() == id_expression_node::empty) {
                    print( " }" );
                }
                print( ";" );
            }

            //  If not, use cpp2::deferred_init<T>, e.g.,
            //    auto s = deferred_init<vector<int>>{};
            else {
                print( " = cpp2::deferred_init<" );
                emit( *type );
                print( ">{};" );
            }

        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(translation_unit_node const& n) -> void
    {
        if (n.declarations.empty()) {
            return;
        }

        //  Restart positioning info for this pass
        //
        auto curr_map_section = tokens.get_map().cbegin();
        assert( curr_map_section != tokens.get_map().cend() );
        assert( !curr_map_section->second.empty() );

        next_comment = 0;
        last_pos     = { curr_map_section->first, 0 };
        print_line_directive( last_pos );

        //  Emit each declaration
        //
        for (auto const& x : n.declarations)
        {
            //  If we're leaving the current Cpp2 code section, we need to
            //  reanchor last_pos to be relative to the next section
            //
            if (curr_map_section != tokens.get_map().cend())
            {
                assert (std::ssize(curr_map_section->second) > 0);
                if (last_pos.lineno > curr_map_section->second.back().position().lineno)
                {
                    if (++curr_map_section != tokens.get_map().cend()) {
                        last_pos = { curr_map_section->first, 0 };
                        print_line_directive( last_pos );
                    }
                }
            }

            //  And then emit this declaration
            //
            assert(x);
            emit(*x);
        }
    }


    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print() -> void
    {
        for (auto&& error : errors) {
            error.print(std::cerr, strip_path(sourcefile));
        }

        //  Only create debug output files if we managed to load the source file.
        //
        if (source_loaded)
        {
            auto out_source     = std::ofstream{ sourcefile+"-source"  };
            source.debug_print( out_source     );

            auto out_tokens     = std::ofstream{ sourcefile+"-tokens"  };
            tokens.debug_print( out_tokens     );

            auto out_parse      = std::ofstream{ sourcefile+"-parse"   };
            auto tree_printer   = parse_tree_printer{out_parse  };
            parser.visit      ( tree_printer   );

            auto out_symbols    = std::ofstream{ sourcefile+"-symbols" };
            sema.debug_print  ( out_symbols    );
        }
    }
};

}


//===========================================================================
//  main - driver
//===========================================================================

using namespace std;
using namespace cpp2;

int main(int argc, char* argv[]) 
{
    for (auto i = 1; i < argc; ++i) {
        cppfront c(argv[i]);
        c.debug_print();
        c.lower_to_cpp1();
    }
}

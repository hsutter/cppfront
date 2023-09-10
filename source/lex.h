
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//===========================================================================
//  Lexer
//===========================================================================

#ifndef __CPP2_LEX
#define __CPP2_LEX

#include "io.h"
#include <map>
#include <climits>
#include <deque>
#include <cstring>


namespace cpp2 {

//-----------------------------------------------------------------------
//
//  lexeme: represents the type of a token
//
//-----------------------------------------------------------------------
//

enum class lexeme : std::int8_t {
    SlashEq,
    Slash,
    LeftShiftEq,
    LeftShift,
    Spaceship,
    LessEq,
    Less,
    RightShiftEq,
    RightShift,
    GreaterEq,
    Greater,
    PlusPlus,
    PlusEq,
    Plus,
    MinusMinus,
    MinusEq,
    Arrow,
    Minus,
    LogicalOrEq,
    LogicalOr,
    PipeEq,
    Pipe,
    LogicalAndEq,
    LogicalAnd,
    MultiplyEq,
    Multiply,
    ModuloEq,
    Modulo,
    AmpersandEq,
    Ampersand,
    CaretEq,
    Caret,
    TildeEq,
    Tilde,
    EqualComparison,
    Assignment,
    NotEqualComparison,
    Not,
    LeftBrace,
    RightBrace,
    LeftParen,
    RightParen,
    LeftBracket,
    RightBracket,
    Scope,
    Colon,
    Semicolon,
    Comma,
    Dot,
    Ellipsis,
    QuestionMark,
    At,
    Dollar,
    FloatLiteral,
    BinaryLiteral,
    DecimalLiteral,
    HexadecimalLiteral,
    StringLiteral,
    CharacterLiteral,
    UserDefinedLiteralSuffix,
    Keyword,
    Cpp1MultiKeyword,
    Cpp2FixedType,
    Identifier,
    None = 127
};

auto is_literal(lexeme l) -> bool {
    switch (l) {
    break;case lexeme::FloatLiteral:
          case lexeme::BinaryLiteral:
          case lexeme::DecimalLiteral:
          case lexeme::HexadecimalLiteral:
          case lexeme::StringLiteral:
          case lexeme::CharacterLiteral:    return true;
    break;default:                          return false;
    }
}

auto close_paren_type(lexeme l)
    -> lexeme
{
    switch (l) {
    break;case lexeme::LeftBrace:   return lexeme::RightBrace;
    break;case lexeme::LeftBracket: return lexeme::RightBracket;
    break;case lexeme::LeftParen:   return lexeme::RightParen;
    break;default:                  return lexeme::None;
    }
}


template<typename T>
    requires std::is_same_v<T, std::string>
auto __as(lexeme l)
    -> std::string
{
    switch (l) {
    break;case lexeme::SlashEq:             return "SlashEq";
    break;case lexeme::Slash:               return "Slash";
    break;case lexeme::LeftShiftEq:         return "LeftShiftEq";
    break;case lexeme::LeftShift:           return "LeftShift";
    break;case lexeme::Spaceship:           return "Spaceship";
    break;case lexeme::LessEq:              return "LessEq";
    break;case lexeme::Less:                return "Less";
    break;case lexeme::RightShiftEq:        return "RightShiftEq";
    break;case lexeme::RightShift:          return "RightShift";
    break;case lexeme::GreaterEq:           return "GreaterEq";
    break;case lexeme::Greater:             return "Greater";
    break;case lexeme::PlusPlus:            return "PlusPlus";
    break;case lexeme::PlusEq:              return "PlusEq";
    break;case lexeme::Plus:                return "Plus";
    break;case lexeme::MinusMinus:          return "MinusMinus";
    break;case lexeme::MinusEq:             return "MinusEq";
    break;case lexeme::Arrow:               return "Arrow";
    break;case lexeme::Minus:               return "Minus";
    break;case lexeme::LogicalOrEq:         return "LogicalOrEq";
    break;case lexeme::LogicalOr:           return "LogicalOr";
    break;case lexeme::PipeEq:              return "PipeEq";
    break;case lexeme::Pipe:                return "Pipe";
    break;case lexeme::LogicalAndEq:        return "LogicalAndEq";
    break;case lexeme::LogicalAnd:          return "LogicalAnd";
    break;case lexeme::MultiplyEq:          return "MultiplyEq";
    break;case lexeme::Multiply:            return "Multiply";
    break;case lexeme::ModuloEq:            return "ModuloEq";
    break;case lexeme::Modulo:              return "Modulo";
    break;case lexeme::AmpersandEq:         return "AmpersandEq";
    break;case lexeme::Ampersand:           return "Ampersand";
    break;case lexeme::CaretEq:             return "CaretEq";
    break;case lexeme::Caret:               return "Caret";
    break;case lexeme::TildeEq:             return "TildeEq";
    break;case lexeme::Tilde:               return "Tilde";
    break;case lexeme::EqualComparison:     return "EqualComparison";
    break;case lexeme::Assignment:          return "Assignment";
    break;case lexeme::NotEqualComparison:  return "NotEqualComparison";
    break;case lexeme::Not:                 return "Not";
    break;case lexeme::LeftBrace:           return "LeftBrace";
    break;case lexeme::RightBrace:          return "RightBrace";
    break;case lexeme::LeftParen:           return "LeftParen";
    break;case lexeme::RightParen:          return "RightParen";
    break;case lexeme::LeftBracket:         return "LeftBracket";
    break;case lexeme::RightBracket:        return "RightBracket";
    break;case lexeme::Scope:               return "Scope";
    break;case lexeme::Colon:               return "Colon";
    break;case lexeme::Semicolon:           return "Semicolon";
    break;case lexeme::Comma:               return "Comma";
    break;case lexeme::Dot:                 return "Dot";
    break;case lexeme::Ellipsis:            return "Ellipsis";
    break;case lexeme::QuestionMark:        return "QuestionMark";
    break;case lexeme::At:                  return "At";
    break;case lexeme::Dollar:              return "Dollar";
    break;case lexeme::FloatLiteral:        return "FloatLiteral";
    break;case lexeme::BinaryLiteral:       return "BinaryLiteral";
    break;case lexeme::DecimalLiteral:      return "DecimalLiteral";
    break;case lexeme::HexadecimalLiteral:  return "HexadecimalLiteral";
    break;case lexeme::StringLiteral:       return "StringLiteral";
    break;case lexeme::CharacterLiteral:    return "CharacterLiteral";
    break;case lexeme::UserDefinedLiteralSuffix:    return "UserDefinedLiteralSuffix";
    break;case lexeme::Keyword:             return "Keyword";
    break;case lexeme::Cpp1MultiKeyword:    return "Cpp1MultiKeyword";
    break;case lexeme::Cpp2FixedType:       return "Cpp2FixedType";
    break;case lexeme::Identifier:          return "Identifier";
    break;case lexeme::None:                return "(NONE)";
    break;default:                          return "INTERNAL-ERROR";
    }
};


auto is_operator(lexeme l)
    -> bool
{
    return l <= lexeme::Not;
}


//-----------------------------------------------------------------------
//
//  token: represents a single token
//
//     Note: by reference, thge test into the program's source lines
//
//-----------------------------------------------------------------------
//
class token
{
public:
    token(
        char const*     start,
        auto            count,
        source_position pos,
        lexeme          type
    )
      : sv      {start, unsafe_narrow<ulong>(count)}
      , pos     {pos}
      , lex_type{type}
    {
    }

    token(
        char const*     sz,
        source_position pos,
        lexeme          type
    )
      : sv      {sz}
      , pos     {pos}
      , lex_type{type}
    {
    }

    auto as_string_view() const
        -> std::string_view
    {
        assert (sv.data());
        return sv;
    }

    operator std::string_view() const
    {
        return as_string_view();
    }

    auto operator== (token const& t) const
        -> bool
    {
        return operator std::string_view() == t.operator std::string_view();
    }

    auto operator== (std::string_view s) const
        -> bool
    {
        return s == this->operator std::string_view();
    }

    auto to_string( bool text_only = false ) const
        -> std::string
    {
        auto text = std::string{sv};
        if (text_only) {
            return text;
        }
        else {
            return __as<std::string>(lex_type) + std::string(": ") + text;
        }
    }

    friend auto operator<< (auto& o, token const& t)
        -> auto&
    {
        return o << std::string_view(t);
    }

    auto position_col_shift( colno_t offset )
        -> void
    {
        assert (pos.colno + offset > 0);
        pos.colno += offset;
    }

    auto position() const -> source_position { return pos;       }

    auto length  () const -> int             { return sv.size(); }

    auto type    () const -> lexeme          { return lex_type;  }

    auto set_type(lexeme l) -> void          { lex_type = l;     }

    auto visit(auto& v, int depth) const
        -> void
    {
        v.start(*this, depth);
    }

private:
    std::string_view sv;
    source_position  pos;
    lexeme           lex_type;
};

static_assert (CHAR_BIT == 8);


auto labelized_position(token const* t)
    -> std::string
{
    auto ret = std::string{};
    if (t) {
        ret +=
            std::to_string(t->position().lineno) +
            "_" +
            std::to_string(t->position().colno);
    }
    return ret;
}


//-----------------------------------------------------------------------
//
//  A StringLiteral could include captures
//
auto expand_string_literal(
    std::string_view          text,
    std::vector<error_entry>& errors,
    source_position           src_pos
)
    -> std::string
{
    auto const length = std::ssize(text);

    assert(length >= 2);
    if (text.back() != '"') {
        errors.emplace_back(
            source_position( src_pos ),
            "not a legal string literal",
            false,
            true    // a noisy fallback error message
        );
        return {};
    }

    auto pos = 0;

    //  Skip prefix to first non-" character
    while (
        pos < length
        && text[pos] != '"'
        )
    {
        ++pos;
    }
    assert(
        pos < length
        && text[pos] == '"'
    );
    ++pos;
    auto current_start = pos;   // the current offset before which the string has been added to ret

    auto parts = string_parts{std::string(text.substr(0, current_start)), // begin sequence ", U", u8" depends on the string type 
                              "\"", // end sequence
                              string_parts::on_both_ends}; // add opening and closing sequence to generated string

    bool escape = false;
    //  Now we're on the first character of the string itself
    for (
        ;
        pos < length && !(!escape && text[pos] == '"');
        ++pos
        )
    {
        escape = (text[pos] == '\\' && !escape);
        //  Find the next )$
        if (
            text[pos] == '$'
            && text[pos-1] == ')'
            )
        {
            //  Scan back to find the matching (
            auto paren_depth = 1;
            auto open = pos - 2;

            for( ; open > current_start; --open)
            {
                if (text[open] == ')') {
                    ++paren_depth;
                }
                else if (text[open] == '(') {
                    --paren_depth;
                    if (paren_depth == 0) {
                        break;
                    }
                }
            }
            if (text[open] != '(')
            {
                errors.emplace_back(
                    source_position( src_pos.lineno, src_pos.colno + pos ),
                    "no matching ( for string interpolation ending in )$"
                );
                return {};
            }

            //  'open' is now at the matching (

            //  Put the next non-empty non-interpolated chunk straight into ret
            if (open != current_start) {
                parts.add_string(text.substr(current_start, open - current_start));
            }

            //  Then put interpolated chunk into ret
            auto chunk = std::string{text.substr(open, pos - open)};
            { // unescape chunk string
                auto last_it = std::remove_if(std::begin(chunk), std::end(chunk), [escape = false](const auto& e) mutable {
                    escape = !escape && e == '\\';
                    return escape;
                });
                chunk.erase(last_it, std::end(chunk));
            }
            parts.add_code("cpp2::to_string" + chunk);

            current_start = pos+1;
        }
    }

    //  Now we should be on the the final " closing the string
    assert(
        pos == length-1
        && text[pos] == '"'
    );

    //  Put the final non-interpolated chunk straight into ret
    if (current_start < std::ssize(text)-1) {
        parts.add_string(text.substr(current_start, std::ssize(text)-current_start-1));
    }

    return parts.generate();
}

auto expand_raw_string_literal(
    const std::string&           opening_seq,
    const std::string&           closing_seq,
    string_parts::adds_sequences closing_strategy,
    std::string_view             text,
    std::vector<error_entry>&    errors,
    source_position src_pos
)
    -> string_parts
{
    auto const length = std::ssize(text);
    auto pos = 0;
    auto current_start   = pos;   // the current offset before which the string has been added to ret
    string_parts parts{opening_seq, closing_seq, closing_strategy};

    //  Now we're on the first character of the string itself
    for ( ; pos < length; ++pos )
    {
        //  Find the next )$
        if (text[pos] == '$' && text[pos-1] == ')')
        {
            //  Scan back to find the matching (
            auto paren_depth = 1;
            auto open = pos - 2;

            for( ; open > current_start; --open)
            {
                if (text[open] == ')') {
                    ++paren_depth;
                }
                else if (text[open] == '(') {
                    --paren_depth;
                    if (paren_depth == 0) {
                        break;
                    }
                }
            }
            if (text[open] != '(')
            {
                errors.emplace_back(
                    source_position( src_pos.lineno, src_pos.colno + pos ),
                    "no matching ( for string interpolation ending in )$"
                );
                return parts;
            }

            //  'open' is now at the matching (

            //  Put the next non-empty non-interpolated chunk straight into ret
            if (open != current_start) {
                parts.add_string(text.substr(current_start, open - current_start));
            }
            //  Then put interpolated chunk into ret
            parts.add_code("cpp2::to_string" + std::string{text.substr(open, pos - open)});

            current_start = pos+1;
        }
    }

    //  Put the final non-interpolated chunk straight into ret
    if (current_start < std::ssize(text)) {
        parts.add_string(text.substr(current_start));
    }

    return parts;
}

//-----------------------------------------------------------------------
//  lex: Tokenize a single line while maintaining inter-line state
//
//  mutable_line            the line to be tokenized
//  lineno                  the current line number
//  in_comment              are we currently in a comment
//  current_comment         the current partial comment
//  current_comment_start   the current comment's start position
//  tokens                  the token list to add to
//  comments                the comment token list to add to
//  errors                  the error message list to use for reporting problems
//  raw_string_multiline    the current optional raw_string state
//

//  A stable place to store additional text for source tokens that are merged
//  into a whitespace-containing token (to merge the Cpp1 multi-token keywords)
//  -- this isn't about tokens generated later, that's tokens::generated_tokens
static auto generated_text  = std::deque<std::string>{};
static auto generated_lines = std::deque<std::vector<source_line>>{};


static auto multiline_raw_strings = std::deque<multiline_raw_string>{};

auto lex_line(
    std::string&               mutable_line,
    int const                  lineno,
    bool&                      in_comment,
    std::string&               current_comment,
    source_position&           current_comment_start,
    std::vector<token>&        tokens,
    std::vector<comment>&      comments,
    std::vector<error_entry>&  errors,
    std::optional<raw_string>& raw_string_multiline
)
    -> bool
{
    auto const& line = mutable_line;    // most accesses will be const, so give that the nice name

    auto original_size = std::ssize(tokens);

    auto i = colno_t{0};

    //  Token merging helpers
    //
    auto merge_cpp1_multi_token_fundamental_type_names = [&]
    {
        //  If the last token is a non-Cpp1MultiKeyword, we might be at the end
        //  of a sequence of Cpp1MultiKeyword tokens that need to be merged

        //  First, check the last token... only proceed if it is NOT one of those
        auto i = std::ssize(tokens)-1;
        if (
            i < 0
            || tokens[i].type() == lexeme::Cpp1MultiKeyword
            )
        {
            return;
        }

        //  Next, check the two tokens before that... only proceed if they ARE those
        --i;
        if (
            i < 1
            || tokens[i].type() != lexeme::Cpp1MultiKeyword
            || tokens[i-1].type() != lexeme::Cpp1MultiKeyword
            )
        {
            //  If this is just one such token, changed its type to regular ::Keyword
            if (
                i >= 0
                && tokens[i].type() == lexeme::Cpp1MultiKeyword
                )
            {
                tokens[i].set_type( lexeme::Keyword );
            }
            return;
        }

        //  OK, we have found the end of a sequence of 1 or more Cpp1MultiKeywords, so
        //  replace them with a single synthesized token that contains all their text
        //
        //  Note: It's intentional that this is a kind of token that can contain whitespace

        //  Remember the last (non-Cpp1MultiKeyword) token so we can put it back
        auto last_token = tokens.back();
        tokens.pop_back();

        assert(tokens.back().type() == lexeme::Cpp1MultiKeyword);
        auto pos = tokens.back().position();

        auto num_merged_tokens = 0;
        auto is_char           = 0;
        auto is_short          = 0;
        auto is_int            = 0;
        auto is_long           = 0;
        auto is_double         = 0;
        auto is_signed         = 0;
        auto is_unsigned       = 0;
        generated_text.push_back( "" );
        while(
            !tokens.empty()
            && tokens.back().type() == lexeme::Cpp1MultiKeyword
            )
        {
            auto text = tokens.back().to_string(true);
            if (text == "char"    ) { ++is_char    ; }
            if (text == "short"   ) { ++is_short   ; }
            if (text == "int"     ) { ++is_int     ; }
            if (text == "long"    ) { ++is_long    ; }
            if (text == "double"  ) { ++is_double  ; }
            if (text == "signed"  ) { ++is_signed  ; }
            if (text == "unsigned") { ++is_unsigned; }

            if (num_merged_tokens > 0) {
                generated_text.back() = " " + generated_text.back();
            }
            generated_text.back() = text + generated_text.back();
            pos = tokens.back().position();
            tokens.pop_back();
            ++num_merged_tokens;
        }

        tokens.push_back({
            &generated_text.back()[0],
            std::ssize(generated_text.back()),
            pos,
            lexeme::Keyword
            });

        if (num_merged_tokens > 1)
        {
            auto alt = std::string{};
            if      (is_char      &&  is_signed)   { alt = "'i8' (usually best) or 'cpp2::__schar'"; }
            else if (is_char      &&  is_unsigned) { alt = "'u8' (usually best) or 'cpp2::__uchar'"; }
            else if (is_short     && !is_unsigned) { alt = "'short'"      ; }
            else if (is_short     &&  is_unsigned) { alt = "'ushort'"     ; }
            else if (is_long == 1 && !is_unsigned) { alt = "'long'"       ; }
            else if (is_long == 1 &&  is_unsigned) { alt = "'ulong'"      ; }
            else if (is_long >  1 && !is_unsigned) { alt = "'longlong'"   ; }
            else if (is_long >  1 &&  is_unsigned) { alt = "'ulonglong'"  ; }
            else if (is_int       && !is_unsigned) { alt = "'int'"        ; }
            else if (is_int       &&  is_unsigned) { alt = "'uint'"       ; }
            else if (is_double    &&  is_long)     { alt = "'longdouble'" ; }

            if (std::ssize(alt) > 0) {
                errors.emplace_back(
                    pos,
                    "'" + tokens.back().to_string(true) + "' - did you mean " + alt + "?"
                );
            }
            errors.emplace_back(
                pos,
                "'" + tokens.back().to_string(true) + "' is an old-style C/C++ multi-word keyword type\n"
                "    - most such types should be used only for interoperability with older code\n"
                "    - using those when you need them is fine, but name them with these short names instead:\n"
                "        short, ushort, int, uint, long, ulong, longlong, ulonglong, longdouble, __schar, __uchar\n"
                "    - see also cpp2util.h > \"Convenience names for integer types\""
            );
        }

        tokens.push_back(last_token);
    };

    auto merge_operator_function_names = [&]
    {
        auto i = std::ssize(tokens)-1;

        //  If the third-to-last token is "operator", we may need to
        //  merge an "operator?" name into a single identifier token

        if (
            i >= 2
            && tokens[i-2] == "operator"
            )
        {
            //  If the tokens after "operator" are ">" and without whitespace one of ">=" ">" "="
            if (
                tokens[i-1].type() == lexeme::Greater
                && (tokens[i-1].position() == source_position{tokens[i].position().lineno, tokens[i].position().colno-1})
                && (tokens[i].type() == lexeme::GreaterEq || tokens[i].type() == lexeme::Greater || tokens[i].type() == lexeme::Assignment))
            {
                //  Merge all three tokens into an identifier
                generated_text.push_back( "operator" + tokens[i-1].to_string(true) + tokens[i].to_string(true) );
                tokens.pop_back();
                tokens.pop_back();
                auto pos = tokens.back().position();
                tokens.pop_back();
                tokens.push_back({
                    &generated_text.back()[0],
                    std::ssize(generated_text.back()),
                    pos,
                    lexeme::Identifier
                    });
            }

            //  Else if token after "operator" is a single-token operator symbol
            else if (is_operator(tokens[i-1].type()))
            {
                //  Merge just "operator" + the symbol into an identifier,
                generated_text.push_back( "operator" + tokens[i-1].to_string(true) );
                //  and preserve the last token separately
                auto last_token = tokens.back();

                tokens.pop_back();
                tokens.pop_back();
                auto pos = tokens.back().position();
                tokens.pop_back();
                tokens.push_back({
                    &generated_text.back()[0],
                    std::ssize(generated_text.back()),
                    pos,
                    lexeme::Identifier
                    });
                tokens.push_back(last_token);
            }

            //  Else if token after "operator" is a two-token operator symbol
            else if (
                (tokens[i-1].type() == lexeme::LeftParen && tokens[i].type() == lexeme::RightParen)
                || (tokens[i-1].type() == lexeme::LeftBracket && tokens[i].type() == lexeme::RightBracket)
                )
            {
                //  Merge just "operator" + the symbols into an identifier,
                generated_text.push_back( "operator" + tokens[i-1].to_string(true) + tokens[i].to_string(true) );

                tokens.pop_back();
                tokens.pop_back();
                auto pos = tokens.back().position();
                tokens.pop_back();
                tokens.push_back({
                    &generated_text.back()[0],
                    std::ssize(generated_text.back()),
                    pos,
                    lexeme::Identifier
                    });
            }

        }
    };


    //  Local helper functions for readability
    //
    auto peek = [&](int num) {
        return
            (i+num < std::ssize(line) && i+num >= 0)
            ? line[i+num]
            : '\0';
    };

    auto store = [&](auto num, lexeme type)
    {
        tokens.push_back({
            &line[i],
            num,
            source_position(lineno, i + 1),
            type
            });
        i += num-1;

        merge_cpp1_multi_token_fundamental_type_names();
        merge_operator_function_names();
    };


    //-----------------------------------------------------
    //  These functions return the length of sequence if
    //  present at the current location, else 0

    //G simple-escape-sequence:
    //G     '\' { any member of the basic character set except u, U, or x }
    //G
    auto peek_is_simple_escape_sequence = [&](int offset)
    {
        auto peek1 = peek(offset);
        auto peek2 = peek(1 + offset);
        if (
            peek1 == '\\'
            && peek2 != 'u'
            && peek2 != 'U'
            && peek2 != 'x'
            )
        {
            return 2;
        }
        return 0;
    };

    //G hexadecimal-escape-sequence:
    //G     '\x' hexadecimal-digit
    //G     hexadecimal-escape-sequence hexadecimal-digit
    //G
    auto peek_is_hexadecimal_escape_sequence = [&](int offset)
    {
        if (
            peek(  offset) == '\\'
            && peek(1+offset) == 'x'
            && is_hexadecimal_digit(peek(2+offset))
            )
        {
            auto j = 3;
            while (
                peek(j+offset)
                && is_hexadecimal_digit(peek(j+offset))
                )
            {
                ++j;
            }
            return j;
        }
        return 0;
    };

    //G universal-character-name:
    //G     '\u' hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit
    //G     '\U' hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit
    //G
    auto peek_is_universal_character_name = [&](colno_t offset)
    {
        if (
            peek(offset) == '\\'
            && peek(1 + offset) == 'u'
            )
        {
            auto j = 2;
            while (
                j <= 5
                && is_hexadecimal_digit(peek(j + offset))
                )
            {
                ++j;
            }
            if (j == 6) { return j; }
            errors.emplace_back(
                source_position( lineno, i + offset ),
                "invalid universal character name (\\u must"
                " be followed by 4 hexadecimal digits)"
            );
        }
        if (
            peek(offset) == '\\'
            && peek(1+offset) == 'U'
            )
        {
            auto j = 2;
            while (
                j <= 9
                && is_hexadecimal_digit(peek(j+offset))
                )
            {
                ++j;
            }
            if (j == 10) { return j; }
            errors.emplace_back(
                source_position(lineno, i+offset),
                "invalid universal character name (\\U must"
                    " be followed by 8 hexadecimal digits)"
            );
        }
        return 0;
    };

    //G escape-sequence:
    //G     hexadecimal-escape-sequence
    //G     simple-escape-sequence
    //G
    auto peek_is_escape_sequence = [&](int offset)
    {
        if (auto h = peek_is_hexadecimal_escape_sequence(offset)) { return h; }
        return peek_is_simple_escape_sequence(offset);
    };

    //G s-char:
    //G     universal-character-name
    //G     escape-sequence
    //G     basic-s-char
    //G
    //G basic-s-char:
    //G     any member of the basic source character set except '"' '\' or new-line
    //G
    //G c-char:
    //G     universal-character-name
    //G     escape-sequence
    //G     basic-c-char
    //G
    //G basic-c-char:
    //G     any member of the basic source character set except ''' '\' or new-line
    //G
    auto peek_is_sc_char = [&](int offset, char quote)
    {
        if (auto u = peek_is_universal_character_name(offset)) {
            return u;
        }
        if (auto e = peek_is_escape_sequence(offset)) {
            return e;
        }
        if (
            peek(offset)
            && peek(offset) != quote
            && peek(offset) != '\\'
            )
        {
            return 1;
        }
        return 0;
    };

    //G keyword:
    //G     any Cpp1-and-Cpp2 keyword
    //G     one of: 'import' 'module' 'export' 'is' 'as'
    //G
    auto do_is_keyword = [&](std::vector<std::string_view> const& r) {
        auto remaining_line = std::string_view(line).substr(unsafe_narrow<std::size_t>(i));
        auto m = std::find_if(r.begin(), r.end(), [&](std::string_view s) {
            return remaining_line.starts_with(s);
        });
        if (m != r.end()) {
            //  If we matched and what's next is EOL or a non-identifier char, we matched!
            if (
                i+std::ssize(*m) == std::ssize(line)                                            // EOL
                || !is_identifier_continue(line[unsafe_narrow<std::size_t>(i)+std::size(*m)])   // non-identifier char
                )
            {
                return static_cast<int>(std::ssize(*m));
            }
        }
        return 0;
    };

    auto peek_is_keyword = [&]
    {
        //  Cpp2 has a smaller set of the Cpp1 globally reserved keywords, but we continue to
        //  reserve all the ones Cpp1 has both for compatibility and to not give up a keyword
        //  Some keywords like "delete" and "union" are not in this list because we reject them elsewhere
        //  Cpp2 also adds a couple, notably "is" and "as"
        static const auto keys = std::vector<std::string_view>{
            "alignas", "alignof", "asm", "as", "auto",
            "bool", "break",
            "case", "catch", "char16_t", "char32_t", "char8_t", "char", "co_await", "co_return",
            "co_yield", "concept", "const_cast", "consteval", "constexpr", "constinit", "const", "continue",
            "decltype", "default", "double", "do", "dynamic_cast",
            "else", "enum", "explicit", "export", "extern",
            "float", "for", "friend",
            "goto",
            "if", "import", "inline", "int", "is",
            "long",
            "module", "mutable",
            "namespace", "noexcept",
            "operator",
            "private", "protected", "public",
            "register", "reinterpret_cast", "requires", "return",
            "short", "signed", "sizeof", "static_assert", "static_cast", "static", "switch",
            "template", "this", "thread_local", "throws", "throw", "try", "typedef", "typeid", "typename",
            "unsigned", "using",
            "virtual", "void", "volatile",
            "wchar_t", "while"
        };

        return do_is_keyword(keys);
    };

    auto peek_is_cpp2_fundamental_type_keyword = [&]
    {
        static const auto keys = std::vector<std::string_view>{
            "i8", "i16", "i32", "i64", "longdouble", "longlong", "u8", "u16", "u32", "u64", "ulong", "ulonglong", "ushort"
        };

        return do_is_keyword(keys);
    };

    auto peek_is_cpp1_multi_token_fundamental_keyword = [&]
    {
        static const auto multi_keys = std::vector<std::string_view>{
            "char16_t", "char32_t", "char8_t", "char", "double", "float", "int", "long", "short", "signed", "unsigned"
        };
        return do_is_keyword(multi_keys);
    };

    auto reset_processing_of_the_line = [&]() {
        //  Redo processing of this whole line now that the string is expanded,
        //  which may have moved it in memory... move i back to the line start
        //  and _ = any tokens we already tokenized for this line
        i = colno_t{-1};
        while (
            !tokens.empty()
            && tokens.back().position().lineno == lineno
            )
        {
            tokens.pop_back();
        }
    };

    auto interpolate_raw_string = [&](
        const std::string& opening_seq,
        const std::string& closing_seq,
        string_parts::adds_sequences closing_strategy,
        std::string_view part, 
        int pos_to_replace, 
        int size_to_replace
    ) -> bool {
        auto parts = expand_raw_string_literal(opening_seq, closing_seq, closing_strategy, part, errors, source_position(lineno, pos_to_replace + 1));
        auto new_part = parts.generate();
        mutable_line.replace( pos_to_replace, size_to_replace, new_part );
        i += std::ssize(new_part)-1;

        if (parts.is_expanded()) {
            // raw string was expanded and we need to repeat the processing of this line
            reset_processing_of_the_line();

            // but skipping end of potential multiline raw string that ends on this line
            if (!multiline_raw_strings.empty() && multiline_raw_strings.back().end.lineno == lineno) {
                i = multiline_raw_strings.back().end.colno;
                raw_string_multiline.reset();
            } else if (raw_string_multiline && raw_string_multiline->start.lineno == lineno) {
                raw_string_multiline.reset();
            }
            return true;
        }
        return false;
    };

    //
    //-----------------------------------------------------

    for ( ; i < ssize(line); ++i)
    {
        auto peek1 = peek(1);
        auto peek2 = peek(2);
        auto peek3 = peek(3);

        //G encoding-prefix: one of
        //G     'u8' 'u' 'uR' 'u8R' 'U' 'UR' 'L' 'LR' 'R' 
        //G
        auto is_encoding_prefix_and = [&](char next) {
            if (line[i] == next)                                        { return 1; } // "
            else if (line[i] == 'u') {
                if (peek1 == next)                                      { return 2; } // u"
                else if (peek1 == '8' && peek2 == next)                 { return 3; } // u8"
                else if (peek1 == 'R' && peek2 == next)                 { return 3; } // uR"
                else if (peek1 == '8' && peek2 == 'R' && peek3 == next) { return 4; } // u8R"
            } 
            else if (line[i] == 'U') { 
                if ( peek1 == next)                                     { return 2; } // U"
                else if (peek1 == 'R' && peek2 == next)                 { return 3; } // UR"
            } 
            else if (line[i] == 'L') { 
                if ( peek1 == next )                                    { return 2; } // L"
                else if (peek1 == 'R' && peek2 == next)                 { return 3; } // LR" 
            } 
            else if (line[i] == 'R' && peek1 == next)                   { return 2; } // R"
            return 0;
        };

        //  If we're currently in a multiline comment,
        //  the only thing to look for is the */ comment end
        //
        if (in_comment) {
            switch (line[i]) {
            //  */ comment end
            break;case '*':
                if (peek1 == '/') {
                    current_comment += "*/";
                    comments.push_back({
                        comment::comment_kind::stream_comment,
                        current_comment_start,
                        source_position(lineno, i + 2),
                        current_comment
                        });
                    in_comment = false;
                    ++i;
                }
            break;default:
                current_comment += line[i];
            }
        }
        else if (raw_string_multiline) {
            auto end_pos = line.find(raw_string_multiline.value().closing_seq, i);
            auto part = line.substr(i, end_pos-i);

            if (const auto& rsm = raw_string_multiline.value(); rsm.should_interpolate) {
                
                auto closing_strategy = end_pos == line.npos ? string_parts::no_ends : string_parts::on_the_end;
                auto size_to_replace  = end_pos == line.npos ? std::ssize(line) - i  : end_pos - i + std::ssize(rsm.closing_seq);

                if (interpolate_raw_string(rsm.opening_seq, rsm.closing_seq, closing_strategy, part, i, size_to_replace ) ) {
                    continue;
                }
            }
            // raw string was not expanded

            raw_string_multiline.value().text += part;
            if (end_pos == std::string::npos) {
                raw_string_multiline.value().text += '\n';
                break;
            }

            // here we know that we are dealing with finalized multiline raw string literal
            // token needs to use multiline_raw_strings to store string that exists in multiple lines
            raw_string_multiline.value().text += raw_string_multiline.value().closing_seq;

            // and position where multiline_raw_string ends (needed for reseting line parsing)
            i = end_pos+std::ssize(raw_string_multiline.value().closing_seq)-1;

            const auto& text = raw_string_multiline.value().should_interpolate ? raw_string_multiline.value().text.substr(1) : raw_string_multiline.value().text;
            multiline_raw_strings.emplace_back(multiline_raw_string{ text, {lineno, i} });

            tokens.push_back({
                &multiline_raw_strings.back().text[0],
                std::ssize(multiline_raw_strings.back().text),
                raw_string_multiline.value().start,
                lexeme::StringLiteral
            });
            raw_string_multiline.reset();
            continue;
        }

        //  Otherwise, we will be at the start of a token, a comment, or whitespace
        //
        else {
            //G token:
            //G     identifier
            //G     keyword
            //G     literal
            //G     operator-or-punctuator
            //G
            //G operator-or-punctuator:
            //G     operator
            //G     punctuator
            //G
            //G operator: one of

            switch (line[i]) {

            //  .* ->* ? aren't currently used in Cpp2, and aren't needed

            //  (we do need all the overloadable operators for Cpp1 compat,
            //  even if we may not keep their meanings for built-in types)

            //      /* and // comment starts
            //G     '/=' '/'
            break;case '/':
                if (peek1 == '*') {
                    current_comment = "/*";
                    current_comment_start = source_position(lineno, i+1);
                    in_comment = true;
                    ++i;
                }
                else if (peek1 == '/') {
                    comments.push_back({
                        comment::comment_kind::line_comment,
                        {lineno, i},
                        {lineno, __as<colno_t>(std::ssize(line))},
                        std::string(&line[i], std::ssize(line) - i)
                        });
                    in_comment = false;
                    goto END;
                }
                else if (peek1 == '=') {
                    store(2, lexeme::SlashEq);
                }
                else {
                    store(1, lexeme::Slash);
                }

            //G     '<<=' '<<' '<=>' '<=' '<'
            break;case '<':
                if (peek1 == '<') {
                    if (peek2 == '=') { store(3, lexeme::LeftShiftEq); }
                    else { store(2, lexeme::LeftShift); }
                }
                else if (peek1 == '=') {
                    if (peek2 == '>') { store(3, lexeme::Spaceship); }
                    else { store(2, lexeme::LessEq); }
                }
                else { store(1, lexeme::Less); }

            //  Note: >> and >>= are not source tokens, they are synthesized from > > and > >= where legal
            //G     '>>=' '>>' '>=' '>'
            break;case '>':
                //---------------------------------------------------------
                //  Do not uncomment, see above Note
                //
                //if (peek1 == '>') {
                //    if (peek2 == '=') { store(3, lexeme::RightShiftEq); }
                //    else { store(2, lexeme::RightShift); }
                //}
                //else
                //---------------------------------------------------------
                if (peek1 == '=') { store(2, lexeme::GreaterEq); }
                else { store(1, lexeme::Greater); }

            //G     '++' '+=' '+'
            break;case '+':
                if (peek1 == '+') { store(2, lexeme::PlusPlus); }
                else if (peek1 == '=') { store(2, lexeme::PlusEq); }
                else { store(1, lexeme::Plus); }

            //G     '--' '-=' '->' '-'
            break;case '-':
                if (peek1 == '-') { store(2, lexeme::MinusMinus); }
                else if (peek1 == '=') { store(2, lexeme::MinusEq); }
                else if (peek1 == '>') { store(2, lexeme::Arrow); }
                else { store(1, lexeme::Minus); }

            //G     '||=' '||' '|=' '|'
            break;case '|':
                if (peek1 == '|') {
                    if (peek2 == '=') { store(3, lexeme::LogicalOrEq); }
                    else { store(2, lexeme::LogicalOr); }
                }
                else if (peek1 == '=') { store(2, lexeme::PipeEq); }
                else { store(1, lexeme::Pipe); }

            //G     '&&=' '&&' '&=' '&'
            break;case '&':
                if (peek1 == '&') {
                    if (peek2 == '=') { store(3, lexeme::LogicalAndEq); }
                    else { store(2, lexeme::LogicalAnd); }
                }
                else if (peek1 == '=') { store(2, lexeme::AmpersandEq); }
                else { store(1, lexeme::Ampersand); }

            //  Next, all the other operators that have a compound assignment form

            //G     '*=' '*'
            break;case '*':
                if (peek1 == '=') { store(2, lexeme::MultiplyEq); }
                else { store(1, lexeme::Multiply); }

            //G     '%=' '%'
            break;case '%':
                if (peek1 == '=') { store(2, lexeme::ModuloEq); }
                else { store(1, lexeme::Modulo); }

            //G     '^=' '^'
            break;case '^':
                if (peek1 == '=') { store(2, lexeme::CaretEq); }
                else { store(1, lexeme::Caret); }

            //G     '~=' '~'
            break;case '~':
                if (peek1 == '=') { store(2, lexeme::TildeEq); }
                else { store(1, lexeme::Tilde); }

            //G     '==' '='
            break;case '=':
                if (peek1 == '=') { store(2, lexeme::EqualComparison); }
                else { store(1, lexeme::Assignment); }

            //G     '!=' '!'
            break;case '!':
                if (peek1 == '=') { store(2, lexeme::NotEqualComparison); }
                else { store(1, lexeme::Not); }

            //G
            //G punctuator: one of
            //G     '...' '.'
            break;case '.':
                if (peek1 == '.' && peek2 == '.') { store(3, lexeme::Ellipsis); }
                else { store(1, lexeme::Dot); }

            //G     '::' ':'
            break;case ':':
                if (peek1 == ':') { store(2, lexeme::Scope); }
                else { store(1, lexeme::Colon); }

            //  All the other single-character tokens

            //G     '{' '}' '(' ')' '[' ']' ';' ',' '?' '$'
            //G

            break;case '{':
                store(1, lexeme::LeftBrace);

            break;case '}':
                store(1, lexeme::RightBrace);

            break;case '(':
                store(1, lexeme::LeftParen);

            break;case ')':
                store(1, lexeme::RightParen);

            break;case '[':
                store(1, lexeme::LeftBracket);

            break;case ']':
                store(1, lexeme::RightBracket);

            break;case ';':
                store(1, lexeme::Semicolon);

            break;case ',':
                store(1, lexeme::Comma);

            break; case '?':
                store(1, lexeme::QuestionMark);

            break; case '@':
                store(1, lexeme::At);

            break;case '$':
                if (peek1 == 'R' && peek2 == '"') {
                    // if peek(j-2) is 'R' it means that we deal with raw-string literal
                    auto R_pos = i + 1;
                    auto seq_pos = i + 3;
                        
                    if (auto paren_pos = line.find("(", seq_pos); paren_pos != std::string::npos) {
                        auto opening_seq = line.substr(i, paren_pos - i + 1);
                        auto closing_seq = ")"+line.substr(seq_pos, paren_pos-seq_pos)+"\"";

                        if (auto closing_pos = line.find(closing_seq, paren_pos+1); closing_pos != line.npos) {
                            if (interpolate_raw_string(
                                    opening_seq,
                                    closing_seq,
                                    string_parts::on_both_ends,
                                    std::string_view(&line[paren_pos+1], closing_pos-paren_pos-1), i, closing_pos-i+std::ssize(closing_seq))
                            ) {
                                continue;
                            }

                            tokens.push_back({
                                                &line[R_pos],
                                                i - R_pos + 1,
                                                source_position(lineno, R_pos + 1),
                                                lexeme::StringLiteral
                                            });
                        } else {
                            raw_string_multiline.emplace(raw_string{source_position{lineno, i}, opening_seq, opening_seq, closing_seq, true });

                            if (interpolate_raw_string(
                                    opening_seq,
                                    closing_seq,
                                    string_parts::on_the_beginning,
                                    std::string_view(&line[paren_pos+1], std::ssize(line)-(paren_pos+1)), i, std::ssize(line)-i)
                            ) {
                                continue;
                            }
                            // skip entire raw string opening sequence R"
                            i = paren_pos;

                            // if we are on the end of the line we need to add new line char
                            if (i+1 == std::ssize(line)) {
                                raw_string_multiline.value().text += '\n';
                            }
                        }
                        continue;
                    }
                    else {
                        errors.emplace_back(
                            source_position(lineno, i + 1),
                            "invalid new-line in raw string delimiter \"" + std::string(&line[i],3)
                                + "\" - stray 'R' in program \""
                        );
                    }
                } else {
                    store(1, lexeme::Dollar);
                }

            //G
            //G literal:
            //G     integer-literal
            //G     character-literal
            //G     floating-point-literal
            //G     string-literal
            //GTODO     boolean-literal
            //GTODO     pointer-literal
            //G
            //G integer-literal:
            //G     binary-literal
            //G     hexadecimal-literal
            //G     decimal-literal
            //G
            //G binary-literal:
            //G     '0b' binary-digit
            //G     '0B' binary-digit
            //G     binary-literal binary-digit
            //G     binary-literal ''' binary-digit
            //G
            //G hexadecimal-literal:
            //G     '0x' hexadecimal-digit
            //G     '0X' hexadecimal-digit
            //G     hexadecimal-literal hexadecimal-digit
            //G     hexadecimal-literal ''' hexadecimal-digit
            //G
            break;case '0': {
                auto j = 3;
                if (peek1 == 'b' || peek1 == 'B') {
                    if (is_binary_digit(peek2)) {
                        while (is_separator_or(is_binary_digit,peek(j))) { ++j; }
                        store(j, lexeme::BinaryLiteral);
                        continue;
                    }
                    else {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "binary literal cannot be empty (0B must be followed by binary digits)"
                        );
                        ++i;
                    }
                }
                else if (peek1 == 'x' || peek1 == 'X') {
                    if (is_hexadecimal_digit(peek2)) {
                        while (is_separator_or(is_hexadecimal_digit,peek(j))) { ++j; }
                        store(j, lexeme::HexadecimalLiteral);
                        continue;
                    }
                    else {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "hexadecimal literal cannot be empty (0X must be followed by hexadecimal digits)"
                        );
                        ++i;
                    }
                }
            }
            [[fallthrough]];

            // NO BREAK: we want 0 to fall through to numeric literal case
            // (this will be less kludgy to write with pattern matching)
            default:

                if (
                    line[i] == 'n'
                    && peek1 == 'o'
                    && peek2 == 't'
                    && isspace(peek3)
                    )
                {
                    store(3, lexeme::Not);
                }

                //G
                //G decimal-literal:
                //G     digit [uU][lL][lL]
                //G     decimal-literal digit [uU][lL][lL]
                //G     decimal-literal ''' digit [uU][lL][lL]
                //G
                //G floating-point-literal:
                //G     digit { ' | digit }* . digit ({ ' | digit }*)? ([eE][-+]?digit { ' | digit }*) [fFlL]
                //G
                //G TODO full grammar & refactor to utility functions with their
                //G      own unit test rather than inline everything here
                //G
                else if (is_digit(line[i])) {
                    auto j = 1;
                    while (is_separator_or(is_digit,peek(j))) { ++j; }
                    if (
                        (peek(j) != '.' || !is_digit(peek(j+1)))
                        && peek(j) != 'f'
                        && peek(j) != 'F'
                        && peek(j) != 'e'
                        && peek(j) != 'E'
                        )
                    {
                        // cf: https://en.cppreference.com/w/cpp/language/integer_literal
                        //
                        // TODO: This dumbly slurps the suffixs
                        // ull/ULL. Suffix parsing should move to a utility
                        // and be error checked. Best would be to slurp all
                        // [a-zA-Z] and then validate against a list of
                        // allowed suffixes. Ideally handle the C++23 size
                        // suffixes as well.
                        if (peek(j) == 'u' || peek(j) == 'U') { ++j; }
                        if (peek(j) == 'l' || peek(j) == 'L') { ++j; }
                        if (peek(j) == 'l' || peek(j) == 'L') { ++j; }
                        store(j, lexeme::DecimalLiteral);
                    }
                    else {
                        // cf: https://en.cppreference.com/w/cpp/language/floating_literal

                        // slurps the digits after '.'
                        if (peek(j) == '.') {
                            ++j;
                            if (!is_digit(peek(j))) {
                                errors.emplace_back(
                                    source_position(lineno, i),
                                    "a floating point literal must have at least one digit after the decimal point (can be '.0')"
                                );
                            }
                            while (is_separator_or(is_digit,peek(j))) {
                                ++j;
                            }
                        }

                        // slurp the exponential form marker
                        if (peek(j) == 'e' || peek(j) == 'E') {
                            ++j;
                            if (peek(j) == '-' || peek(j) == '+') { ++j; }
                            while (is_separator_or(is_digit,peek(j))) { ++j; }
                        }

                        // TODO: This dumbly slurps the suffixes fF or
                        // lL. Suffix parsing should move to a utility and be
                        // error checked. Best would be to slurp all [a-zA-Z]
                        // and then validate against a list of allowed
                        // suffixes. Ideally handle the C++23 suffixes aswell.
                        if      (peek(j) == 'f' || peek(j) == 'F') { ++j; }
                        else if (peek(j) == 'l' || peek(j) == 'L') { ++j; }
                        store(j, lexeme::FloatLiteral);
                    }
                }

                //G string-literal:
                //G     encoding-prefix? '"' s-char-seq? '"'
                //G     encoding-prefix? 'R"' d-char-seq? '(' s-char-seq? ')' d-char-seq? '"'
                //G
                //G s-char-seq:
                //G     interpolation? s-char
                //G     interpolation? s-char-seq s-char
                //G
                //G d-char-seq:
                //G     d-char
                //G
                //G interpolation:
                //G     '(' expression ')' '$'
                //G
                else if (auto j = is_encoding_prefix_and('\"')) {
                    // if peek(j-2) is 'R' it means that we deal with raw-string literal
                    if (peek(j-2) == 'R') { 
                        auto seq_pos = i + j;
                            
                        if (auto paren_pos = line.find("(", seq_pos); paren_pos != std::string::npos) {
                            auto opening_seq = line.substr(i, paren_pos - i + 1);
                            auto closing_seq = ")"+line.substr(seq_pos, paren_pos-seq_pos)+"\"";

                            if (auto closing_pos = line.find(closing_seq, paren_pos+1); closing_pos != line.npos) {
                                store(closing_pos+std::ssize(closing_seq)-i, lexeme::StringLiteral);
                            } else {
                                raw_string_multiline.emplace(raw_string{source_position{lineno, i}, opening_seq, opening_seq, closing_seq });
                                // skip entire raw string opening sequence R"
                                i = paren_pos;

                                // if we are on the end of the line we need to add new line char
                                if (i+1 == std::ssize(line)) {
                                    raw_string_multiline.value().text += '\n';
                                }
                            }
                            continue;
                        }
                        else {
                            errors.emplace_back(
                                source_position(lineno, i + j - 2),
                                "invalid new-line in raw string delimiter \"" + std::string(&line[i],j)
                                    + "\" - stray 'R' in program \""
                            );
                        }
                    }
                    else {
                        while (auto len = peek_is_sc_char(j, '\"')) { j += len; }
                        if (peek(j) != '\"') {
                            errors.emplace_back(
                                source_position(lineno, i),
                                "string literal \"" + std::string(&line[i+1],j)
                                    + "\" is missing its closing \""
                            );
                        }

                        //  At this point we have a string-literal, but it may contain
                        //  captures/interpolations we want to tokenize
                        auto literal = std::string_view{ &line[i], std::size_t(j+1) };
                        auto s = expand_string_literal( literal, errors, source_position(lineno, i + 1) );

                        //  If there are no captures/interpolations, just store it directly and continue
                        if (std::ssize(s) == j+1) {
                            store(j+1, lexeme::StringLiteral);
                        }
                        //  Otherwise, replace it with the expanded version and continue
                        else {
                            if (std::ssize(s) <= j + 1) {
                                errors.emplace_back(
                                    source_position( lineno, i ),
                                    "not a legal string literal",
                                    false,
                                    true    // a noisy fallback error message
                                );
                                return {};
                            }
                            mutable_line.replace( i, j+1, s );

                            reset_processing_of_the_line();
                        }
                    }
                }

                //G character-literal:
                //G     encoding-prefix? ''' c-char-seq? '''
                //G
                //G c-char-seq:
                //G     c-char
                //G     c-char-seq c-char
                //G
                else if (auto j = is_encoding_prefix_and('\'')) {
                    auto len = peek_is_sc_char(j, '\'');
                    if (len > 0) {
                        j += len;
                        if (peek(j) != '\'') {
                            errors.emplace_back(
                                source_position(lineno, i),
                                "character literal '" + std::string(&line[i+1],j)
                                    + "' is missing its closing '"
                            );
                        }
                        store(j+1, lexeme::CharacterLiteral);
                    }
                    else {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "character literal is empty"
                        );
                    }
                }

                //  Cpp1 multi-token fundamental type keyword
                //
                else if (auto j = peek_is_cpp1_multi_token_fundamental_keyword()) {
                    store(j, lexeme::Cpp1MultiKeyword);
                }

                //  Cpp2 fixed-width type alias keyword
                //
                else if (auto j = peek_is_cpp2_fundamental_type_keyword()) {
                    store(j, lexeme::Cpp2FixedType);
                }

                //  Other keyword
                //
                else if (auto j = peek_is_keyword()) {
                    store(j, lexeme::Keyword);

                    if (tokens.back() == "const_cast") {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "'const_cast' is not supported in Cpp2 - the current C++ best practice is to never cast away const, and that is const_cast's only effective use"
                        );
                    }
                    if (tokens.back() == "reinterpret_cast") {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "'reinterpret_cast' is not supported in Cpp2 - use std::bit_cast instead"
                        );
                    }
                    if (tokens.back() == "static_cast") {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "'static_cast<T>(val)' is not supported in Cpp2 - use 'val as T' for safe conversions instead, or if necessary cpp2::unsafe_narrow<T>(val) for a possibly-lossy narrowing conversion"
                        );
                    }
                    if (tokens.back() == "dynamic_cast") {
                        errors.emplace_back(
                            source_position(lineno, i),
                            "'dynamic_cast<Derived*>(pBase)' is not supported in Cpp2 - use 'pBase as *Derived' for safe dynamic conversions instead"
                        );
                    }
                }

                //  Identifier
                //
                else if (auto j = starts_with_identifier({&line[i], std::size(line)-i}))
                {
                    if (
                        !isspace(peek(-1))
                        && !tokens.empty()
                        && is_literal(tokens.back().type())
                        )
                    {
                        store(j, lexeme::UserDefinedLiteralSuffix);
                    }
                    else
                    {
                        store(j, lexeme::Identifier);
                        if (tokens.back() == "NULL") {
                            errors.emplace_back(
                                source_position(lineno, i),
                                "'NULL' is not supported in Cpp2 - for a local pointer variable, leave it uninitialized instead, and set it to a non-null value when you have one"
                            );
                        }
                        if (tokens.back() == "delete") {
                            errors.emplace_back(
                                source_position(lineno, i),
                                "'delete' and owning raw pointers are not supported in Cpp2 - use unique.new<T> or shared.new<T> instead in that order (or, in the future, gc.new<T>, but that is not yet implemented)"
                            );
                        }
                    }
                }

                //  Anything else should be whitespace
                //
                else if (!isspace(line[i])) {
                    errors.emplace_back(
                        source_position(lineno, i),
                        std::string("unexpected text '") + line[i] + "'",
                        false,
                        true    // a noisy fallback error message
                    );
                }
            }
        }
    }

END:
    if (in_comment) {
        current_comment += "\n";
    }
    if (raw_string_multiline && line.size() == 0) {
        raw_string_multiline.value().text += '\n';
    }

    assert (std::ssize(tokens) >= original_size);
    return std::ssize(tokens) != original_size;
}


//-----------------------------------------------------------------------
//
//  tokens: a map of the tokens of a source file
//
//-----------------------------------------------------------------------
//

class tokens
{
    std::vector<error_entry>& errors;

    //  All non-comment source tokens go here, which will be parsed in the parser
    std::map<lineno_t, std::vector<token>> grammar_map;

    //  All comment source tokens go here, which are applied in the lexer
    //
    //  We could put all the tokens in the same map, but that would mean the
    //  parsing logic would have to remember to skip comments everywhere...
    //  simpler to keep comments separate, at the smaller cost of traversing
    //  a second token stream when lowering to Cpp1 to re-interleave comments
    std::vector<comment> comments;

    //  A stable place to store additional tokens that are synthesized later
    std::deque<token> generated_tokens;

public:
    //-----------------------------------------------------------------------
    //  Constructor
    //
    //  errors      error list
    //
    tokens(
        std::vector<error_entry>& errors_
    )
        : errors{ errors_ }
    {
    }


    //-----------------------------------------------------------------------
    //  lex: Tokenize the Cpp2 lines
    //
    //  lines           tagged source lines
    //  is_generated    is this generated code
    //
    auto lex(
        std::vector<source_line>& lines,
        bool                      is_generated = false
    )
        -> void
    {
        auto in_comment           = false;
        auto raw_string_multiline = std::optional<raw_string>();

        assert (std::ssize(lines) > 0);
        auto line = std::begin(lines);
        while (line != std::end(lines)) {

            //  Skip over non-Cpp2 lines
            if (line->cat != source_line::category::cpp2) {
                ++line;
                continue;
            }

            //  At this point, we're at the first line of a Cpp2 code section

            //  Create new map entry for the section starting at this line,
            //  and populate its tokens with the tokens in this section
            auto lineno = std::distance(std::begin(lines), line);

            //  If this is generated code, use negative line numbers to
            //  inform and assist the printer
            if (is_generated) {
                lineno -= 10'000;
            }

            auto& entry = grammar_map[lineno];
            auto current_comment = std::string{};
            auto current_comment_start = source_position{};

            for (
                ;
                line != std::end(lines) && line->cat == source_line::category::cpp2;
                ++line, ++lineno
                )
            {
                lex_line(
                    line->text, lineno,
                    in_comment, current_comment, current_comment_start,
                    entry, comments, errors,
                    raw_string_multiline
                );

                //  Check whether all the tokens on this line were consecutive
                //  w/o extra whitespace (separated by 0 or 1 whitespace chars)
                if (!entry.empty()) {
                    for (auto i = std::ssize(entry) - 1;
                        i > 0;
                        --i
                        )
                    {
                        if (entry[i-1].position().lineno != lineno) {
                            break;
                        }

                        if (
                            entry[i].position().lineno == lineno
                            && entry[i-1].position().colno + entry[i-1].length() + 1
                                < entry[i].position().colno
                            )
                        {
                            line->all_tokens_are_densely_spaced = false;
                            break;
                        }
                    }
                }
            }
        }
    }


    //-----------------------------------------------------------------------
    //  get_map: Access the token map
    //
    auto get_map() const
        -> auto const&
    {
        return grammar_map;
    }


    //-----------------------------------------------------------------------
    //  get_comments: Access the comment list
    //
    auto get_comments() const
        -> auto const&
    {
        return comments;
    }


    //-----------------------------------------------------------------------
    //  get_generated: Access the generated tokens
    //
    auto get_generated()
        -> auto&
    {
        return generated_tokens;
    }


    //-----------------------------------------------------------------------
    //  num_unprinted_comments: The number of not-yet-printed comments
    //
    auto num_unprinted_comments()
        -> int
    {
        auto ret = 0;
        for (auto const& c : comments) {
            if (!c.dbg_was_printed) {
                ++ret;
            }
        }
        return ret;
    }

    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print(std::ostream& o) const
        -> void
    {
        for (auto const& [lineno, entry] : grammar_map) {

            o << "--- Section starting at line " << lineno << "\n";
            for (auto const& token : entry) {
                o << "    " << token << " (" << token.position().lineno
                    << "," << token.position().colno << ") "
                    << __as<std::string>(token.type()) << "\n";
            }

        }

        o << "--- Comments\n";
        for (auto const& [kind, start, end, text, dbg_ignore] : comments) {
            o << "    "
              << (kind == comment::comment_kind::line_comment ? "// " : "/* ")
              << "(" << start.lineno << "," << start.colno << ")"
              << "-(" << end.lineno << "," << end.colno << ")"
              << " " << text << "\n";
        }

        o << "--- Generated tokens\n";
        for (auto const& token : generated_tokens) {
            o << "    " << token << " (" << token.position().lineno
                << "," << token.position().colno << ") "
                << __as<std::string>(token.type()) << "\n";
        }

        o << "--- Generated text\n";
        for (auto const& s : generated_text) {
            o << "    " << s << "\n";
        }

    }

};

static auto generated_lexers = std::deque<tokens>{};

}

#endif

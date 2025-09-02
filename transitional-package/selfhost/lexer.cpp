lexer.cpp2... ok (mixed Cpp1/Cpp2, Cpp2 code passes safety checks)

emory>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "lexer.cpp2"

#line 23 "lexer.cpp2"
class token;
    

#line 91 "lexer.cpp2"
class lexer;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "lexer.cpp2"
// lexer.cpp2
// SIMD-optimized lexer with wide scanning capabilities

#line 7 "lexer.cpp2"

// Token types
@enum: type = {
    identifier,
    number,
    string_literal,
    char_literal,
    keyword,
    operator_,
    delimiter,
    whitespace,
    comment,
    eof
}

// Token structure
#line 23 "lexer.cpp2"
class token {
    private: cpp2_enum type {}; 
    private: std::string text {""}; 
    private: int line {0}; 
    private: int column {0}; 
    public: [[nodiscard]] auto operator<=>(token const& that) const& -> std::strong_ordering = default;
public: token(token const& that);

public: auto operator=(token const& that) -> token& ;
public: token(token&& that) noexcept;
public: auto operator=(token&& that) noexcept -> token& ;
public: explicit token();

#line 28 "lexer.cpp2"
};

// SIMD-optimized wide scanner
@wide_scanner: type = {
    // Vector width for SIMD operations
    vector_width: int = 4;
    
    // SIMD-accelerated character classification
    is_whitespace_simd: (data: std::vector<char> const&) -> std::vector<bool> = {
        result: std::vector<bool> = std::vector<bool>(data.size(), false);
        
        // Process in chunks for SIMD optimization
        chunk_size: int = vector_width * 4;
        
        for i: int = 0; i < data.size(); i += chunk_size {
            end: int = std::min(i + chunk_size, data.size());
            
            // This loop can be auto-vectorized by the compiler
            #pragma clang loop vectorize(enable)
            for j: int = i; j < end; ++j {
                c: char = data[j];
                result[j] = (c == ' ' || c == '\t' || c == '\n' || c == '\r');
            }
        }
        
        return result;
    }
    
    // SIMD-accelerated boundary detection
    find_boundaries_simd: (data: std::vector<char> const&, boundaries: std::vector<char> const&) -> std::vector<int> = {
        result: std::vector<int> = ();
        
        // Process in chunks for SIMD optimization
        chunk_size: int = vector_width * 4;
        
        for i: int = 0; i < data.size(); i += chunk_size {
            end: int = std::min(i + chunk_size, data.size());
            
            // This loop can be auto-vectorized by the compiler
            #pragma clang loop vectorize(enable)
            for j: int = i; j < end; ++j {
                c: char = data[j];
                is_boundary: bool = false;
                
                // Check if character is a boundary
                for boundary: char in boundaries {
                    if c == boundary {
                        is_boundary = true;
                        break;
                    }
                }
                
                if is_boundary {
                    result.push_back(j);
                }
            }
        }
        
        return result;
    }
}

// Lexer class
class lexer {
    private: std::string source {""}; 
    private: int position {0}; 
    private: int line {1}; 
    private: int column {1}; 

    private: wide_scanner scanner {}; 

    // Get next token
    public: [[nodiscard]] auto next_token() const& -> token;

#line 126 "lexer.cpp2"
    // Skip whitespace characters
    public: auto skip_whitespace() const& -> void;

#line 139 "lexer.cpp2"
    // Scan identifier or keyword
    public: [[nodiscard]] auto scan_identifier() const& -> token;

#line 160 "lexer.cpp2"
    // Scan number literal
    public: [[nodiscard]] auto scan_number() const& -> token;

#line 187 "lexer.cpp2"
    // Scan string literal
    public: [[nodiscard]] auto scan_string_literal() const& -> token;

#line 220 "lexer.cpp2"
    // Scan character literal
    public: [[nodiscard]] auto scan_char_literal() const& -> token;

#line 248 "lexer.cpp2"
    // Scan operator or delimiter
    public: [[nodiscard]] auto scan_operator_or_delimiter() const& -> token;
    public: [[nodiscard]] auto operator<=>(lexer const& that) const& -> std::strong_ordering = default;
public: lexer(lexer const& that);

public: auto operator=(lexer const& that) -> lexer& ;
public: lexer(lexer&& that) noexcept;
public: auto operator=(lexer&& that) noexcept -> lexer& ;
public: explicit lexer();

#line 261 "lexer.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "lexer.cpp2"

#line 1 "lexer.cpp2"

token::token(token const& that)
                                : type{ that.type }
                                , text{ that.text }
                                , line{ that.line }
                                , column{ that.column }{}
auto token::operator=(token const& that) -> token& {
                                type = that.type;
                                text = that.text;
                                line = that.line;
                                column = that.column;
                                return *this;}
token::token(token&& that) noexcept
                                : type{ std::move(that).type }
                                , text{ std::move(that).text }
                                , line{ std::move(that).line }
                                , column{ std::move(that).column }{}
auto token::operator=(token&& that) noexcept -> token& {
                                type = std::move(that).type;
                                text = std::move(that).text;
                                line = std::move(that).line;
                                column = std::move(that).column;
                                return *this;}
token::token(){}
#line 100 "lexer.cpp2"
    [[nodiscard]] auto lexer::next_token() const& -> token{
        // Skip whitespace
        skip_whitespace();

        // Check for end of file
        if (cpp2::impl::cmp_greater_eq(position,CPP2_UFCS(size)(source))) {
            return token(cpp2_enum::eof, "", line, column); 
        }

        // Get current character
        char c {CPP2_ASSERT_IN_BOUNDS(source, position)}; 

        // Handle different token types
        if (isalpha(c) || c == '_') {
            return scan_identifier(); 
        }else {if (isdigit(c)) {
            return scan_number(); 
        }else {if (c == '"') {
            return scan_string_literal(); 
        }else {if (cpp2::move(c) == '\'') {
            return scan_char_literal(); 
        }else {
            return scan_operator_or_delimiter(); 
        }}}}
    }

#line 127 "lexer.cpp2"
    auto lexer::skip_whitespace() const& -> void{
        while( cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && isspace(CPP2_ASSERT_IN_BOUNDS(source, position)) ) {
            if (CPP2_ASSERT_IN_BOUNDS(source, position) == '\n') {
                line += 1;
                column = 1;
            }else {
                column += 1;
            }
            position += 1;
        }
    }

#line 140 "lexer.cpp2"
    [[nodiscard]] auto lexer::scan_identifier() const& -> token{
        int start {position}; 
        int start_line {line}; 
        int start_column {column}; 

        while( cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && (isalnum(CPP2_ASSERT_IN_BOUNDS(source, position)) || CPP2_ASSERT_IN_BOUNDS(source, position) == '_') ) {
            column += 1;
            position += 1;
        }

        std::string text {CPP2_UFCS(substr)(source, start, position - start)}; 

        // Check if it's a keyword
        if (text == "class" || text == "func" || text == "var" || text == "let" || text == "if" || text == "else") {
            return token(cpp2_enum::keyword, cpp2::move(text), cpp2::move(start_line), cpp2::move(start_column)); 
        }else {
            return token(cpp2_enum::identifier, cpp2::move(text), cpp2::move(start_line), cpp2::move(start_column)); 
        }
    }

#line 161 "lexer.cpp2"
    [[nodiscard]] auto lexer::scan_number() const& -> token{
        int start {position}; 
        int start_line {line}; 
        int start_column {column}; 

        // Integer part
        while( cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && isdigit(CPP2_ASSERT_IN_BOUNDS(source, position)) ) {
            column += 1;
            position += 1;
        }

        // Decimal part
        if (cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && CPP2_ASSERT_IN_BOUNDS(source, position) == '.') {
            column += 1;
            position += 1;

            while( cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && isdigit(CPP2_ASSERT_IN_BOUNDS(source, position)) ) {
                column += 1;
                position += 1;
            }
        }

        std::string text {CPP2_UFCS(substr)(source, start, position - start)}; 
        return token(cpp2_enum::number, cpp2::move(text), cpp2::move(start_line), cpp2::move(start_column)); 
    }

#line 188 "lexer.cpp2"
    [[nodiscard]] auto lexer::scan_string_literal() const& -> token{
        int start {position}; 
        int start_line {line}; 
        int start_column {column}; 

        position += 1; // Skip opening quote
        column += 1;

        while( cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && CPP2_ASSERT_IN_BOUNDS(source, position) != '"' ) {
            if (CPP2_ASSERT_IN_BOUNDS(source, position) == '\\') {
                position += 2; // Skip escape sequence
                column += 2;
            }else {
                if (CPP2_ASSERT_IN_BOUNDS(source, position) == '\n') {
                    line += 1;
                    column = 1;
                }else {
                    column += 1;
                }
                position += 1;
            }
        }

        if (cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source))) {
            position += 1; // Skip closing quote
            column += 1;
        }

        std::string text {CPP2_UFCS(substr)(source, start, position - start)}; 
        return token(cpp2_enum::string_literal, cpp2::move(text), cpp2::move(start_line), cpp2::move(start_column)); 
    }

#line 221 "lexer.cpp2"
    [[nodiscard]] auto lexer::scan_char_literal() const& -> token{
        int start {position}; 
        int start_line {line}; 
        int start_column {column}; 

        position += 1; // Skip opening quote
        column += 1;

        if (cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source))) {
            if (CPP2_ASSERT_IN_BOUNDS(source, position) == '\\') {
                position += 2; // Skip escape sequence
                column += 2;
            }else {
                position += 1;
                column += 1;
            }
        }

        if (cpp2::impl::cmp_less(position,CPP2_UFCS(size)(source)) && CPP2_ASSERT_IN_BOUNDS(source, position) == '\'') {
            position += 1; // Skip closing quote
            column += 1;
        }

        std::string text {CPP2_UFCS(substr)(source, start, position - start)}; 
        return token(cpp2_enum::char_literal, cpp2::move(text), cpp2::move(start_line), cpp2::move(start_column)); 
    }

#line 249 "lexer.cpp2"
    [[nodiscard]] auto lexer::scan_operator_or_delimiter() const& -> token{
        int start {position}; 
        int start_line {line}; 
        int start_column {column}; 

        char c {CPP2_ASSERT_IN_BOUNDS(source, position)}; 
        position += 1;
        column += 1;

        std::string text {std::string(1, cpp2::move(c))}; 
        return token(cpp2_enum::operator_, cpp2::move(text), cpp2::move(start_line), cpp2::move(start_column)); 
    }


    lexer::lexer(lexer const& that)
                                : source{ that.source }
                                , position{ that.position }
                                , line{ that.line }
                                , column{ that.column }
                                , scanner{ that.scanner }{}

auto lexer::operator=(lexer const& that) -> lexer& {
                                source = that.source;
                                position = that.position;
                                line = that.line;
                                column = that.column;
                                scanner = that.scanner;
                                return *this;}
lexer::lexer(lexer&& that) noexcept
                                : source{ std::move(that).source }
                                , position{ std::move(that).position }
                                , line{ std::move(that).line }
                                , column{ std::move(that).column }
                                , scanner{ std::move(that).scanner }{}
auto lexer::operator=(lexer&& that) noexcept -> lexer& {
                                source = std::move(that).source;
                                position = std::move(that).position;
                                line = std::move(that).line;
                                column = std::move(that).column;
                                scanner = std::move(that).scanner;
                                return *this;}
lexer::lexer(){}

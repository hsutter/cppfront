#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <string_view>
#include <variant>
#include <optional>

// Hierarchical Domain Specific Embedded Language for parsing
namespace parser_dsel {

// Forward declarations
struct parse_result;
class parser_base;

// Parse result with hierarchical structure
struct parse_result {
    bool success = false;
    size_t start_pos = 0;
    size_t end_pos = 0;
    std::string matched_text;
    std::vector<parse_result> children;
    std::string error_message;

    // Type evidence metadata
    std::string evidence_type;
    int confidence_level = 0;

    parse_result() = default;
    parse_result(bool s, size_t start, size_t end, std::string text = "")
        : success(s), start_pos(start), end_pos(end), matched_text(std::move(text)) {}
};

class parser_base {
public:
    virtual ~parser_base() = default;
    virtual parse_result parse(std::string_view input, size_t& pos) const = 0;
    virtual std::string description() const = 0;
    virtual std::string name() const { return description(); }
};

// Hierarchical parser with type evidence integration
class hierarchical_parser : public parser_base {
public:
    explicit hierarchical_parser(std::string n) : parser_name(std::move(n)) {}

    void set_root_parser(std::unique_ptr<parser_base> p) {
        root_parser = std::move(p);
    }

    parse_result parse(std::string_view input, size_t& pos) const override {
        if (!root_parser) {
            return parse_result(false, pos, pos, "");
        }

        size_t start_pos = pos;
        auto result = root_parser->parse(input, pos);

        if (result.success) {
            result.evidence_type = parser_name;
            result.confidence_level = calculate_confidence(result);
        }

        return result;
    }

    std::string description() const override {
        return "hierarchical_parser(" + parser_name + ")";
    }

private:
    std::string parser_name;
    std::unique_ptr<parser_base> root_parser;

    int calculate_confidence(const parse_result& result) const {
        // Calculate confidence based on parse structure
        int confidence = 50; // base confidence

        // More children = more structured = higher confidence
        confidence += std::min(30, static_cast<int>(result.children.size()) * 5);

        // Longer matches = more confident
        confidence += std::min(20, static_cast<int>((result.end_pos - result.start_pos) / 10));

        return std::min(100, confidence);
    }
};// Character parser
class char_parser : public parser_base {
public:
    explicit char_parser(char c) : ch(c) {}

    parse_result parse(std::string_view input, size_t& pos) const override {
        if (pos < input.size() && input[pos] == ch) {
            ++pos;
            return parse_result(true, pos-1, pos, std::string(1, ch));
        }
        return parse_result(false, pos, pos, "");
    }

    std::string description() const override {
        return std::string("char('") + ch + "')";
    }

private:
    char ch;
};

// String parser
class str_parser : public parser_base {
public:
    explicit str_parser(std::string s) : str(std::move(s)) {}

    parse_result parse(std::string_view input, size_t& pos) const override {
        if (pos + str.size() <= input.size() &&
            input.substr(pos, str.size()) == str) {
            pos += str.size();
            return parse_result(true, pos - str.size(), pos, str);
        }
        return parse_result(false, pos, pos, "");
    }

    std::string description() const override {
        return "str(\"" + str + "\")";
    }

private:
    std::string str;
};

// Alternative parser
class alt_parser : public parser_base {
public:
    void add_parser(std::unique_ptr<parser_base> p) {
        parsers.push_back(std::move(p));
    }

    parse_result parse(std::string_view input, size_t& pos) const override {
        for (const auto& parser : parsers) {
            size_t temp_pos = pos;
            auto result = parser->parse(input, temp_pos);
            if (result.success) {
                pos = temp_pos;
                return result;
            }
        }
        return parse_result(false, pos, pos, "");
    }

    std::string description() const override {
        std::string desc = "alt(";
        for (size_t i = 0; i < parsers.size(); ++i) {
            if (i > 0) desc += ", ";
            desc += parsers[i]->description();
        }
        desc += ")";
        return desc;
    }

private:
    std::vector<std::unique_ptr<parser_base>> parsers;
};

// Optional parser
class opt_parser : public parser_base {
public:
    explicit opt_parser(std::unique_ptr<parser_base> p) : parser(std::move(p)) {}

    parse_result parse(std::string_view input, size_t& pos) const override {
        size_t temp_pos = pos;
        auto result = parser->parse(input, temp_pos);
        if (result.success) {
            pos = temp_pos;
            return result;
        }
        return parse_result(true, pos, pos, ""); // Optional always succeeds
    }

    std::string description() const override {
        return parser->description() + "?";
    }

private:
    std::unique_ptr<parser_base> parser;
};

// Helper functions
inline std::unique_ptr<char_parser> char_(char c) {
    return std::make_unique<char_parser>(c);
}

inline std::unique_ptr<str_parser> str(std::string s) {
    return std::make_unique<str_parser>(std::move(s));
}

inline std::unique_ptr<alt_parser> alt() {
    return std::make_unique<alt_parser>();
}

} // namespace parser_dsel

#pragma once

#include "parser_dsel.h"
#include "type_evidence.h"
#include <string>
#include <vector>
#include <memory>
#include <functional>

// Wide scanner integration system
namespace wide_scan_integration {

class wide_scanner_integration {
public:
    wide_scanner_integration() : hierarchical_parser("cpp_code_parser") {
        initialize_parser_combinators();
        initialize_type_evidence_system();
    }

    // Main scanning interface
    parser_dsel::parse_result scan_code(const std::string& code) {
        size_t pos = 0;
        return hierarchical_parser.parse(code, pos);
    }

    // Perform hierarchical scanning with type evidence collection
    void perform_hierarchical_scan(const std::string& code) {
        evidence_collector.perform_hierarchical_scan(code);

        // Integrate parser results with type evidence
        size_t pos = 0;
        auto parse_result = hierarchical_parser.parse(code, pos);

        if (parse_result.success) {
            extract_type_evidence_from_parse_tree(parse_result);
        }
    }

    // Get type evidence results
    type_evidence::type_evidence get_type_evidence(const std::string& type_name) const {
        return evidence_collector.get_evidence(type_name);
    }

    std::vector<type_evidence::type_evidence> get_all_type_evidence() const {
        return evidence_collector.get_all_evidence();
    }

    // Bayesian analysis interface
    double calculate_type_probability(const std::string& type_name, const std::string& context) const {
        return evidence_collector.calculate_bayesian_probability(type_name, context);
    }

    // Type lattice queries
    bool is_subtype(const std::string& subtype, const std::string& supertype) const {
        return evidence_collector.is_subtype_of(subtype, supertype);
    }

    std::vector<std::string> get_type_supertypes(const std::string& type) const {
        return evidence_collector.get_supertypes(type);
    }

private:
    parser_dsel::hierarchical_parser hierarchical_parser;
    type_evidence::enhanced_type_evidence_collector evidence_collector;

void initialize_parser_combinators() {
    // Create basic parsers for C++ constructs
    auto type_parser = create_type_parser();
    auto identifier_parser = create_identifier_parser();
    auto expression_parser = create_expression_parser();

    // Create main parser combining all constructs
    auto main_parser = std::make_unique<parser_dsel::alt_parser>();
    main_parser->add_parser(std::move(type_parser));
    main_parser->add_parser(std::move(identifier_parser));
    main_parser->add_parser(std::move(expression_parser));

    hierarchical_parser.set_root_parser(std::move(main_parser));
}    void initialize_type_evidence_system() {
        // Initialize with common C++ types
        std::vector<std::string> common_types = {
            "int", "double", "float", "char", "bool", "string",
            "vector", "array", "map", "set", "pair"
        };

        for (const auto& type : common_types) {
            type_evidence::type_evidence evidence(type, 0.5);
            evidence.evidence_source = "initialization";
            evidence_collector.add_evidence(evidence);
        }
    }

    std::unique_ptr<parser_dsel::parser_base> create_type_parser() {
        // Parser for C++ type declarations
        auto alt_parser = parser_dsel::alt();

        // Basic types
        alt_parser->add_parser(parser_dsel::str("int"));
        alt_parser->add_parser(parser_dsel::str("double"));
        alt_parser->add_parser(parser_dsel::str("float"));
        alt_parser->add_parser(parser_dsel::str("char"));
        alt_parser->add_parser(parser_dsel::str("bool"));
        alt_parser->add_parser(parser_dsel::str("string"));

        // Template types
        alt_parser->add_parser(parser_dsel::str("vector<"));
        alt_parser->add_parser(parser_dsel::str("array<"));
        alt_parser->add_parser(parser_dsel::str("map<"));
        alt_parser->add_parser(parser_dsel::str("set<"));

        return alt_parser;
    }

    std::unique_ptr<parser_dsel::parser_base> create_identifier_parser() {
        // Simple identifier parser (letters, digits, underscores)
        // This is a simplified version - real implementation would be more complex
        auto alt_parser = parser_dsel::alt();

        // Add common identifier patterns
        for (char c = 'a'; c <= 'z'; ++c) {
            alt_parser->add_parser(parser_dsel::char_(c));
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            alt_parser->add_parser(parser_dsel::char_(c));
        }
        alt_parser->add_parser(parser_dsel::char_('_'));

        return alt_parser;
    }

    std::unique_ptr<parser_dsel::parser_base> create_expression_parser() {
        // Simple expression parser for basic operators
        auto alt_parser = parser_dsel::alt();

        alt_parser->add_parser(parser_dsel::char_('+'));
        alt_parser->add_parser(parser_dsel::char_('-'));
        alt_parser->add_parser(parser_dsel::char_('*'));
        alt_parser->add_parser(parser_dsel::char_('/'));
        alt_parser->add_parser(parser_dsel::char_('='));
        alt_parser->add_parser(parser_dsel::str("=="));
        alt_parser->add_parser(parser_dsel::str("!="));
        alt_parser->add_parser(parser_dsel::str("<="));
        alt_parser->add_parser(parser_dsel::str(">="));
        alt_parser->add_parser(parser_dsel::char_('<'));
        alt_parser->add_parser(parser_dsel::char_('>'));

        return alt_parser;
    }

    void extract_type_evidence_from_parse_tree(const parser_dsel::parse_result& result) {
        // Extract type evidence from successful parse results
        if (result.success && !result.evidence_type.empty()) {
            type_evidence::type_evidence evidence(result.evidence_type,
                                                result.confidence_level / 100.0);
            evidence.occurrence_count = 1;
            evidence.evidence_source = "parse_tree_extraction";
            evidence_collector.add_evidence(evidence);
        }

        // Recursively process children
        for (const auto& child : result.children) {
            extract_type_evidence_from_parse_tree(child);
        }
    }
};

// Factory function for creating scanner integration
inline std::unique_ptr<wide_scanner_integration> create_wide_scanner() {
    return std::make_unique<wide_scanner_integration>();
}

} // namespace wide_scan_integration

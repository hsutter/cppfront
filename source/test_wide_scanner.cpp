#include "wide_scan_integration.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "=== Advanced Cpp2 Scanner Integration Test ===\n\n";

    // Create the scanner integration system
    auto scanner = wide_scan_integration::create_wide_scanner();

    // Test code samples
    std::vector<std::string> test_codes = {
        "int x = 42;",
        "vector<string> names;",
        "double calculate(vector<int> values) { return 0.0; }",
        "map<string, int> lookup_table;",
        "template<typename T> class Container { T value; };"
    };

    std::cout << "1. Performing hierarchical scanning on test code samples...\n";
    for (const auto& code : test_codes) {
        std::cout << "   Scanning: " << code << "\n";
        scanner->perform_hierarchical_scan(code);
    }

    std::cout << "\n2. Type evidence collected:\n";
    auto all_evidence = scanner->get_all_type_evidence();
    for (const auto& evidence : all_evidence) {
        std::cout << "   Type: " << evidence.type_name
                  << ", Probability: " << std::fixed << std::setprecision(3)
                  << evidence.bayesian_probability
                  << ", Occurrences: " << evidence.occurrence_count
                  << ", Source: " << evidence.evidence_source << "\n";
    }

    std::cout << "\n3. Bayesian probability calculations:\n";
    std::vector<std::pair<std::string, std::string>> test_queries = {
        {"int", "numeric calculation"},
        {"string", "text processing"},
        {"vector", "container operations"},
        {"double", "floating point math"}
    };

    for (const auto& [type, context] : test_queries) {
        double prob = scanner->calculate_type_probability(type, context);
        std::cout << "   P(" << type << " | " << context << ") = "
                  << std::fixed << std::setprecision(3) << prob << "\n";
    }

    std::cout << "\n4. Type lattice relationships:\n";
    std::vector<std::string> test_types = {"int", "vector<int>", "string"};
    for (const auto& type : test_types) {
        auto supertypes = scanner->get_type_supertypes(type);
        std::cout << "   " << type << " supertypes: ";
        if (supertypes.empty()) {
            std::cout << "none";
        } else {
            for (size_t i = 0; i < supertypes.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << supertypes[i];
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n5. Parser DSEL demonstration:\n";
    std::string test_input = "int x = vector<string> y;";
    auto parse_result = scanner->scan_code(test_input);
    std::cout << "   Parsing: " << test_input << "\n";
    std::cout << "   Success: " << (parse_result.success ? "true" : "false") << "\n";
    std::cout << "   Matched: " << parse_result.matched_text << "\n";
    std::cout << "   Confidence: " << parse_result.confidence_level << "/100\n";

    std::cout << "\n=== Test completed successfully ===\n";
    return 0;
}

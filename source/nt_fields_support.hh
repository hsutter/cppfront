#pragma

#include <string>

inline  void replaceAtFields( std::string& input) {
    if (input.find("@") == std::string::npos) { 
        return;
    }

    std::string output;
    output.reserve(input.size() * 2); // avoid reallocations

    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '@') {
            // start of identifier
            size_t j = i + 1;
            while (j < input.size() && 
                   (std::isalnum(static_cast<unsigned char>(input[j])) || input[j] == '_')) {
                ++j;
            }

            // Extract identifier
            std::string name = input.substr(i + 1, j - (i + 1));

            if (!name.empty()) {
                output += "nt_field(";
                output += name;
                output += ")";
                i = j - 1; // skip past the identifier
                continue;
            }
        }
        // fallback: copy char as is
        output.push_back(input[i]);
    }

    input = output;
}
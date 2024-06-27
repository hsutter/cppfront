#pragma once

#include <string>
#include <algorithm>
#include <sstream>

namespace cpp2 {
namespace string_util {

// From https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring

// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
inline std::string ltrim_copy(std::string_view s) {
    std::string t(s);
    ltrim(t);
    return t;
}

// trim from end (copying)
inline std::string rtrim_copy(std::string_view s) {
    std::string t(s);
    rtrim(t);
    return t;
}

// trim from both ends (copying)
inline std::string trim_copy(std::string_view s) {
    std::string t(s);
    trim(t);
    return t;
}

// From https://oleksandrkvl.github.io/2021/04/02/cpp-20-overview.html#nttp

template<typename CharT, std::size_t N>
struct fixed_string {
    constexpr fixed_string(const CharT (&s)[N+1]) {
        std::copy_n(s, N + 1, c_str);
    }
    constexpr const CharT* data() const {
        return c_str;
    }
    constexpr std::size_t size() const {
        return N;
    }

    constexpr auto str() const {
        return std::basic_string<CharT>(c_str);
    }

    CharT c_str[N+1];
};

template<typename CharT, std::size_t N>
fixed_string(const CharT (&)[N])->fixed_string<CharT, N-1>;

// Other utility functions.

inline bool is_escaped(std::string_view s) {
    return s.starts_with("\"") && s.ends_with("\"");
}

inline bool string_to_int(std::string const& s, int& v, int base = 10) {
    try {
        v = stoi(s, nullptr, base);
        return true;
    }
    catch (std::invalid_argument const&)
    {
        return false;
    }
    catch (std::out_of_range const&)
    {
        return false;
    }
}

inline std::string int_to_string(int i, int base = 10) {
    if (8 == base) {
        std::ostringstream oss;
        oss << std::oct << i;
        return oss.str();
    }
    else if (10 == base) {
        return std::to_string(i);
    }
    else if (16 == base) {
        std::ostringstream oss;
        oss << std::hex << i;
        return oss.str();
    }
    else {
        throw std::runtime_error("Base " + std::to_string(i) + " not implemented.");
    }
}

inline char safe_toupper(char ch) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

inline char safe_tolower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

inline std::string replace_all(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

template<typename List>
inline std::string join(List const& list) {
    std::string r = "";
    std::string sep = "";

    for (auto const& cur : list) {
        r += sep + cur;
        sep = ", ";
    }

    return r;
}

} // namespace string_util
} // namespace cpp2
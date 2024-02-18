#pragma once

#include <string>
#include <algorithm>

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
        std::copy_n(s, N + 1, str);
    }
    constexpr const CharT* data() const {
        return str;
    }
    constexpr std::size_t size() const {
        return N;
    }

    CharT str[N+1];
};

template<typename CharT, std::size_t N>
fixed_string(const CharT (&)[N])->fixed_string<CharT, N-1>;

// Other utility functions.

inline bool is_escaped(std::string_view s) {
    return s.starts_with("\"") && s.ends_with("\"");
}

inline bool string_to_int(std::string const& s, int& v) {
    try {
        v = stoi(s);
        return true;
    }
    catch (std::invalid_argument const& ex)
    {
        return false;
    }
    catch (std::out_of_range const& ex)
    {
        return false;
    }
}

inline char safe_toupper(char ch) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

inline char safe_tolower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

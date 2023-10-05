//
// Created by root on 05.10.23.
//

#ifndef CPPFRONT_POSITIONAL_PRINTER_UTILS_HPP
#define CPPFRONT_POSITIONAL_PRINTER_UTILS_HPP
namespace cpp2{
    auto pad(int padding)
    -> std::string_view
    {
        if (padding < 1) {
            return "";
        }

        return {
                indent_str.c_str(),
                _as<size_t>( std::min( padding, _as<int>(std::ssize(indent_str))) )
        };
    }
};
#endif //CPPFRONT_POSITIONAL_PRINTER_UTILS_HPP

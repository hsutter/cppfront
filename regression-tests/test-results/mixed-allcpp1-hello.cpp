#line 1 "mixed-allcpp1-hello.cpp2"
#line 1 "mixed-allcpp1-hello.cpp2"

//  Step 1: rename .cpp to .cpp2

#include <iostream>
#include <string>

#pragma auto_inline(on)

//  Here's a sample Syntax 1 "Hello world"...

auto main() -> int
{
    auto s = std::string{"world\n"};
    std::cout << "Hello " << s;
}

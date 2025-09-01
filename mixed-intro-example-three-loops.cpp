#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <span>
#include <memory>

auto print(auto const& x) -> void { 
    std::cout << ">> " << x << "\n";
}

auto decorate_and_print(auto& x) -> void { 
    x = "[" + x + "]";
    print(x);
}

auto main() -> int {
    auto words = std::vector<std::string>
        { "hello", "big", "world" };

    std::span<std::string> view{ words };

    auto i = std::make_unique<int>(0);
    while (*i < view.size()) {
        print( view[*i] );
        ++*i;
    }

    do {
        std::cout << std::setw(4) << "**";
    } while (--*i > 0);

    std::cout << "\n";
    for (auto& word : words) {
        decorate_and_print(word);
    }
}

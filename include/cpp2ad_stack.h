#ifndef CPP2_CPP2AD_STACK_H
#define CPP2_CPP2AD_STACK_H

#include <vector>

namespace cpp2 {

struct ad_stack {

    template<typename T>
    static void push(T const& v) {
        std::vector<T>& stack = get_stack<T>();

        stack.push_back(v);
    }

    template<typename T>
    static T pop() {
        std::vector<T>& stack = get_stack<T>();

        T v = stack.back();
        stack.pop_back();

        return v;
    }

    private:

    template<typename T>
    static std::vector<T>& get_stack() {
        static std::vector<T> stack = {};

        return stack;
    }
};
} // cpp2 namespace

#endif // CPP2_CPP2AD_STACK_H
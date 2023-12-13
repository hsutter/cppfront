
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-defaulted-comparisons-and-final-types.cpp2"

#line 2 "pure2-defaulted-comparisons-and-final-types.cpp2"
class widget;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-defaulted-comparisons-and-final-types.cpp2"

#line 2 "pure2-defaulted-comparisons-and-final-types.cpp2"
class widget final
 {
    private: int v; 

    public: explicit widget(cpp2::in<int> value);
#line 6 "pure2-defaulted-comparisons-and-final-types.cpp2"
    public: auto operator=(cpp2::in<int> value) -> widget& ;

    public: [[nodiscard]] auto operator==(widget const& that) const& -> bool = default;

    public: [[nodiscard]] auto operator<=>(widget const& that) const& -> std::strong_ordering = default;
    public: widget(widget const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(widget const&) -> void = delete;

#line 11 "pure2-defaulted-comparisons-and-final-types.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-defaulted-comparisons-and-final-types.cpp2"

#line 6 "pure2-defaulted-comparisons-and-final-types.cpp2"
    widget::widget(cpp2::in<int> value)
                                          : v{ value }{}
#line 6 "pure2-defaulted-comparisons-and-final-types.cpp2"
    auto widget::operator=(cpp2::in<int> value) -> widget& {
                                          v = value;
                                          return *this; }

#line 13 "pure2-defaulted-comparisons-and-final-types.cpp2"
auto main() -> int{
    widget a {1}; 
    widget b {2}; 
    if (cpp2::cmp_less(std::move(a),std::move(b))) {
        std::cout << "less";
    }
    else {
        std::cout << "more";
    }
}



#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-value-types-via-meta-functions.cpp2"
class widget;
    

#line 7 "pure2-types-value-types-via-meta-functions.cpp2"
class w_widget;
    

#line 12 "pure2-types-value-types-via-meta-functions.cpp2"
class p_widget;
    

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-value-types-via-meta-functions.cpp2"
class widget {
    private: int val {0}; 
    public: explicit widget(cpp2::in<int> i);
#line 4 "pure2-types-value-types-via-meta-functions.cpp2"
    public: auto operator=(cpp2::in<int> i) -> widget& ;

public: [[nodiscard]] auto operator<=>(widget const& that) const -> std::strong_ordering = default;
public: widget(widget const& that);
public: auto operator=(widget const& that) -> widget& ;
public: widget(widget&& that) noexcept;
public: auto operator=(widget&& that) noexcept -> widget& ;
public: explicit widget();

#line 5 "pure2-types-value-types-via-meta-functions.cpp2"
};

class w_widget {
    private: int val {0}; 
    public: explicit w_widget(cpp2::in<int> i);
#line 9 "pure2-types-value-types-via-meta-functions.cpp2"
    public: auto operator=(cpp2::in<int> i) -> w_widget& ;

public: [[nodiscard]] auto operator<=>(w_widget const& that) const -> std::weak_ordering = default;
public: w_widget(w_widget const& that);
public: auto operator=(w_widget const& that) -> w_widget& ;
public: w_widget(w_widget&& that) noexcept;
public: auto operator=(w_widget&& that) noexcept -> w_widget& ;
public: explicit w_widget();

#line 10 "pure2-types-value-types-via-meta-functions.cpp2"
};

class p_widget {
    private: int val {0}; 
    public: explicit p_widget(cpp2::in<int> i);
#line 14 "pure2-types-value-types-via-meta-functions.cpp2"
    public: auto operator=(cpp2::in<int> i) -> p_widget& ;

public: [[nodiscard]] auto operator<=>(p_widget const& that) const -> std::partial_ordering = default;
public: p_widget(p_widget const& that);
public: auto operator=(p_widget const& that) -> p_widget& ;
public: p_widget(p_widget&& that) noexcept;
public: auto operator=(p_widget&& that) noexcept -> p_widget& ;
public: explicit p_widget();

#line 15 "pure2-types-value-types-via-meta-functions.cpp2"
};

auto main() -> int;
    

#line 23 "pure2-types-value-types-via-meta-functions.cpp2"
template<typename T> auto test() -> void;
    

//=== Cpp2 function definitions =================================================


#line 4 "pure2-types-value-types-via-meta-functions.cpp2"
    widget::widget(cpp2::in<int> i)
                                      : val{ i }
#line 4 "pure2-types-value-types-via-meta-functions.cpp2"
    {}
#line 4 "pure2-types-value-types-via-meta-functions.cpp2"
    auto widget::operator=(cpp2::in<int> i) -> widget& {
                                      val = i;
                                      return *this;
#line 4 "pure2-types-value-types-via-meta-functions.cpp2"
    }


    widget::widget(widget const& that)
                                : val{ that.val }{}

auto widget::operator=(widget const& that) -> widget& {
                                val = that.val;
                                return *this;}
widget::widget(widget&& that) noexcept
                                : val{ std::move(that).val }{}
auto widget::operator=(widget&& that) noexcept -> widget& {
                                val = std::move(that).val;
                                return *this;}
widget::widget(){}
#line 9 "pure2-types-value-types-via-meta-functions.cpp2"
    w_widget::w_widget(cpp2::in<int> i)
                                      : val{ i }
#line 9 "pure2-types-value-types-via-meta-functions.cpp2"
    {}
#line 9 "pure2-types-value-types-via-meta-functions.cpp2"
    auto w_widget::operator=(cpp2::in<int> i) -> w_widget& {
                                      val = i;
                                      return *this;
#line 9 "pure2-types-value-types-via-meta-functions.cpp2"
    }


    w_widget::w_widget(w_widget const& that)
                                : val{ that.val }{}

auto w_widget::operator=(w_widget const& that) -> w_widget& {
                                val = that.val;
                                return *this;}
w_widget::w_widget(w_widget&& that) noexcept
                                : val{ std::move(that).val }{}
auto w_widget::operator=(w_widget&& that) noexcept -> w_widget& {
                                val = std::move(that).val;
                                return *this;}
w_widget::w_widget(){}
#line 14 "pure2-types-value-types-via-meta-functions.cpp2"
    p_widget::p_widget(cpp2::in<int> i)
                                      : val{ i }
#line 14 "pure2-types-value-types-via-meta-functions.cpp2"
    {}
#line 14 "pure2-types-value-types-via-meta-functions.cpp2"
    auto p_widget::operator=(cpp2::in<int> i) -> p_widget& {
                                      val = i;
                                      return *this;
#line 14 "pure2-types-value-types-via-meta-functions.cpp2"
    }


    p_widget::p_widget(p_widget const& that)
                                : val{ that.val }{}

auto p_widget::operator=(p_widget const& that) -> p_widget& {
                                val = that.val;
                                return *this;}
p_widget::p_widget(p_widget&& that) noexcept
                                : val{ std::move(that).val }{}
auto p_widget::operator=(p_widget&& that) noexcept -> p_widget& {
                                val = std::move(that).val;
                                return *this;}
p_widget::p_widget(){}
#line 17 "pure2-types-value-types-via-meta-functions.cpp2"
auto main() -> int{
    test<widget>();
    test<w_widget>();
    test<p_widget>();
}

template<typename T> auto test() -> void{
    //  should be default constructible
    T a {}; 

    //  widget should be comparable
    T b {2}; 
    if ((cpp2::cmp_less(std::move(a),std::move(b)))) {
        std::cout << "less ";
    }
    else {
        std::cout << "more ";
    }
}




//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-increment-decrement.cpp2"

#line 2 "mixed-increment-decrement.cpp2"
template<typename T> class iterator;
    

#line 7 "mixed-increment-decrement.cpp2"
template<typename T> class iterator2;
    

#line 34 "mixed-increment-decrement.cpp2"
class number;
  

#line 39 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> class number_line;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-increment-decrement.cpp2"

#line 2 "mixed-increment-decrement.cpp2"
template<typename T> class iterator {
    public: T x {0}; 
    public: auto operator++() & -> iterator<T>&
CPP2_REQUIRES_ (true) ;
#line 4 "mixed-increment-decrement.cpp2"
    public: auto operator++(int) & -> iterator<T>
CPP2_REQUIRES_ (true) ;
    public: [[nodiscard]] auto operator<=>(iterator const& that) const& -> std::strong_ordering = default;
public: iterator(iterator const& that);

public: auto operator=(iterator const& that) -> iterator& ;
public: iterator(iterator&& that) noexcept;
public: auto operator=(iterator&& that) noexcept -> iterator& ;
public: explicit iterator();

#line 5 "mixed-increment-decrement.cpp2"
};

template<typename T> class iterator2 {
    public: T x {0}; 
    public: [[nodiscard]] auto operator<=>(iterator2 const& that) const& -> std::strong_ordering = default;
public: iterator2(iterator2 const& that);

public: auto operator=(iterator2 const& that) -> iterator2& ;
public: iterator2(iterator2&& that) noexcept;
public: auto operator=(iterator2&& that) noexcept -> iterator2& ;
public: explicit iterator2();

#line 9 "mixed-increment-decrement.cpp2"
};
template<typename T> auto operator++(iterator2<T>& it) -> iterator2<T>&
CPP2_REQUIRES (true) ;
#line 10 "mixed-increment-decrement.cpp2"
template<typename T> auto operator++(iterator2<T>& it,int) -> iterator2<T>
CPP2_REQUIRES (true) ;

int main() {
    {
    iterator<int> i;
    std::cout << (++i).x;
    std::cout << (++i).x;
    std::cout << i++.x;
    std::cout << i++.x;
    std::cout << i.x << "\n";
    }

    {
    iterator2<int> i;
    std::cout << (++i).x;
    std::cout << (++i).x;
    std::cout << i++.x;
    std::cout << i++.x;
    std::cout << i.x << "\n";
    }
}

#line 34 "mixed-increment-decrement.cpp2"
class number {
  public: [[nodiscard]] auto operator<=>([[maybe_unused]] number const& that) const& -> auto = default;
  public: [[nodiscard]] auto operator-([[maybe_unused]] auto const& unnamed_param_2) const& -> int;
};

template<cpp2::i8 Op, cpp2::i32 Id> class number_line: public number {

};

template                   <    cpp2::i32 Id> using number_line_pre_increment = number_line<0b1110,Id>;
template                   <    cpp2::i32 Id> using number_line_pre_decrement = number_line<0b1101,Id>;
template<cpp2::i32 Id> using number_line_post_increment = number_line<0b1011,Id>;
template<cpp2::i32 Id> using number_line_post_decrement = number_line<0b0111,Id>;

template<cpp2::i8 Op, cpp2::i32 Id> auto operator++(number_line<Op,Id>& x) -> number_line<Op,Id>&
CPP2_REQUIRES (bool(Op & 1)) ;
#line 48 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator++(number_line<Op,Id>& x,int) -> number_line<Op,Id>
CPP2_REQUIRES (bool(Op & 1)) ;
#line 49 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator--(number_line<Op,Id>& x) -> number_line<Op,Id>&
CPP2_REQUIRES (bool(Op & 2)) ;
#line 49 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator--(number_line<Op,Id>& x,int) -> number_line<Op,Id>
CPP2_REQUIRES (bool(Op & 2)) ;

#line 51 "mixed-increment-decrement.cpp2"
auto operator++(number_line_pre_increment<0>& x) -> number_line_pre_increment<0>&;
#line 51 "mixed-increment-decrement.cpp2"
auto operator++(number_line_pre_increment<0>& x,int) -> number_line_pre_increment<0>;
auto operator--(number_line_pre_decrement<0>& x) -> number_line_pre_decrement<0>&;
#line 52 "mixed-increment-decrement.cpp2"
auto operator--(number_line_pre_decrement<0>& x,int) -> number_line_pre_decrement<0>;

auto operator++(number_line_pre_increment<1>& x) -> number_line_pre_increment<1> const&;
#line 54 "mixed-increment-decrement.cpp2"
auto operator++(number_line_pre_increment<1>& x,int) -> number_line_pre_increment<1> const;
auto operator--(number_line_pre_decrement<1>& x) -> number_line_pre_decrement<1> const&;
#line 55 "mixed-increment-decrement.cpp2"
auto operator--(number_line_pre_decrement<1>& x,int) -> number_line_pre_decrement<1> const;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-increment-decrement.cpp2"

#line 4 "mixed-increment-decrement.cpp2"
    template <typename T> auto iterator<T>::operator++() & -> iterator<T>&
requires (true) {++x; return (*this); }
#line 4 "mixed-increment-decrement.cpp2"
    template <typename T> auto iterator<T>::operator++(int) & -> iterator<T>
requires (true)  { auto ret = *this; ++*this; return ret; }


    template <typename T> iterator<T>::iterator(iterator const& that)
                                : x{ that.x }{}

template <typename T> auto iterator<T>::operator=(iterator const& that) -> iterator& {
                                x = that.x;
                                return *this;}
template <typename T> iterator<T>::iterator(iterator&& that) noexcept
                                : x{ std::move(that).x }{}
template <typename T> auto iterator<T>::operator=(iterator&& that) noexcept -> iterator& {
                                x = std::move(that).x;
                                return *this;}
template <typename T> iterator<T>::iterator(){}
template <typename T> iterator2<T>::iterator2(iterator2 const& that)
                                : x{ that.x }{}
template <typename T> auto iterator2<T>::operator=(iterator2 const& that) -> iterator2& {
                                x = that.x;
                                return *this;}
template <typename T> iterator2<T>::iterator2(iterator2&& that) noexcept
                                : x{ std::move(that).x }{}
template <typename T> auto iterator2<T>::operator=(iterator2&& that) noexcept -> iterator2& {
                                x = std::move(that).x;
                                return *this;}
template <typename T> iterator2<T>::iterator2(){}
#line 10 "mixed-increment-decrement.cpp2"
template<typename T> auto operator++(iterator2<T>& it) -> iterator2<T>&
requires (true) {++it.x; return it; }
#line 10 "mixed-increment-decrement.cpp2"
template<typename T> auto operator++(iterator2<T>& it,int) -> iterator2<T>
requires (true)  { auto ret = it; ++it; return ret; }

#line 36 "mixed-increment-decrement.cpp2"
  [[nodiscard]] auto number::operator-([[maybe_unused]] auto const& unnamed_param_2) const& -> int { return 0;  }

#line 48 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator++(number_line<Op,Id>& x) -> number_line<Op,Id>&
requires (bool(Op & 1))  { return x;  }
#line 48 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator++(number_line<Op,Id>& x,int) -> number_line<Op,Id>
requires (bool(Op & 1))  { auto ret = x; ++x; return ret; }
#line 49 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator--(number_line<Op,Id>& x) -> number_line<Op,Id>&
requires (bool(Op & 2))  { return x;  }
#line 49 "mixed-increment-decrement.cpp2"
template<cpp2::i8 Op, cpp2::i32 Id> auto operator--(number_line<Op,Id>& x,int) -> number_line<Op,Id>
requires (bool(Op & 2))  { auto ret = x; ++x; return ret; }

#line 51 "mixed-increment-decrement.cpp2"
auto operator++(number_line_pre_increment<0>& x) -> number_line_pre_increment<0>& { return x;  }
#line 51 "mixed-increment-decrement.cpp2"
auto operator++(number_line_pre_increment<0>& x,int) -> number_line_pre_increment<0> { auto ret = x; ++x; return ret; }
auto operator--(number_line_pre_decrement<0>& x) -> number_line_pre_decrement<0>& { return x;  }
#line 52 "mixed-increment-decrement.cpp2"
auto operator--(number_line_pre_decrement<0>& x,int) -> number_line_pre_decrement<0> { auto ret = x; ++x; return ret; }

auto operator++(number_line_pre_increment<1>& x) -> number_line_pre_increment<1> const& { return x;  }
#line 54 "mixed-increment-decrement.cpp2"
auto operator++(number_line_pre_increment<1>& x,int) -> number_line_pre_increment<1> const { auto ret = x; ++x; return ret; }
auto operator--(number_line_pre_decrement<1>& x) -> number_line_pre_decrement<1> const& { return x;  }
#line 55 "mixed-increment-decrement.cpp2"
auto operator--(number_line_pre_decrement<1>& x,int) -> number_line_pre_decrement<1> const { auto ret = x; ++x; return ret; }


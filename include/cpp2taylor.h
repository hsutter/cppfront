
#ifndef CPP2TAYLOR_H_CPP2
#define CPP2TAYLOR_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "cpp2taylor.h2"

#line 4 "cpp2taylor.h2"
namespace cpp2 {

template<typename R, int dim> class taylor;
    

#line 257 "cpp2taylor.h2"
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "cpp2taylor.h2"
#ifndef CPP2_CPP2TAYLOR_H
#define CPP2_CPP2TAYLOR_H

#line 4 "cpp2taylor.h2"
namespace cpp2 {

template<typename R, int dim> class taylor {
    public: std::array<R,dim> v {}; 

    public: explicit taylor();
    public: taylor(R const& d1);
#line 10 "cpp2taylor.h2"
    public: auto operator=(R const& d1) -> taylor& ;

#line 14 "cpp2taylor.h2"
    public: taylor(taylor const& that);
#line 14 "cpp2taylor.h2"
    public: auto operator=(taylor const& that) -> taylor& ;
#line 14 "cpp2taylor.h2"
    public: taylor(taylor&& that) noexcept;
#line 14 "cpp2taylor.h2"
    public: auto operator=(taylor&& that) noexcept -> taylor& ;

    public: taylor(std::initializer_list<R> const& l);
#line 16 "cpp2taylor.h2"
    public: auto operator=(std::initializer_list<R> const& l) -> taylor& ;

#line 23 "cpp2taylor.h2"
    // C++ interface

    public: [[nodiscard]] auto operator[](cpp2::impl::in<int> k) const& -> R;

#line 35 "cpp2taylor.h2"
    public: auto set(cpp2::impl::in<int> k, cpp2::impl::in<R> value) & -> void;

#line 45 "cpp2taylor.h2"
    // C++2 interface / AD interface

    public: [[nodiscard]] auto get(cpp2::impl::in<int> i, cpp2::impl::in<R> v0) const& -> R;

#line 58 "cpp2taylor.h2"
    // Overload for reverse AD.
    public: auto operator+=(cpp2::impl::in<taylor> o) & -> auto&&;

#line 64 "cpp2taylor.h2"
    // Overload for reverse AD.
    public: auto operator-=(cpp2::impl::in<taylor> o) & -> auto&&;

#line 70 "cpp2taylor.h2"
    // Overload for simple handling of connected adds.
    public: [[nodiscard]] auto operator+(cpp2::impl::in<taylor> o) const& -> taylor;

#line 75 "cpp2taylor.h2"
    // Overload for simple handling of connected minuses.
    public: [[nodiscard]] auto operator-(cpp2::impl::in<taylor> o) const& -> taylor;

#line 80 "cpp2taylor.h2"
    // Overload for simple handling of prefix +.
    public: [[nodiscard]] auto operator+() const& -> taylor;

#line 85 "cpp2taylor.h2"
    // Overload for simple handling of prefix -.
    public: [[nodiscard]] auto operator-() const& -> taylor;

#line 97 "cpp2taylor.h2"
    public: [[nodiscard]] auto add(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 108 "cpp2taylor.h2"
    public: [[nodiscard]] auto sub(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 119 "cpp2taylor.h2"
    public: template<int dim_o> [[nodiscard]] auto mul(taylor<R,dim_o> const& o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor<R,std::max(dim, dim_o)>;

#line 133 "cpp2taylor.h2"
    public: [[nodiscard]] auto div(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 151 "cpp2taylor.h2"
    public: [[nodiscard]] auto sqrt(cpp2::impl::in<R> v0) const& -> taylor;

#line 170 "cpp2taylor.h2"
    public: [[nodiscard]] auto log(cpp2::impl::in<R> v0) const& -> taylor;

#line 189 "cpp2taylor.h2"
    public: [[nodiscard]] auto exp(cpp2::impl::in<R> v0) const& -> taylor;

#line 208 "cpp2taylor.h2"
    public: static auto comp_sin_cos(taylor& s, taylor& c, cpp2::impl::in<taylor> u, cpp2::impl::in<R> u0) -> void;

#line 225 "cpp2taylor.h2"
    public: [[nodiscard]] auto sin(cpp2::impl::in<R> v0) const& -> taylor;

#line 235 "cpp2taylor.h2"
    public: [[nodiscard]] auto cos(cpp2::impl::in<R> v0) const& -> taylor;

#line 244 "cpp2taylor.h2"
};

template<typename R, int order> [[nodiscard]] auto to_string(taylor<R,order> const& o) -> std::string;

#line 257 "cpp2taylor.h2"
} // cpp2 namespace

#endif // CPP2_CPP2TAYLOR_H


//=== Cpp2 function definitions =================================================

#line 1 "cpp2taylor.h2"

#line 4 "cpp2taylor.h2"
namespace cpp2 {

#line 9 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(){}
#line 10 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(R const& d1)
        : v{  }{

#line 12 "cpp2taylor.h2"
        CPP2_ASSERT_IN_BOUNDS_LITERAL(v, 0) = d1;
    }
#line 10 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(R const& d1) -> taylor& {
        v = {};

#line 12 "cpp2taylor.h2"
        CPP2_ASSERT_IN_BOUNDS_LITERAL(v, 0) = d1;
        return *this;
#line 13 "cpp2taylor.h2"
    }
#line 14 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(taylor const& that)
                                  : v{ that.v }{}
#line 14 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(taylor const& that) -> taylor& {
                                  v = that.v;
                                  return *this; }
#line 14 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(taylor&& that) noexcept
                                  : v{ std::move(that).v }{}
#line 14 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(taylor&& that) noexcept -> taylor& {
                                  v = std::move(that).v;
                                  return *this; }

#line 16 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(std::initializer_list<R> const& l){
{
auto i{1};

#line 18 "cpp2taylor.h2"
        for ( auto const& cur : l ) {
            set(i, cur);
        }
}
#line 21 "cpp2taylor.h2"
    }
#line 16 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(std::initializer_list<R> const& l) -> taylor& {
        v = {};
{
auto i{1};

#line 18 "cpp2taylor.h2"
        for ( auto const& cur : l ) {
            set(i, cur);
        }
}
        return *this;
#line 21 "cpp2taylor.h2"
    }

#line 25 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator[](cpp2::impl::in<int> k) const& -> R{
        if (cpp2::cpp2_default.is_active() && !([_0 = 1, _1 = k, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }
        R r {CPP2_ASSERT_IN_BOUNDS(v, k - 1)}; 
{
auto i{2};

#line 29 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(i,k); i += 1 ) {
            r *= i;
        }
}
#line 32 "cpp2taylor.h2"
        return r; 
    }

#line 35 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::set(cpp2::impl::in<int> k, cpp2::impl::in<R> value) & -> void{
        if (cpp2::cpp2_default.is_active() && !([_0 = 1, _1 = k, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }
        CPP2_ASSERT_IN_BOUNDS(v, k - 1) = value;
{
auto i{2};

#line 40 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(i,k); i += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(v, k - 1)),i);
        }
}
#line 43 "cpp2taylor.h2"
    }

#line 47 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::get(cpp2::impl::in<int> i, cpp2::impl::in<R> v0) const& -> R{
        if (i == 0) {
            return v0; 
        }
        else {if (cpp2::impl::cmp_greater(i,dim)) {
            return 0.0; 
        }}

        return CPP2_ASSERT_IN_BOUNDS(v, i - 1); 
    }

#line 59 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator+=(cpp2::impl::in<taylor> o) & -> auto&&{
        (*this) = (*this) + o;
        return (*this); 
    }

#line 65 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator-=(cpp2::impl::in<taylor> o) & -> auto&&{
        (*this) = (*this) - o;
        return (*this); 
    }

#line 71 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator+(cpp2::impl::in<taylor> o) const& -> taylor{
        return add(o, 0.0, 0.0); // Primal values are not required.
    }

#line 76 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator-(cpp2::impl::in<taylor> o) const& -> taylor{
        return sub(o, 0.0, 0.0); // Primal values are not required.
    }

#line 81 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator+() const& -> taylor{
        return (*this); 
    }

#line 86 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator-() const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 90 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = -CPP2_ASSERT_IN_BOUNDS(v, k - 1);
        }
}

#line 94 "cpp2taylor.h2"
        return r; 
    }

#line 97 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::add(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 101 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0) + CPP2_UFCS(get)(o, k, o0);
        }
}

#line 105 "cpp2taylor.h2"
        return r; 
    }

#line 108 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sub(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 112 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0) - CPP2_UFCS(get)(o, k, o0);
        }
}

#line 116 "cpp2taylor.h2"
        return r; 
    }

#line 119 "cpp2taylor.h2"
    template <typename R, int dim> template<int dim_o> [[nodiscard]] auto taylor<R,dim>::mul(taylor<R,dim_o> const& o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor<R,std::max(dim, dim_o)>{
        int constexpr dim_r{ std::max(dim, dim_o) };
        taylor<R,dim_r> r {}; 
{
auto k{1};

#line 124 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim_r); k += 1 ) {
{
auto j{0};

#line 126 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) += get(j, v0) * o.get(k - j, o0);
            }
}
#line 129 "cpp2taylor.h2"
        }
}
#line 130 "cpp2taylor.h2"
        return r; 
    }

#line 133 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::div(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
        R r0 {v0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(v0),o0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),o0)}; 
{
auto k{1};

#line 140 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0);
{
auto j{0};

#line 143 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= CPP2_UFCS(get)(r, j, r0) * o.get(k - j, o0);
            }
}
#line 146 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor;
        }
}
#line 148 "cpp2taylor.h2"
        return r; 
    }

#line 151 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sqrt(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::sqrt(v0)}; 

        R factor {0.5 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(0.5),r0)}; 
{
auto k{1};

#line 158 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0);
{
auto j{1};

#line 161 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= r.get(j, r0) * r.get(k - j, r0);
            }
}
#line 164 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor;
        }
}

#line 167 "cpp2taylor.h2"
        return r; 
    }

#line 170 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::log(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::log(v0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),v0)}; 
{
auto k{1};

#line 177 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = k * get(k, v0);
{
auto j{1};

#line 180 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= j * get(k - j, v0) * r.get(j, r0);
            }
}
#line 183 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(factor),k);
        }
}

#line 186 "cpp2taylor.h2"
        return r; 
    }

#line 189 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::exp(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::exp(v0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),v0)}; 
{
auto k{1};

#line 196 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{1};

#line 198 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) += j * r.get(k - j, r0) * get(j, v0);
            }
}
#line 201 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(r.v, k - 1)),k);
        }
}

#line 204 "cpp2taylor.h2"
        return r; 
    }

#line 208 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::comp_sin_cos(taylor& s, taylor& c, cpp2::impl::in<taylor> u, cpp2::impl::in<R> u0) -> void{
        R s0 {std::sin(u0)}; 
        R c0 {std::cos(u0)}; 
{
auto k{1};

#line 213 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{1};

#line 215 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(s.v, k - 1) += j * u.get(j, u0) * CPP2_UFCS(get)(c, k - j, c0);
                CPP2_ASSERT_IN_BOUNDS(c.v, k - 1) -= j * u.get(j, u0) * CPP2_UFCS(get)(s, k - j, s0);
            }
}
#line 219 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(s.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(s.v, k - 1)),k);
            CPP2_ASSERT_IN_BOUNDS(c.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(c.v, k - 1)),k);
        }
}
#line 222 "cpp2taylor.h2"
    }

#line 225 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sin(cpp2::impl::in<R> v0) const& -> taylor{
        taylor t {}; 
        taylor r {}; 

        comp_sin_cos(r, t, (*this), v0);
        static_cast<void>(cpp2::move(t));

        return r; 
    }

#line 235 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::cos(cpp2::impl::in<R> v0) const& -> taylor{
        taylor t {}; 
        taylor r {}; 

        comp_sin_cos(t, r, (*this), v0);
        static_cast<void>(cpp2::move(t));

        return r; 
    }

#line 246 "cpp2taylor.h2"
template<typename R, int order> [[nodiscard]] auto to_string(taylor<R,order> const& o) -> std::string{
    std::string r {"("}; 
{
auto i{1};

#line 249 "cpp2taylor.h2"
    for( ; cpp2::impl::cmp_less_eq(i,order); i += 1 ) {
        r += " " + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(o, i)) + "";
    }
}
#line 252 "cpp2taylor.h2"
    r += " )";

    return r; 
}

}

#endif

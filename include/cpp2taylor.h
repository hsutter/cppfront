
#ifndef CPP2TAYLOR_H_CPP2
#define CPP2TAYLOR_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "cpp2taylor.h2"

#line 4 "cpp2taylor.h2"
namespace cpp2 {

template<typename R, int dim> class taylor;
    

#line 242 "cpp2taylor.h2"
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "cpp2taylor.h2"
#ifndef CPP2_CPP2TAYLOR_H
#define CPP2_CPP2TAYLOR_H

#line 4 "cpp2taylor.h2"
namespace cpp2 {

template<typename R, int dim> class taylor {
    private: std::array<R,dim> v {}; 

    public: explicit taylor();
    public: taylor(R const& d1);
#line 10 "cpp2taylor.h2"
    public: auto operator=(R const& d1) -> taylor& ;

#line 13 "cpp2taylor.h2"
    public: taylor(taylor const& that);
#line 13 "cpp2taylor.h2"
    public: auto operator=(taylor const& that) -> taylor& ;
#line 13 "cpp2taylor.h2"
    public: taylor(taylor&& that) noexcept;
#line 13 "cpp2taylor.h2"
    public: auto operator=(taylor&& that) noexcept -> taylor& ;

    public: taylor(std::initializer_list<R> const& l);
#line 15 "cpp2taylor.h2"
    public: auto operator=(std::initializer_list<R> const& l) -> taylor& ;

#line 22 "cpp2taylor.h2"
    // C++ interface

    public: [[nodiscard]] auto operator[](cpp2::impl::in<int> k) const& -> R;

#line 34 "cpp2taylor.h2"
    public: auto set(cpp2::impl::in<int> k, cpp2::impl::in<R> value) & -> void;

#line 44 "cpp2taylor.h2"
    // C++2 interface / AD interface

    public: [[nodiscard]] auto get(cpp2::impl::in<int> i, cpp2::impl::in<R> v0) const& -> R;

#line 56 "cpp2taylor.h2"
    // Overload for simple handling of connected adds.
    public: [[nodiscard]] auto operator+(cpp2::impl::in<taylor> o) const& -> taylor;

#line 61 "cpp2taylor.h2"
    // Overload for simple handling of connected minuses.
    public: [[nodiscard]] auto operator-(cpp2::impl::in<taylor> o) const& -> taylor;

#line 66 "cpp2taylor.h2"
    // Overload for simple handling of prefix +.
    public: [[nodiscard]] auto operator+() const& -> taylor;

#line 71 "cpp2taylor.h2"
    // Overload for simple handling of prefix -.
    public: [[nodiscard]] auto operator-() const& -> taylor;

#line 83 "cpp2taylor.h2"
    public: [[nodiscard]] auto add(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 94 "cpp2taylor.h2"
    public: [[nodiscard]] auto sub(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 105 "cpp2taylor.h2"
    public: [[nodiscard]] auto mul(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 118 "cpp2taylor.h2"
    public: [[nodiscard]] auto div(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 136 "cpp2taylor.h2"
    public: [[nodiscard]] auto sqrt(cpp2::impl::in<R> v0) const& -> taylor;

#line 155 "cpp2taylor.h2"
    public: [[nodiscard]] auto log(cpp2::impl::in<R> v0) const& -> taylor;

#line 174 "cpp2taylor.h2"
    public: [[nodiscard]] auto exp(cpp2::impl::in<R> v0) const& -> taylor;

#line 193 "cpp2taylor.h2"
    public: static auto comp_sin_cos(taylor& s, taylor& c, cpp2::impl::in<taylor> u, cpp2::impl::in<R> u0) -> void;

#line 210 "cpp2taylor.h2"
    public: [[nodiscard]] auto sin(cpp2::impl::in<R> v0) const& -> taylor;

#line 220 "cpp2taylor.h2"
    public: [[nodiscard]] auto cos(cpp2::impl::in<R> v0) const& -> taylor;

#line 229 "cpp2taylor.h2"
};

template<typename R, int order> [[nodiscard]] auto to_string(taylor<R,order> const& o) -> std::string;

#line 242 "cpp2taylor.h2"
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
        : v{ d1 }{

#line 12 "cpp2taylor.h2"
    }
#line 10 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(R const& d1) -> taylor& {
        v = d1;
        return *this;

#line 12 "cpp2taylor.h2"
    }
#line 13 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(taylor const& that)
                                  : v{ that.v }{}
#line 13 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(taylor const& that) -> taylor& {
                                  v = that.v;
                                  return *this; }
#line 13 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(taylor&& that) noexcept
                                  : v{ std::move(that).v }{}
#line 13 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(taylor&& that) noexcept -> taylor& {
                                  v = std::move(that).v;
                                  return *this; }

#line 15 "cpp2taylor.h2"
    template <typename R, int dim> taylor<R,dim>::taylor(std::initializer_list<R> const& l){
{
auto i{1};

#line 17 "cpp2taylor.h2"
        for ( auto const& cur : l ) {
            set(i, cur);
        }
}
#line 20 "cpp2taylor.h2"
    }
#line 15 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::operator=(std::initializer_list<R> const& l) -> taylor& {
        v = {};
{
auto i{1};

#line 17 "cpp2taylor.h2"
        for ( auto const& cur : l ) {
            set(i, cur);
        }
}
        return *this;
#line 20 "cpp2taylor.h2"
    }

#line 24 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator[](cpp2::impl::in<int> k) const& -> R{
        if (cpp2::cpp2_default.is_active() && !([_0 = 1, _1 = k, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }
        R r {CPP2_ASSERT_IN_BOUNDS(v, k - 1)}; 
{
auto i{2};

#line 28 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(i,k); i += 1 ) {
            r *= i;
        }
}
#line 31 "cpp2taylor.h2"
        return r; 
    }

#line 34 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::set(cpp2::impl::in<int> k, cpp2::impl::in<R> value) & -> void{
        if (cpp2::cpp2_default.is_active() && !([_0 = 1, _1 = k, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }
        CPP2_ASSERT_IN_BOUNDS(v, k - 1) = value;
{
auto i{2};

#line 39 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(i,k); i += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(v, k - 1)),i);
        }
}
#line 42 "cpp2taylor.h2"
    }

#line 46 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::get(cpp2::impl::in<int> i, cpp2::impl::in<R> v0) const& -> R{
        if (cpp2::cpp2_default.is_active() && !([_0 = 0, _1 = i, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }

        if (i == 0) {
            return v0; 
        }

        return CPP2_ASSERT_IN_BOUNDS(v, i - 1); 
    }

#line 57 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator+(cpp2::impl::in<taylor> o) const& -> taylor{
        return add(o, 0.0, 0.0); // Primal values are not required.
    }

#line 62 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator-(cpp2::impl::in<taylor> o) const& -> taylor{
        return sub(o, 0.0, 0.0); // Primal values are not required.
    }

#line 67 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator+() const& -> taylor{
        return (*this); 
    }

#line 72 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator-() const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 76 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = -CPP2_ASSERT_IN_BOUNDS(v, k - 1);
        }
}

#line 80 "cpp2taylor.h2"
        return r; 
    }

#line 83 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::add(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 87 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0) + CPP2_UFCS(get)(o, k, o0);
        }
}

#line 91 "cpp2taylor.h2"
        return r; 
    }

#line 94 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sub(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 98 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0) - CPP2_UFCS(get)(o, k, o0);
        }
}

#line 102 "cpp2taylor.h2"
        return r; 
    }

#line 105 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::mul(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 109 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{0};

#line 111 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) += get(j, v0) * o.get(k - j, o0);
            }
}
#line 114 "cpp2taylor.h2"
        }
}
#line 115 "cpp2taylor.h2"
        return r; 
    }

#line 118 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::div(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
        R r0 {v0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(v0),o0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),o0)}; 
{
auto k{1};

#line 125 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0);
{
auto j{0};

#line 128 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= CPP2_UFCS(get)(r, j, r0) * o.get(k - j, o0);
            }
}
#line 131 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor;
        }
}
#line 133 "cpp2taylor.h2"
        return r; 
    }

#line 136 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sqrt(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::sqrt(v0)}; 

        R factor {0.5 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(0.5),r0)}; 
{
auto k{1};

#line 143 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0);
{
auto j{1};

#line 146 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= r.get(j, r0) * r.get(k - j, r0);
            }
}
#line 149 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor;
        }
}

#line 152 "cpp2taylor.h2"
        return r; 
    }

#line 155 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::log(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::log(v0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),v0)}; 
{
auto k{1};

#line 162 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = k * get(k, v0);
{
auto j{1};

#line 165 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= j * get(k - j, v0) * r.get(j, r0);
            }
}
#line 168 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(factor),k);
        }
}

#line 171 "cpp2taylor.h2"
        return r; 
    }

#line 174 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::exp(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::exp(v0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),v0)}; 
{
auto k{1};

#line 181 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{1};

#line 183 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) += j * r.get(k - j, r0) * get(j, v0);
            }
}
#line 186 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(r.v, k - 1)),k);
        }
}

#line 189 "cpp2taylor.h2"
        return r; 
    }

#line 193 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::comp_sin_cos(taylor& s, taylor& c, cpp2::impl::in<taylor> u, cpp2::impl::in<R> u0) -> void{
        R s0 {std::sin(u0)}; 
        R c0 {std::cos(u0)}; 
{
auto k{1};

#line 198 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{1};

#line 200 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(s.v, k - 1) += j * u.get(j, u0) * CPP2_UFCS(get)(c, k - j, c0);
                CPP2_ASSERT_IN_BOUNDS(c.v, k - 1) -= j * u.get(j, u0) * CPP2_UFCS(get)(s, k - j, s0);
            }
}
#line 204 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(s.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(s.v, k - 1)),k);
            CPP2_ASSERT_IN_BOUNDS(c.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(c.v, k - 1)),k);
        }
}
#line 207 "cpp2taylor.h2"
    }

#line 210 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sin(cpp2::impl::in<R> v0) const& -> taylor{
        taylor t {}; 
        taylor r {}; 

        comp_sin_cos(r, t, (*this), v0);
        static_cast<void>(cpp2::move(t));

        return r; 
    }

#line 220 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::cos(cpp2::impl::in<R> v0) const& -> taylor{
        taylor t {}; 
        taylor r {}; 

        comp_sin_cos(t, r, (*this), v0);
        static_cast<void>(cpp2::move(t));

        return r; 
    }

#line 231 "cpp2taylor.h2"
template<typename R, int order> [[nodiscard]] auto to_string(taylor<R,order> const& o) -> std::string{
    std::string r {"("}; 
{
auto i{1};

#line 234 "cpp2taylor.h2"
    for( ; cpp2::impl::cmp_less_eq(i,order); i += 1 ) {
        r += " " + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(o, i)) + "";
    }
}
#line 237 "cpp2taylor.h2"
    r += " )";

    return r; 
}

}

#endif

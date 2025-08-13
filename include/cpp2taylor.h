
#ifndef CPP2TAYLOR_H_CPP2
#define CPP2TAYLOR_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "cpp2taylor.h2"

#line 4 "cpp2taylor.h2"
namespace cpp2 {

template<typename R, int dim> class taylor;
    

#line 192 "cpp2taylor.h2"
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

    // C++ interface

    public: [[nodiscard]] auto operator[](cpp2::impl::in<int> k) const& -> R;

#line 27 "cpp2taylor.h2"
    public: [[nodiscard]] auto operator[](cpp2::impl::in<int> i) & -> auto&&;

#line 32 "cpp2taylor.h2"
    // C++2 interface / AD interface

    public: [[nodiscard]] auto get(cpp2::impl::in<int> i, cpp2::impl::in<R> v0) const& -> R;

#line 44 "cpp2taylor.h2"
    public: [[nodiscard]] auto add(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 55 "cpp2taylor.h2"
    public: [[nodiscard]] auto sub(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 66 "cpp2taylor.h2"
    public: [[nodiscard]] auto mul(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 79 "cpp2taylor.h2"
    public: [[nodiscard]] auto div(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor;

#line 97 "cpp2taylor.h2"
    public: [[nodiscard]] auto sqrt(cpp2::impl::in<R> v0) const& -> taylor;

#line 116 "cpp2taylor.h2"
    public: [[nodiscard]] auto log(cpp2::impl::in<R> v0) const& -> taylor;

#line 135 "cpp2taylor.h2"
    public: [[nodiscard]] auto exp(cpp2::impl::in<R> v0) const& -> taylor;

#line 154 "cpp2taylor.h2"
    public: static auto comp_sin_cos(taylor& s, taylor& c, cpp2::impl::in<taylor> u, cpp2::impl::in<R> u0) -> void;

#line 171 "cpp2taylor.h2"
    public: [[nodiscard]] auto sin(cpp2::impl::in<R> v0) const& -> taylor;

#line 181 "cpp2taylor.h2"
    public: [[nodiscard]] auto cos(cpp2::impl::in<R> v0) const& -> taylor;

#line 190 "cpp2taylor.h2"
};

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

#line 17 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator[](cpp2::impl::in<int> k) const& -> R{
        if (cpp2::cpp2_default.is_active() && !([_0 = 1, _1 = k, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }
        R r {CPP2_ASSERT_IN_BOUNDS(v, k - 1)}; 
{
auto i{2};

#line 21 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(i,k); i += 1 ) {
            r *= i;
        }
}
#line 24 "cpp2taylor.h2"
        return r; 
    }

#line 27 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::operator[](cpp2::impl::in<int> i) & -> auto&&{
        if (cpp2::cpp2_default.is_active() && !([_0 = 1, _1 = 1, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }
        return CPP2_ASSERT_IN_BOUNDS(v, i - 1); 
    }

#line 34 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::get(cpp2::impl::in<int> i, cpp2::impl::in<R> v0) const& -> R{
        if (cpp2::cpp2_default.is_active() && !([_0 = 0, _1 = i, _2 = dim]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less_eq(_1,_2); }()) ) { cpp2::cpp2_default.report_violation(""); }

        if (i == 0) {
            return v0; 
        }

        return CPP2_ASSERT_IN_BOUNDS(v, i - 1); 
    }

#line 44 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::add(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 48 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0) + CPP2_UFCS(get)(o, k, o0);
        }
}

#line 52 "cpp2taylor.h2"
        return r; 
    }

#line 55 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sub(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 59 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0) - CPP2_UFCS(get)(o, k, o0);
        }
}

#line 63 "cpp2taylor.h2"
        return r; 
    }

#line 66 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::mul(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
{
auto k{1};

#line 70 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{0};

#line 72 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) += get(j, v0) * o.get(k - j, o0);
            }
}
#line 75 "cpp2taylor.h2"
        }
}
#line 76 "cpp2taylor.h2"
        return r; 
    }

#line 79 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::div(cpp2::impl::in<taylor> o, cpp2::impl::in<R> v0, cpp2::impl::in<R> o0) const& -> taylor{
        taylor r {}; 
        R r0 {v0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(v0),o0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),o0)}; 
{
auto k{1};

#line 86 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0);
{
auto j{0};

#line 89 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= CPP2_UFCS(get)(r, j, r0) * o.get(k - j, o0);
            }
}
#line 92 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor;
        }
}
#line 94 "cpp2taylor.h2"
        return r; 
    }

#line 97 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sqrt(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::sqrt(v0)}; 

        R factor {0.5 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(0.5),r0)}; 
{
auto k{1};

#line 104 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = get(k, v0);
{
auto j{1};

#line 107 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= r.get(j, r0) * r.get(k - j, r0);
            }
}
#line 110 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor;
        }
}

#line 113 "cpp2taylor.h2"
        return r; 
    }

#line 116 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::log(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::log(v0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),v0)}; 
{
auto k{1};

#line 123 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) = k * get(k, v0);
{
auto j{1};

#line 126 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) -= j * get(k - j, v0) * r.get(j, r0);
            }
}
#line 129 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) *= factor / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(factor),k);
        }
}

#line 132 "cpp2taylor.h2"
        return r; 
    }

#line 135 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::exp(cpp2::impl::in<R> v0) const& -> taylor{
        taylor r {}; 
        R r0 {std::exp(v0)}; 

        R factor {1.0 / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(1.0),v0)}; 
{
auto k{1};

#line 142 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{1};

#line 144 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) += j * r.get(k - j, r0) * get(j, v0);
            }
}
#line 147 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(r.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(r.v, k - 1)),k);
        }
}

#line 150 "cpp2taylor.h2"
        return r; 
    }

#line 154 "cpp2taylor.h2"
    template <typename R, int dim> auto taylor<R,dim>::comp_sin_cos(taylor& s, taylor& c, cpp2::impl::in<taylor> u, cpp2::impl::in<R> u0) -> void{
        R s0 {std::sin(u0)}; 
        R c0 {std::cos(u0)}; 
{
auto k{1};

#line 159 "cpp2taylor.h2"
        for( ; cpp2::impl::cmp_less_eq(k,dim); k += 1 ) {
{
auto j{1};

#line 161 "cpp2taylor.h2"
            for( ; cpp2::impl::cmp_less_eq(j,k); j += 1 ) {
                CPP2_ASSERT_IN_BOUNDS(s.v, k - 1) += j * u.get(j, u0) * CPP2_UFCS(get)(c, k - j, c0);
                CPP2_ASSERT_IN_BOUNDS(c.v, k - 1) -= j * u.get(j, u0) * CPP2_UFCS(get)(s, k - j, s0);
            }
}
#line 165 "cpp2taylor.h2"
            CPP2_ASSERT_IN_BOUNDS(s.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(s.v, k - 1)),k);
            CPP2_ASSERT_IN_BOUNDS(c.v, k - 1) /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(CPP2_ASSERT_IN_BOUNDS(c.v, k - 1)),k);
        }
}
#line 168 "cpp2taylor.h2"
    }

#line 171 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::sin(cpp2::impl::in<R> v0) const& -> taylor{
        taylor t {}; 
        taylor r {}; 

        comp_sin_cos(r, t, (*this), v0);
        static_cast<void>(cpp2::move(t));

        return r; 
    }

#line 181 "cpp2taylor.h2"
    template <typename R, int dim> [[nodiscard]] auto taylor<R,dim>::cos(cpp2::impl::in<R> v0) const& -> taylor{
        taylor t {}; 
        taylor r {}; 

        comp_sin_cos(t, r, (*this), v0);
        static_cast<void>(cpp2::move(t));

        return r; 
    }

#line 192 "cpp2taylor.h2"
}

#endif

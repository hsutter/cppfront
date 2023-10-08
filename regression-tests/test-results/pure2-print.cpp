
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 4 "pure2-print.cpp2"
class outer;


//=== Cpp2 type definitions and function declarations ===========================


//  Exercise the pretty-print visualizer for the various grammar elements

#line 4 "pure2-print.cpp2"
class outer {

    public: template<typename T> 
CPP2_REQUIRES_ (true)
#line 6 "pure2-print.cpp2"
    static const T object_alias;

    public: class mytype final
     {
        protected: [[nodiscard]] static auto f() -> int;

        public: [[nodiscard]] virtual auto g(cpp2::in<int> i) const -> int;
            

#line 29 "pure2-print.cpp2"
        private: [[nodiscard]] static auto h(cpp2::in<std::string> s, std::map<int const,std::string>& m) -> std::string;
            struct values_ret { int offset; std::string name; };



#line 52 "pure2-print.cpp2"
        public: template<typename T> [[nodiscard]] auto values([[maybe_unused]] T const& param2) const& -> values_ret;
            

#line 57 "pure2-print.cpp2"
        public: explicit mytype();

        public: mytype([[maybe_unused]] mytype const& that);

        public: mytype([[maybe_unused]] cpp2::in<int> param2);

        public: static auto variadic(auto const& ...x) -> void
CPP2_REQUIRES_ ((std::is_convertible_v<CPP2_TYPEOF(x), int> && ...))
#line 63 "pure2-print.cpp2"
        ;
    };

    public: static auto test() -> void;
        

#line 84 "pure2-print.cpp2"
    public: template<typename ...Ts> class x {
        private: std::tuple<Ts...> tup {}; 
        public: x() = default;
        public: x(x const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(x const&) -> void = delete;

#line 86 "pure2-print.cpp2"
    };

    public: template<typename ...Args> static auto print(std::ostream& out, Args const& ...args) -> void
CPP2_REQUIRES_ (cpp2::cmp_greater_eq(sizeof(Args)...,0))
#line 88 "pure2-print.cpp2"
    ;
        

#line 92 "pure2-print.cpp2"
    public: template<typename ...Args> [[nodiscard]] static auto all(Args const& ...args) -> bool;
        
    public: outer() = default;
    public: outer(outer const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(outer const&) -> void = delete;


#line 95 "pure2-print.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 6 "pure2-print.cpp2"
    template<typename T> 
requires (true)
#line 6 "pure2-print.cpp2"
    inline CPP2_CONSTEXPR T outer::object_alias = 42;

#line 10 "pure2-print.cpp2"
        [[nodiscard]] auto outer::mytype::f() -> int { return 42;  }

        [[nodiscard]] auto outer::mytype::g(cpp2::in<int> i) const -> int{
            auto s {"string literal"}; 
            int ret {i}; 
            int const* const p {&ret}; 
            if (cpp2::cmp_less(*cpp2::assert_not_null(p),0)) {
                ret = -*cpp2::assert_not_null(std::move(p));
            }
            ret += strlen(s) - 10 + CPP2_UFCS_0(strlen, std::move(s)) * (16 / (3 & 2)) % 3;

            std::map<int const,std::string> m {}; 
            cpp2::assert_in_bounds(m, 0) = cpp2::as_<std::string>("har");
            ret -= CPP2_UFCS_0(length, h("x", m));
            static_cast<void>(std::move(m));

            return ret; 
        }

        [[nodiscard]] auto outer::mytype::h(cpp2::in<std::string> s, std::map<int const,std::string>& m) -> std::string

#line 32 "pure2-print.cpp2"
        {
            cpp2::Default.expects(CPP2_UFCS_0(empty, m) == false || false, "");
            cpp2::Bounds.expects([_0 = 0, _1 = CPP2_UFCS_0(ssize, m), _2 = 100]{ return cpp2::cmp_less(_0,_1) && cpp2::cmp_less(_1,_2); }() && true != false, "");
#line 33 "pure2-print.cpp2"
            auto a {[]() -> void{}}; 
            auto b {[]() -> void{}}; 
            auto c {[]() -> void{}}; 

            for( ; CPP2_UFCS_0(empty, s); a() ) {break; }

            do {} while ( CPP2_UFCS_0(empty, s) && [&]{ b() ; return true; }() );

            for ( [[maybe_unused]] auto const& param1 : m ) {
#line 41 "pure2-print.cpp2"
             { do {goto CONTINUE_41_13; } while (false); c(); } CPP2_CONTINUE_BREAK(41_13) }

#line 43 "pure2-print.cpp2"
            if (cpp2::is(!(CPP2_UFCS_0(empty, s)), (true))) {std::move(a)(); }
            else {if (!(CPP2_UFCS_0(empty, m))) {std::move(b)(); }
            else {std::move(c)(); }}

            cpp2::Default.expects(true, "");

            return [_0 = (s + cpp2::assert_in_bounds(m, 0))]() -> std::string { return _0;  }(); 
        }

        template<typename T> [[nodiscard]] auto outer::mytype::values([[maybe_unused]] T const& param2) const& -> values_ret{
                cpp2::deferred_init<int> offset;
                cpp2::deferred_init<std::string> name;
#line 53 "pure2-print.cpp2"
            offset.construct(53);
            name.construct("plugh");
        return  { std::move(offset.value()), std::move(name.value()) }; }

        outer::mytype::mytype(){}

        outer::mytype::mytype([[maybe_unused]] mytype const& that){}

        outer::mytype::mytype([[maybe_unused]] cpp2::in<int> param2){}

        auto outer::mytype::variadic(auto const& ...x) -> void
requires ((std::is_convertible_v<CPP2_TYPEOF(x), int> && ...))
#line 63 "pure2-print.cpp2"
        {(std::cout << ... << x); }

#line 66 "pure2-print.cpp2"
    auto outer::test() -> void{
        namespace namespace_alias = ::std;

        using type_alias = std::array<int,10>;

        cpp2::i8 const& object_alias_1 = 42;
        auto const& object_alias_2 = 42;

#line 75 "pure2-print.cpp2"
        ::outer::mytype var {}; 
        std::cout << CPP2_UFCS(g, var, 42) << "\n";

        std::cout << [&] () -> namespace_alias::string { auto&& _expr = CPP2_UFCS(g, std::move(var), 42);
            if (cpp2::is(_expr, 43)) { if constexpr( requires{"forty-and-three";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("forty-and-three")),namespace_alias::string> ) return "forty-and-three"; else return namespace_alias::string{}; else return namespace_alias::string{}; }
            else return "default case"; }
        () << "\n";
    }

#line 88 "pure2-print.cpp2"
    template<typename ...Args> auto outer::print(std::ostream& out, Args const& ...args) -> void
requires (cpp2::cmp_greater_eq(sizeof(Args)...,0))
#line 88 "pure2-print.cpp2"
    {
        (out << ... << args);
    }

    template<typename ...Args> [[nodiscard]] auto outer::all(Args const& ...args) -> bool { 
        return (... && args);  }

#line 97 "pure2-print.cpp2"
auto main() -> int{
    outer::test();
}


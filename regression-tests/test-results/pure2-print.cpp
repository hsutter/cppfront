
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-print.cpp2"

#line 6 "pure2-print.cpp2"
class outer;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-print.cpp2"

//  Exercise the pretty-print visualizer for the various grammar elements

#line 4 "pure2-print.cpp2"
extern bool testing_enabled;

class outer {

#line 8 "pure2-print.cpp2"
    public: template<typename T> 
CPP2_REQUIRES_ (true) static const T object_alias;
    public: class mytype final
     {
        protected: [[nodiscard]] static auto f() -> int;

        public: [[nodiscard]] virtual auto g(cpp2::in<int> i) const -> int;

#line 33 "pure2-print.cpp2"
        private: [[nodiscard]] static auto h(cpp2::in<std::string> s, std::map<int const,std::string>& m) -> std::string;
struct values_ret { int offset; std::string name; };



#line 56 "pure2-print.cpp2"
        public: template<typename T> [[nodiscard]] auto values([[maybe_unused]] T const& unnamed_param_2) const& -> values_ret;

#line 61 "pure2-print.cpp2"
        public: explicit mytype();

        public: mytype([[maybe_unused]] mytype const& that);

        public: mytype([[maybe_unused]] cpp2::in<int> unnamed_param_2);

        public: static auto variadic(auto const& ...x) -> void
CPP2_REQUIRES_ ((std::is_convertible_v<CPP2_TYPEOF(x), int> && ...)) ;
#line 68 "pure2-print.cpp2"
    };

    public: static auto test() -> void;

#line 91 "pure2-print.cpp2"
    public: template<typename ...Ts> class x {
        private: std::tuple<Ts...> tup {}; 
        public: x() = default;
        public: x(x const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(x const&) -> void = delete;

#line 93 "pure2-print.cpp2"
    };

    public: template<typename ...Args> static auto print(std::ostream& out, Args const& ...args) -> void
CPP2_REQUIRES_ (cpp2::cmp_greater_eq(sizeof...(Args),0u)) ;

#line 99 "pure2-print.cpp2"
    public: template<typename ...Args> [[nodiscard]] static auto all(Args const& ...args) -> bool;
    public: outer() = default;
    public: outer(outer const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(outer const&) -> void = delete;


#line 102 "pure2-print.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-print.cpp2"

#line 4 "pure2-print.cpp2"
bool testing_enabled {false}; 

#line 8 "pure2-print.cpp2"
    template<typename T> 
requires (true) inline CPP2_CONSTEXPR T outer::object_alias = 42;
#line 9 "pure2-print.cpp2"

#line 12 "pure2-print.cpp2"
        [[nodiscard]] auto outer::mytype::f() -> int { return 42;  }

        [[nodiscard]] auto outer::mytype::g(cpp2::in<int> i) const -> int{
            using namespace ::std;

            auto s {"string literal"}; 
            int ret {i}; 
            int const* const p {&ret}; 
            if (cpp2::cmp_less(*cpp2::assert_not_null(p),0)) {
                ret = -*cpp2::assert_not_null(std::move(p));
            }
            ret += strlen(s) - 10 + CPP2_UFCS(strlen)(std::move(s)) * (16 / (3 & 2)) % 3;

            map<int const,string> m {}; 
            CPP2_ASSERT_IN_BOUNDS(m, 0) = cpp2::as_<string>("har");
            ret -= CPP2_UFCS(length)(h("x", m));
            static_cast<void>(std::move(m));

            return ret; 
        }

        [[nodiscard]] auto outer::mytype::h(cpp2::in<std::string> s, std::map<int const,std::string>& m) -> std::string

#line 36 "pure2-print.cpp2"
        {
            if (cpp2::Default.has_handler() && !(CPP2_UFCS(empty)(m) == false || false) ) { cpp2::Default.report_violation(CPP2_CONTRACT_MSG("message")); }
            if (cpp2::Bounds.has_handler() && testing_enabled && !([_0 = 0, _1 = CPP2_UFCS(ssize)(m), _2 = 100]{ return cpp2::cmp_less(_0,_1) && cpp2::cmp_less(_1,_2); }() && true != false) ) { cpp2::Bounds.report_violation(CPP2_CONTRACT_MSG("size is " + cpp2::to_string(CPP2_UFCS(ssize)(m)))); }
#line 37 "pure2-print.cpp2"
            auto a {[]() mutable -> void{}}; 
            auto b {[]() mutable -> void{}}; 
            auto c {[]() mutable -> void{}}; 

            for( ; CPP2_UFCS(empty)(s); a() ) {break; }

            do {} while ( [&]{ b() ; return true; }() && CPP2_UFCS(empty)(s));

            for ( [[maybe_unused]] auto const& unnamed_param_1 : m ) { { do {goto CONTINUE_45_13; } while (false); c(); } CPP2_CONTINUE_BREAK(45_13) }

#line 47 "pure2-print.cpp2"
            if (cpp2::is(!(CPP2_UFCS(empty)(s)), (true))) {std::move(a)(); }
            else {if (!(CPP2_UFCS(empty)(m))) {std::move(b)(); }
            else {std::move(c)(); }}

            if (cpp2::Default.has_handler() && !(true) ) { cpp2::Default.report_violation(""); }

            return [_0 = (s + CPP2_ASSERT_IN_BOUNDS(m, 0))]() mutable -> std::string { return _0;  }(); 
        }

        template<typename T> [[nodiscard]] auto outer::mytype::values([[maybe_unused]] T const& unnamed_param_2) const& -> values_ret{
                cpp2::deferred_init<int> offset;
                cpp2::deferred_init<std::string> name;
#line 57 "pure2-print.cpp2"
            offset.construct(53);
            name.construct("plugh");
        return  { std::move(offset.value()), std::move(name.value()) }; }

        outer::mytype::mytype(){}

        outer::mytype::mytype([[maybe_unused]] mytype const& that){}

        outer::mytype::mytype([[maybe_unused]] cpp2::in<int> unnamed_param_2){}

        auto outer::mytype::variadic(auto const& ...x) -> void
requires ((std::is_convertible_v<CPP2_TYPEOF(x), int> && ...)) {(std::cout << ... << x); }

#line 70 "pure2-print.cpp2"
    auto outer::test() -> void{
        namespace namespace_alias = ::std;

        using std::array;
        using std::cout;

        using type_alias = array<int,10>;

        cpp2::i8 constexpr object_alias_1 = 42;
        auto constexpr object_alias_2 = 42;

#line 82 "pure2-print.cpp2"
        ::outer::mytype var {}; 
        cout << CPP2_UFCS(g)(var, 42) << "\n";

        cout << [&] () -> namespace_alias::string { auto&& _expr = CPP2_UFCS(g)(std::move(var), 42);
            if (cpp2::is(_expr, 43)) { if constexpr( requires{"forty-and-three";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("forty-and-three")),namespace_alias::string> ) return "forty-and-three"; else return namespace_alias::string{}; else return namespace_alias::string{}; }
            else return "default case"; }
        () << "\n";
    }

#line 95 "pure2-print.cpp2"
    template<typename ...Args> auto outer::print(std::ostream& out, Args const& ...args) -> void
requires (cpp2::cmp_greater_eq(sizeof...(Args),0u)) {
#line 96 "pure2-print.cpp2"
        (out << ... << args);
    }

    template<typename ...Args> [[nodiscard]] auto outer::all(Args const& ...args) -> bool { 
        return (... && args);  }

#line 104 "pure2-print.cpp2"
auto main() -> int{
    outer::test();
}


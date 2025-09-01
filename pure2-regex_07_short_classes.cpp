
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/pure2-regex_07_short_classes.cpp2"

#line 166 "regression-tests/pure2-regex_07_short_classes.cpp2"
class test_tests_07_short_classes;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/pure2-regex_07_short_classes.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 113 "regression-tests/pure2-regex_07_short_classes.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 125 "regression-tests/pure2-regex_07_short_classes.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 166 "regression-tests/pure2-regex_07_short_classes.cpp2"
class test_tests_07_short_classes {

#line 191 "regression-tests/pure2-regex_07_short_classes.cpp2"
  public: auto run() const& -> void;
  public: template<typename CharT> class regex_01_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_01_matcher() = default;
        public: regex_01_matcher(regex_01_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_01_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_01_matcher<char>> regex_01 {}; public: template<typename CharT> class regex_02_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_02_matcher() = default;
        public: regex_02_matcher(regex_02_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_02_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_02_matcher<char>> regex_02 {}; public: template<typename CharT> class regex_03_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_03_matcher() = default;
        public: regex_03_matcher(regex_03_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_03_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_03_matcher<char>> regex_03 {}; public: template<typename CharT> class regex_04_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_04_matcher() = default;
        public: regex_04_matcher(regex_04_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_04_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_04_matcher<char>> regex_04 {}; public: template<typename CharT> class regex_05_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_05_matcher() = default;
        public: regex_05_matcher(regex_05_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_05_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_05_matcher<char>> regex_05 {}; public: template<typename CharT> class regex_06_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_06_matcher() = default;
        public: regex_06_matcher(regex_06_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_06_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_06_matcher<char>> regex_06 {}; public: template<typename CharT> class regex_07_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_07_matcher() = default;
        public: regex_07_matcher(regex_07_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_07_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_07_matcher<char>> regex_07 {}; public: template<typename CharT> class regex_08_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_08_matcher() = default;
        public: regex_08_matcher(regex_08_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_08_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_08_matcher<char>> regex_08 {}; public: template<typename CharT> class regex_09_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_09_matcher() = default;
        public: regex_09_matcher(regex_09_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_09_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_09_matcher<char>> regex_09 {}; public: template<typename CharT> class regex_10_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_10_matcher() = default;
        public: regex_10_matcher(regex_10_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_10_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_10_matcher<char>> regex_10 {}; public: template<typename CharT> class regex_11_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_11_matcher() = default;
        public: regex_11_matcher(regex_11_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_11_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_11_matcher<char>> regex_11 {}; public: template<typename CharT> class regex_12_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_12_matcher() = default;
        public: regex_12_matcher(regex_12_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_12_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_12_matcher<char>> regex_12 {}; public: template<typename CharT> class regex_13_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_13_matcher() = default;
        public: regex_13_matcher(regex_13_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_13_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_13_matcher<char>> regex_13 {}; public: template<typename CharT> class regex_14_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_14_matcher() = default;
        public: regex_14_matcher(regex_14_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_14_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_14_matcher<char>> regex_14 {}; public: template<typename CharT> class regex_15_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_15_matcher() = default;
        public: regex_15_matcher(regex_15_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_15_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_15_matcher<char>> regex_15 {}; public: template<typename CharT> class regex_16_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_16_matcher() = default;
        public: regex_16_matcher(regex_16_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_16_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_16_matcher<char>> regex_16 {}; public: template<typename CharT> class regex_17_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_17_matcher() = default;
        public: regex_17_matcher(regex_17_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_17_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_17_matcher<char>> regex_17 {}; public: template<typename CharT> class regex_18_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_18_matcher() = default;
        public: regex_18_matcher(regex_18_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_18_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_18_matcher<char>> regex_18 {}; public: template<typename CharT> class regex_19_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_19_matcher() = default;
        public: regex_19_matcher(regex_19_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_19_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_19_matcher<char>> regex_19 {}; public: template<typename CharT> class regex_20_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_20_matcher() = default;
        public: regex_20_matcher(regex_20_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_20_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_20_matcher<char>> regex_20 {}; public: template<typename CharT> class regex_21_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_21_matcher() = default;
        public: regex_21_matcher(regex_21_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_21_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_21_matcher<char>> regex_21 {}; public: template<typename CharT> class regex_22_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_22_matcher() = default;
        public: regex_22_matcher(regex_22_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_22_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_22_matcher<char>> regex_22 {}; public: template<typename CharT> class regex_23_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_23_matcher() = default;
        public: regex_23_matcher(regex_23_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_23_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_23_matcher<char>> regex_23 {}; public: template<typename CharT> class regex_24_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: template<typename Iter> [[nodiscard]] static auto entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: [[nodiscard]] constexpr static auto is_start_match() -> bool;
public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_24_matcher() = default;
        public: regex_24_matcher(regex_24_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_24_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_24_matcher<char>> regex_24 {}; 
  public: test_tests_07_short_classes() = default;
  public: test_tests_07_short_classes(test_tests_07_short_classes const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_07_short_classes const&) -> void = delete;


#line 219 "regression-tests/pure2-regex_07_short_classes.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/pure2-regex_07_short_classes.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "regression-tests/pure2-regex_07_short_classes.cpp2"
  std::string result {""}; 

  auto get_next {[_0 = (&resultExpr)](auto const& iter) mutable -> auto{
  auto start {std::distance(CPP2_UFCS(cbegin)((*cpp2::impl::assert_not_null(_0))), iter)}; 
    auto firstDollar {CPP2_UFCS(find)((*cpp2::impl::assert_not_null(_0)), "$", start)}; 
    auto firstAt {CPP2_UFCS(find)((*cpp2::impl::assert_not_null(_0)), "@", cpp2::move(start))}; 

  auto end {std::min(cpp2::move(firstDollar), cpp2::move(firstAt))}; 
  if (end != std::string::npos) {
   return CPP2_UFCS(cbegin)((*cpp2::impl::assert_not_null(_0))) + cpp2::move(end); 
  }
  else {
   return CPP2_UFCS(cend)((*cpp2::impl::assert_not_null(_0))); 
  }
  }}; 
  auto extract_group_and_advance {[](auto& iter) -> auto{
    auto start {iter}; 

    for( ; std::isdigit(*cpp2::impl::assert_not_null(iter)); ++iter ) {}

    return std::stoi(std::string(cpp2::move(start), iter)); 
  }}; 
  auto extract_until {[](auto& iter, cpp2::impl::in<char> to) -> auto{
    auto start {iter}; 

    for( ; (to != *cpp2::impl::assert_not_null(iter)); ++iter ) {}// TODO: Without bracket: error: postfix unary * (dereference) cannot be immediately followed by a (, identifier, or literal - add whitespace before * here if you meant binary * (multiplication)

    return std::string(cpp2::move(start), iter); 
  }}; 

  auto iter {CPP2_UFCS(begin)(resultExpr)}; 

  while( iter != CPP2_UFCS(end)(resultExpr) ) {
    auto next {get_next(iter)}; 

    if (next != iter) {
      result += std::string(iter, next);
    }
    if (next != CPP2_UFCS(end)(resultExpr)) {
      if (*cpp2::impl::assert_not_null(next) == '$') {
        ++next;

        if (*cpp2::impl::assert_not_null(next) == '&') {
          ++next;
          result += CPP2_UFCS(group)(r, 0);
        }
        else {if (*cpp2::impl::assert_not_null(next) == '-' || *cpp2::impl::assert_not_null(next) == '+') {
          auto is_start {*cpp2::impl::assert_not_null(next) == '-'}; 
          ++next;
          if (*cpp2::impl::assert_not_null(next) == '{') {
            ++next; // Skip {
            auto group {extract_until(next, '}')}; 
            ++next; // Skip }
            result += CPP2_UFCS(group)(r, cpp2::move(group));
          }
          else {if (*cpp2::impl::assert_not_null(next) == '[') {
            ++next; // Skip [
            auto group {extract_group_and_advance(next)}; 
            ++next; // Skip ]

            if (cpp2::move(is_start)) {
              result += std::to_string(CPP2_UFCS(group_start)(r, cpp2::move(group)));
            }
            else {
              result += std::to_string(CPP2_UFCS(group_end)(r, cpp2::move(group)));
            }
          }
          else {
            // Return max group
            result += CPP2_UFCS(group)(r, CPP2_UFCS(group_number)(r) - 1);
          }}
        }
        else {if (std::isdigit(*cpp2::impl::assert_not_null(next))) {
          auto group {extract_group_and_advance(next)}; 
          result += CPP2_UFCS(group)(r, cpp2::move(group));
        }
        else {
          std::cerr << "Not implemented";
        }}}
      }
      else {if (*cpp2::impl::assert_not_null(next) == '@') {
        ++next;

        if (*cpp2::impl::assert_not_null(next) == '-' || *cpp2::impl::assert_not_null(next) == '+') {
          auto i {0}; 
          for( ; cpp2::impl::cmp_less(i,cpp2::unchecked_narrow<int>(CPP2_UFCS(group_number)(r))); ++i ) {
            auto pos {0}; 
            if (*cpp2::impl::assert_not_null(next) == '-') {
              pos = CPP2_UFCS(group_start)(r, i);
            }
            else {
              pos = CPP2_UFCS(group_end)(r, i);
            }
            result +=  std::to_string(cpp2::move(pos));
          }
          ++next;
        }
        else {
          std::cerr << "Not implemented";
        }
      }
      else {
        std::cerr << "Not implemented.";
      }}
    }
    iter = cpp2::move(next);
  }

  return result; 
}

#line 113 "regression-tests/pure2-regex_07_short_classes.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string
{
  str = cpp2::string_util::replace_all(str, "\a", "\\a");
  str = cpp2::string_util::replace_all(str, "\f", "\\f");
  str = cpp2::string_util::replace_all(str, "\x1b", "\\e");
  str = cpp2::string_util::replace_all(str, "\n", "\\n");
  str = cpp2::string_util::replace_all(str, "\r", "\\r");
  str = cpp2::string_util::replace_all(str, "\t", "\\t");

  return cpp2::move(str); 
}

#line 125 "regression-tests/pure2-regex_07_short_classes.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void{

  std::string warning {""}; 
  if (CPP2_UFCS(to_string)(regex) != regex_str) {
    warning = "Warning: Parsed regex does not match.";
  }

  std::string status {"OK"}; 

  auto r {CPP2_UFCS(search)(regex, str)}; 

  if ("y" == kind || "yM" == kind || "yS" == kind || "yB" == kind) {
    if (!(r.matched)) {
      status = "Failure: Regex should apply.";
    }
    else {
      // Have a match check the result

      auto result {create_result(resultExpr, cpp2::move(r))}; 

      if (result != resultExpected) {
        status = "Failure: Result is wrong. (is: " + cpp2::to_string(sanitize(cpp2::move(result))) + ")";
      }
    }
  }
  else {if ("n" == kind) {
    if (r.matched) {
      status = "Failure: Regex should not apply. Result is '" + cpp2::to_string(CPP2_UFCS(group)(cpp2::move(r), 0)) + "'";
    }
  }else {
    status = "Unknown kind '" + cpp2::to_string(kind) + "'";
  }}

  if (!(CPP2_UFCS(empty)(warning))) {
    warning += " ";
  }
  std::cout << "" + cpp2::to_string(id) + "_" + cpp2::to_string(kind) + ": " + cpp2::to_string(cpp2::move(status)) + " " + cpp2::to_string(cpp2::move(warning)) + "regex: " + cpp2::to_string(regex_str) + " parsed_regex: " + cpp2::to_string(CPP2_UFCS(to_string)(regex)) + " str: " + cpp2::to_string(sanitize(str)) + " result_expr: " + cpp2::to_string(resultExpr) + " expected_results " + cpp2::to_string(sanitize(resultExpected)) + "" << std::endl;
}

#line 191 "regression-tests/pure2-regex_07_short_classes.cpp2"
  auto test_tests_07_short_classes::run() const& -> void{
    std::cout << "Running tests_07_short_classes:" << std::endl;
    test(regex_01, "01", R"(\w)", "a", "y", R"(-)", "-");
    test(regex_02, "02", R"(\w)", "-", "n", R"(-)", "-");
    test(regex_03, "03", R"(\W)", "a", "n", R"(-)", "-");
    test(regex_04, "04", R"(\W)", "-", "y", R"(-)", "-");
    test(regex_05, "05", R"(a\sb)", "a b", "y", R"(-)", "-");
    test(regex_06, "06", R"(a\sb)", "a-b", "n", R"(-)", "-");
    test(regex_07, "07", R"(a\Sb)", "a b", "n", R"(-)", "-");
    test(regex_08, "08", R"(a\Sb)", "a-b", "y", R"(-)", "-");
    test(regex_09, "09", R"(\d)", "1", "y", R"(-)", "-");
    test(regex_10, "10", R"(\d)", "-", "n", R"(-)", "-");
    test(regex_11, "11", R"(\D)", "1", "n", R"(-)", "-");
    test(regex_12, "12", R"(\D)", "-", "y", R"(-)", "-");
    test(regex_13, "13", R"([\w])", "a", "y", R"(-)", "-");
    test(regex_14, "14", R"([\w])", "-", "n", R"(-)", "-");
    test(regex_15, "15", R"([\W])", "a", "n", R"(-)", "-");
    test(regex_16, "16", R"([\W])", "-", "y", R"(-)", "-");
    test(regex_17, "17", R"(a[\s]b)", "a b", "y", R"(-)", "-");
    test(regex_18, "18", R"(a[\s]b)", "a-b", "n", R"(-)", "-");
    test(regex_19, "19", R"(a[\S]b)", "a b", "n", R"(-)", "-");
    test(regex_20, "20", R"(a[\S]b)", "a-b", "y", R"(-)", "-");
    test(regex_21, "21", R"([\d])", "1", "y", R"(-)", "-");
    test(regex_22, "22", R"([\d])", "-", "n", R"(-)", "-");
    test(regex_23, "23", R"([\D])", "1", "n", R"(-)", "-");
    test(regex_24, "24", R"([\D])", "-", "y", R"(-)", "-");
    std::cout << std::endl;
  }




  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_01_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_word<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_01_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_01_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_01_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_01_matcher<CharT>::to_string() -> std::string{return R"(\w)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_02_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_word<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_02_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_02_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_02_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_02_matcher<CharT>::to_string() -> std::string{return R"(\w)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_03_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_not_word<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_03_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_03_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_03_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_03_matcher<CharT>::to_string() -> std::string{return R"(\W)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_04_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_not_word<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_04_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_04_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_04_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_04_matcher<CharT>::to_string() -> std::string{return R"(\W)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_05_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::named_class_space<char,false>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_05_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_05_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_05_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_05_matcher<CharT>::to_string() -> std::string{return R"(a\sb)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_06_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::named_class_space<char,false>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_06_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_06_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_06_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_06_matcher<CharT>::to_string() -> std::string{return R"(a\sb)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_07_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::named_class_not_space<char,false>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_07_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_07_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_07_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_07_matcher<CharT>::to_string() -> std::string{return R"(a\Sb)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_08_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::named_class_not_space<char,false>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_08_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_08_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_08_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_08_matcher<CharT>::to_string() -> std::string{return R"(a\Sb)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_09_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_digits<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_09_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_09_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_09_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_09_matcher<CharT>::to_string() -> std::string{return R"(\d)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_10_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_digits<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_10_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_10_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_10_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_10_matcher<CharT>::to_string() -> std::string{return R"(\d)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_11_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_not_digits<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_11_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_11_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_11_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_11_matcher<CharT>::to_string() -> std::string{return R"(\D)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_12_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::named_class_not_digits<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_12_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_12_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_12_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_12_matcher<CharT>::to_string() -> std::string{return R"(\D)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_13_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_word_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_13_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_13_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_13_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_13_matcher<CharT>::to_string() -> std::string{return R"([\w])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_14_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_word_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_14_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_14_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_14_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_14_matcher<CharT>::to_string() -> std::string{return R"([\w])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_15_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_not_word_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_15_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_15_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_15_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_15_matcher<CharT>::to_string() -> std::string{return R"([\W])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_16_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_not_word_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_16_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_16_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_16_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_16_matcher<CharT>::to_string() -> std::string{return R"([\W])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_17_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_space_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_17_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_17_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_17_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_17_matcher<CharT>::to_string() -> std::string{return R"(a[\s]b)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_18_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_space_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_18_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_18_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_18_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_18_matcher<CharT>::to_string() -> std::string{return R"(a[\s]b)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_19_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_not_space_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_19_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_19_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_19_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_19_matcher<CharT>::to_string() -> std::string{return R"(a[\S]b)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_20_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_not_space_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_1 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_20_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_20_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_20_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_20_matcher<CharT>::to_string() -> std::string{return R"(a[\S]b)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_21_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_digits_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_21_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_21_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_21_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_21_matcher<CharT>::to_string() -> std::string{return R"([\d])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_22_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_digits_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_22_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_22_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_22_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_22_matcher<CharT>::to_string() -> std::string{return R"([\d])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_23_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_not_digits_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_23_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_23_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_23_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_23_matcher<CharT>::to_string() -> std::string{return R"([\D])"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_24_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::short_not_digits_class<char>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_07_short_classes::regex_24_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_24_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_07_short_classes::regex_24_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_07_short_classes::regex_24_matcher<CharT>::to_string() -> std::string{return R"([\D])"; }


#line 220 "regression-tests/pure2-regex_07_short_classes.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_07_short_classes());
}


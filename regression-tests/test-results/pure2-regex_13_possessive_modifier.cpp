
#define CPP2_IMPORT_STD          Yes
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex_13_possessive_modifier.cpp2"

#line 165 "pure2-regex_13_possessive_modifier.cpp2"
class test_tests_13_possessive_modifier;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex_13_possessive_modifier.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 112 "pure2-regex_13_possessive_modifier.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 124 "pure2-regex_13_possessive_modifier.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 165 "pure2-regex_13_possessive_modifier.cpp2"
class test_tests_13_possessive_modifier {

#line 214 "pure2-regex_13_possessive_modifier.cpp2"
  public: auto run() const& -> void;
  public: class regex_01_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_01_matcher() = default;
        public: regex_01_matcher(regex_01_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_01_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_01_matcher> regex_01 {}; public: class regex_02_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_02_matcher() = default;
        public: regex_02_matcher(regex_02_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_02_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_02_matcher> regex_02 {}; public: class regex_03_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_03_matcher() = default;
        public: regex_03_matcher(regex_03_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_03_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_03_matcher> regex_03 {}; public: class regex_04_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_04_matcher() = default;
        public: regex_04_matcher(regex_04_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_04_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_04_matcher> regex_04 {}; public: class regex_05_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_05_matcher() = default;
        public: regex_05_matcher(regex_05_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_05_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_05_matcher> regex_05 {}; public: class regex_06_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_06_matcher() = default;
        public: regex_06_matcher(regex_06_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_06_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_06_matcher> regex_06 {}; public: class regex_07_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_07_matcher() = default;
        public: regex_07_matcher(regex_07_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_07_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_07_matcher> regex_07 {}; public: class regex_08_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_08_matcher() = default;
        public: regex_08_matcher(regex_08_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_08_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_08_matcher> regex_08 {}; public: class regex_09_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_09_matcher() = default;
        public: regex_09_matcher(regex_09_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_09_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_09_matcher> regex_09 {}; public: class regex_10_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_10_matcher() = default;
        public: regex_10_matcher(regex_10_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_10_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_10_matcher> regex_10 {}; public: class regex_11_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_11_matcher() = default;
        public: regex_11_matcher(regex_11_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_11_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_11_matcher> regex_11 {}; public: class regex_12_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_12_matcher() = default;
        public: regex_12_matcher(regex_12_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_12_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_12_matcher> regex_12 {}; public: class regex_13_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_13_matcher() = default;
        public: regex_13_matcher(regex_13_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_13_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_13_matcher> regex_13 {}; public: class regex_14_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_14_matcher() = default;
        public: regex_14_matcher(regex_14_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_14_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_14_matcher> regex_14 {}; public: class regex_15_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_15_matcher() = default;
        public: regex_15_matcher(regex_15_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_15_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_15_matcher> regex_15 {}; public: class regex_16_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_16_matcher() = default;
        public: regex_16_matcher(regex_16_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_16_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_16_matcher> regex_16 {}; public: class regex_17_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_17_matcher() = default;
        public: regex_17_matcher(regex_17_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_17_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_17_matcher> regex_17 {}; public: class regex_18_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_18_matcher() = default;
        public: regex_18_matcher(regex_18_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_18_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_18_matcher> regex_18 {}; public: class regex_19_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_19_matcher() = default;
        public: regex_19_matcher(regex_19_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_19_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_19_matcher> regex_19 {}; public: class regex_20_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_20_matcher() = default;
        public: regex_20_matcher(regex_20_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_20_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_20_matcher> regex_20 {}; public: class regex_21_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_21_matcher() = default;
        public: regex_21_matcher(regex_21_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_21_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_21_matcher> regex_21 {}; public: class regex_22_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_22_matcher() = default;
        public: regex_22_matcher(regex_22_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_22_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_22_matcher> regex_22 {}; public: class regex_23_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_23_matcher() = default;
        public: regex_23_matcher(regex_23_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_23_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_23_matcher> regex_23 {}; public: class regex_24_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_24_matcher() = default;
        public: regex_24_matcher(regex_24_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_24_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_24_matcher> regex_24 {}; public: class regex_25_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_25_matcher() = default;
        public: regex_25_matcher(regex_25_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_25_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_25_matcher> regex_25 {}; public: class regex_26_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_26_matcher() = default;
        public: regex_26_matcher(regex_26_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_26_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_26_matcher> regex_26 {}; public: class regex_27_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_27_matcher() = default;
        public: regex_27_matcher(regex_27_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_27_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_27_matcher> regex_27 {}; public: class regex_28_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_28_matcher() = default;
        public: regex_28_matcher(regex_28_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_28_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_28_matcher> regex_28 {}; public: class regex_29_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_29_matcher() = default;
        public: regex_29_matcher(regex_29_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_29_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_29_matcher> regex_29 {}; public: class regex_30_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_30_matcher() = default;
        public: regex_30_matcher(regex_30_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_30_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_30_matcher> regex_30 {}; public: class regex_31_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_31_matcher() = default;
        public: regex_31_matcher(regex_31_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_31_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_31_matcher> regex_31 {}; public: class regex_32_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_32_matcher() = default;
        public: regex_32_matcher(regex_32_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_32_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_32_matcher> regex_32 {}; public: class regex_33_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_33_matcher() = default;
        public: regex_33_matcher(regex_33_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_33_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_33_matcher> regex_33 {}; public: class regex_34_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_34_matcher() = default;
        public: regex_34_matcher(regex_34_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_34_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_34_matcher> regex_34 {}; public: class regex_35_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_35_matcher() = default;
        public: regex_35_matcher(regex_35_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_35_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_35_matcher> regex_35 {}; public: class regex_36_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_36_matcher() = default;
        public: regex_36_matcher(regex_36_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_36_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_36_matcher> regex_36 {}; public: class regex_37_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_37_matcher() = default;
        public: regex_37_matcher(regex_37_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_37_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_37_matcher> regex_37 {}; public: class regex_38_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_38_matcher() = default;
        public: regex_38_matcher(regex_38_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_38_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_38_matcher> regex_38 {}; public: class regex_39_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_39_matcher() = default;
        public: regex_39_matcher(regex_39_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_39_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_39_matcher> regex_39 {}; public: class regex_40_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_40_matcher() = default;
        public: regex_40_matcher(regex_40_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_40_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_40_matcher> regex_40 {}; public: class regex_41_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_41_matcher() = default;
        public: regex_41_matcher(regex_41_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_41_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_41_matcher> regex_41 {}; public: class regex_42_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_42_matcher() = default;
        public: regex_42_matcher(regex_42_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_42_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_42_matcher> regex_42 {}; public: class regex_43_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_43_matcher() = default;
        public: regex_43_matcher(regex_43_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_43_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_43_matcher> regex_43 {}; public: class regex_44_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_44_matcher() = default;
        public: regex_44_matcher(regex_44_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_44_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_44_matcher> regex_44 {}; public: class regex_45_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_45_matcher() = default;
        public: regex_45_matcher(regex_45_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_45_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_45_matcher> regex_45 {}; public: class regex_46_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_46_matcher() = default;
        public: regex_46_matcher(regex_46_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_46_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_46_matcher> regex_46 {}; public: class regex_47_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_47_matcher() = default;
        public: regex_47_matcher(regex_47_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_47_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_47_matcher> regex_47 {}; public: class regex_48_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_48_matcher() = default;
        public: regex_48_matcher(regex_48_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_48_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_48_matcher> regex_48 {}; 
  public: test_tests_13_possessive_modifier() = default;
  public: test_tests_13_possessive_modifier(test_tests_13_possessive_modifier const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_13_possessive_modifier const&) -> void = delete;


#line 266 "pure2-regex_13_possessive_modifier.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex_13_possessive_modifier.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "pure2-regex_13_possessive_modifier.cpp2"
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

#line 112 "pure2-regex_13_possessive_modifier.cpp2"
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

#line 124 "pure2-regex_13_possessive_modifier.cpp2"
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

#line 214 "pure2-regex_13_possessive_modifier.cpp2"
  auto test_tests_13_possessive_modifier::run() const& -> void{
    std::cout << "Running tests_13_possessive_modifier:" << std::endl;
    test(regex_01, "01", R"(a++a)", "aaaaa", "n", R"(-)", "-");
    test(regex_02, "02", R"(a*+a)", "aaaaa", "n", R"(-)", "-");
    test(regex_03, "03", R"(a{1,5}+a)", "aaaaa", "n", R"(-)", "-");
    test(regex_04, "04", R"(a?+a)", "ab", "n", R"(-)", "-");
    test(regex_05, "05", R"(a++b)", "aaaaab", "y", R"($&)", "aaaaab");
    test(regex_06, "06", R"(a*+b)", "aaaaab", "y", R"($&)", "aaaaab");
    test(regex_07, "07", R"(a{1,5}+b)", "aaaaab", "y", R"($&)", "aaaaab");
    test(regex_08, "08", R"(a?+b)", "ab", "y", R"($&)", "ab");
    test(regex_09, "09", R"(fooa++a)", "fooaaaaa", "n", R"(-)", "-");
    test(regex_10, "10", R"(fooa*+a)", "fooaaaaa", "n", R"(-)", "-");
    test(regex_11, "11", R"(fooa{1,5}+a)", "fooaaaaa", "n", R"(-)", "-");
    test(regex_12, "12", R"(fooa?+a)", "fooab", "n", R"(-)", "-");
    test(regex_13, "13", R"(fooa++b)", "fooaaaaab", "y", R"($&)", "fooaaaaab");
    test(regex_14, "14", R"(fooa*+b)", "fooaaaaab", "y", R"($&)", "fooaaaaab");
    test(regex_15, "15", R"(fooa{1,5}+b)", "fooaaaaab", "y", R"($&)", "fooaaaaab");
    test(regex_16, "16", R"(fooa?+b)", "fooab", "y", R"($&)", "fooab");
    test(regex_17, "17", R"((aA)++(aA))", "aAaAaAaAaA", "n", R"(-)", "aAaAaAaAaA");
    test(regex_18, "18", R"((aA|bB)++(aA|bB))", "aAaAbBaAbB", "n", R"(-)", "aAaAbBaAbB");
    test(regex_19, "19", R"((aA)*+(aA))", "aAaAaAaAaA", "n", R"(-)", "aAaAaAaAaA");
    test(regex_20, "20", R"((aA|bB)*+(aA|bB))", "aAaAbBaAaA", "n", R"(-)", "aAaAbBaAaA");
    test(regex_21, "21", R"((aA){1,5}+(aA))", "aAaAaAaAaA", "n", R"(-)", "aAaAaAaAaA");
    test(regex_22, "22", R"((aA|bB){1,5}+(aA|bB))", "aAaAbBaAaA", "n", R"(-)", "aAaAbBaAaA");
    test(regex_23, "23", R"((aA)?+(aA))", "aAb", "n", R"(-)", "aAb");
    test(regex_24, "24", R"((aA|bB)?+(aA|bB))", "bBb", "n", R"(-)", "bBb");
    test(regex_25, "25", R"((aA)++b)", "aAaAaAaAaAb", "y", R"($&)", "aAaAaAaAaAb");
    test(regex_26, "26", R"((aA|bB)++b)", "aAbBaAaAbBb", "y", R"($&)", "aAbBaAaAbBb");
    test(regex_27, "27", R"((aA)*+b)", "aAaAaAaAaAb", "y", R"($&)", "aAaAaAaAaAb");
    test(regex_28, "28", R"((aA|bB)*+b)", "bBbBbBbBbBb", "y", R"($&)", "bBbBbBbBbBb");
    test(regex_29, "29", R"((aA){1,5}+b)", "aAaAaAaAaAb", "y", R"($&)", "aAaAaAaAaAb");
    test(regex_30, "30", R"((aA|bB){1,5}+b)", "bBaAbBaAbBb", "y", R"($&)", "bBaAbBaAbBb");
    test(regex_31, "31", R"((aA)?+b)", "aAb", "y", R"($&)", "aAb");
    test(regex_32, "32", R"((aA|bB)?+b)", "bBb", "y", R"($&)", "bBb");
    test(regex_33, "33", R"(foo(aA)++(aA))", "fooaAaAaAaAaA", "n", R"(-)", "fooaAaAaAaAaA");
    test(regex_34, "34", R"(foo(aA|bB)++(aA|bB))", "foobBbBbBaAaA", "n", R"(-)", "foobBbBbBaAaA");
    test(regex_35, "35", R"(foo(aA)*+(aA))", "fooaAaAaAaAaA", "n", R"(-)", "fooaAaAaAaAaA");
    test(regex_36, "36", R"(foo(aA|bB)*+(aA|bB))", "foobBaAbBaAaA", "n", R"(-)", "foobBaAbBaAaA");
    test(regex_37, "37", R"(foo(aA){1,5}+(aA))", "fooaAaAaAaAaA", "n", R"(-)", "fooaAaAaAaAaA");
    test(regex_38, "38", R"(foo(aA|bB){1,5}+(aA|bB))", "fooaAbBbBaAaA", "n", R"(-)", "fooaAbBbBaAaA");
    test(regex_39, "39", R"(foo(aA)?+(aA))", "fooaAb", "n", R"(-)", "fooaAb");
    test(regex_40, "40", R"(foo(aA|bB)?+(aA|bB))", "foobBb", "n", R"(-)", "foobBb");
    test(regex_41, "41", R"(foo(aA)++b)", "fooaAaAaAaAaAb", "y", R"($&)", "fooaAaAaAaAaAb");
    test(regex_42, "42", R"(foo(aA|bB)++b)", "foobBaAbBaAbBb", "y", R"($&)", "foobBaAbBaAbBb");
    test(regex_43, "43", R"(foo(aA)*+b)", "fooaAaAaAaAaAb", "y", R"($&)", "fooaAaAaAaAaAb");
    test(regex_44, "44", R"(foo(aA|bB)*+b)", "foobBbBaAaAaAb", "y", R"($&)", "foobBbBaAaAaAb");
    test(regex_45, "45", R"(foo(aA){1,5}+b)", "fooaAaAaAaAaAb", "y", R"($&)", "fooaAaAaAaAaAb");
    test(regex_46, "46", R"(foo(aA|bB){1,5}+b)", "foobBaAaAaAaAb", "y", R"($&)", "foobBaAaAaAaAb");
    test(regex_47, "47", R"(foo(aA)?+b)", "fooaAb", "y", R"($&)", "fooaAb");
    test(regex_48, "48", R"(foo(aA|bB)?+b)", "foobBb", "y", R"($&)", "foobBb");
    std::cout << std::endl;
  }





  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_01_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_01_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_01_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_01_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_01_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_01_matcher::to_string() -> std::string{return R"(a++a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_02_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_02_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_02_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_02_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_02_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_02_matcher::to_string() -> std::string{return R"(a*+a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_03_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_03_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_03_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_03_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_03_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_03_matcher::to_string() -> std::string{return R"(a{1,5}+a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_04_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_04_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_04_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_04_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_04_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_04_matcher::to_string() -> std::string{return R"(a?+a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_05_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_05_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_05_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_05_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_05_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_05_matcher::to_string() -> std::string{return R"(a++b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_06_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_06_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_06_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_06_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_06_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_06_matcher::to_string() -> std::string{return R"(a*+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_07_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_07_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_07_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_07_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_07_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_07_matcher::to_string() -> std::string{return R"(a{1,5}+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_08_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_08_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_08_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_08_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_08_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_08_matcher::to_string() -> std::string{return R"(a?+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_09_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_09_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_09_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_09_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_09_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_09_matcher::to_string() -> std::string{return R"(fooa++a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_10_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_10_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_10_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_10_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_10_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_10_matcher::to_string() -> std::string{return R"(fooa*+a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_11_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_11_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_11_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_11_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_11_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_11_matcher::to_string() -> std::string{return R"(fooa{1,5}+a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_12_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_12_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_12_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"a"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_12_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_12_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_12_matcher::to_string() -> std::string{return R"(fooa?+a)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_13_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_13_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_13_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_13_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_13_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_13_matcher::to_string() -> std::string{return R"(fooa++b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_14_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_14_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_14_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_14_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_14_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_14_matcher::to_string() -> std::string{return R"(fooa*+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_15_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_15_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_15_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_15_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_15_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_15_matcher::to_string() -> std::string{return R"(fooa{1,5}+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_16_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"a"}; 
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_16_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_16_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_16_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_16_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_16_matcher::to_string() -> std::string{return R"(fooa?+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_17_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_17_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_17_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_17_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_2 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_17_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_17_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_17_matcher::to_string() -> std::string{return R"((aA)++(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_18_matcher::to_string() -> std::string{return R"((aA|bB)++(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_19_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_19_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_19_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_19_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_2 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_19_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_19_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_19_matcher::to_string() -> std::string{return R"((aA)*+(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_20_matcher::to_string() -> std::string{return R"((aA|bB)*+(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_21_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_21_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_21_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_21_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_2 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_21_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_21_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_21_matcher::to_string() -> std::string{return R"((aA){1,5}+(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_22_matcher::to_string() -> std::string{return R"((aA|bB){1,5}+(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_23_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_23_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_23_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_23_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_2 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_23_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_23_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_23_matcher::to_string() -> std::string{return R"((aA)?+(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_24_matcher::to_string() -> std::string{return R"((aA|bB)?+(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_25_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_25_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_25_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_25_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_25_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_25_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_25_matcher::to_string() -> std::string{return R"((aA)++b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_26_matcher::to_string() -> std::string{return R"((aA|bB)++b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_27_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_27_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_27_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_27_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_27_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_27_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_27_matcher::to_string() -> std::string{return R"((aA)*+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_28_matcher::to_string() -> std::string{return R"((aA|bB)*+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_29_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_29_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_29_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_29_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_29_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_29_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_29_matcher::to_string() -> std::string{return R"((aA){1,5}+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_30_matcher::to_string() -> std::string{return R"((aA|bB){1,5}+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_31_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_31_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_31_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_31_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_2 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_31_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_31_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_31_matcher::to_string() -> std::string{return R"((aA)?+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_32_matcher::to_string() -> std::string{return R"((aA|bB)?+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_33_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_33_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_33_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_33_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_33_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_33_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_33_matcher::to_string() -> std::string{return R"(foo(aA)++(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_5 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_34_matcher::to_string() -> std::string{return R"(foo(aA|bB)++(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_35_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_35_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_35_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_35_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_35_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_35_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_35_matcher::to_string() -> std::string{return R"(foo(aA)*+(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_5 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_36_matcher::to_string() -> std::string{return R"(foo(aA|bB)*+(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_37_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_37_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_37_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_37_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_37_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_37_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_37_matcher::to_string() -> std::string{return R"(foo(aA){1,5}+(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_5 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_38_matcher::to_string() -> std::string{return R"(foo(aA|bB){1,5}+(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_39_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_39_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_39_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_39_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);

  std::array<char,2 + 1> str_tmp_3 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_39_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_39_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_39_matcher::to_string() -> std::string{return R"(foo(aA)?+(aA))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_4 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_5 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_40_matcher::to_string() -> std::string{return R"(foo(aA|bB)?+(aA|bB))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_41_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_41_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_41_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_41_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_41_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_41_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_41_matcher::to_string() -> std::string{return R"(foo(aA)++b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_4 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_42_matcher::to_string() -> std::string{return R"(foo(aA|bB)++b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_43_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_43_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_43_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_43_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_43_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_43_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_43_matcher::to_string() -> std::string{return R"(foo(aA)*+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_4 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_44_matcher::to_string() -> std::string{return R"(foo(aA|bB)*+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_45_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_45_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_45_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_45_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_45_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_45_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_45_matcher::to_string() -> std::string{return R"(foo(aA){1,5}+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,5,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_4 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_46_matcher::to_string() -> std::string{return R"(foo(aA|bB){1,5}+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_47_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_47_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_47_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_47_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_47_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_47_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_47_matcher::to_string() -> std::string{return R"(foo(aA)?+b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_1 {"aA"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_1, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_2 {"bB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_2, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 2;}
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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
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
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> str_tmp_0 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,3>::match(r.pos, ctx, func_1(), reset_0(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_4 {"b"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_4, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_13_possessive_modifier::regex_48_matcher::to_string() -> std::string{return R"(foo(aA|bB)?+b)"; }


#line 267 "pure2-regex_13_possessive_modifier.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_13_possessive_modifier());
}


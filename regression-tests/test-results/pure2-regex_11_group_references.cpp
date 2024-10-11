
#define CPP2_IMPORT_STD          Yes
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex_11_group_references.cpp2"

#line 165 "pure2-regex_11_group_references.cpp2"
class test_tests_11_group_references;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex_11_group_references.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 112 "pure2-regex_11_group_references.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 124 "pure2-regex_11_group_references.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 165 "pure2-regex_11_group_references.cpp2"
class test_tests_11_group_references {

#line 190 "pure2-regex_11_group_references.cpp2"
  public: auto run() const& -> void;
  public: class regex_01_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,5>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,5>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_0 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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

  public: cpp2::regex::regular_expression<char,regex_24_matcher> regex_24 {}; 
  public: test_tests_11_group_references() = default;
  public: test_tests_11_group_references(test_tests_11_group_references const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_11_group_references const&) -> void = delete;


#line 218 "pure2-regex_11_group_references.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex_11_group_references.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "pure2-regex_11_group_references.cpp2"
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

#line 112 "pure2-regex_11_group_references.cpp2"
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

#line 124 "pure2-regex_11_group_references.cpp2"
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

#line 190 "pure2-regex_11_group_references.cpp2"
  auto test_tests_11_group_references::run() const& -> void{
    std::cout << "Running tests_11_group_references:" << std::endl;
    test(regex_01, "01", R"((foo)(\g-2))", "foofoo", "y", R"($1-$2)", "foo-foo");
    test(regex_02, "02", R"((foo)(\g-2)(foo)(\g-2))", "foofoofoofoo", "y", R"($1-$2-$3-$4)", "foo-foo-foo-foo");
    test(regex_03, "03", R"((([abc]+) \g-1)(([abc]+) \g{-1}))", "abc abccba cba", "y", R"($2-$4)", "abc-cba");
    test(regex_04, "04", R"((a)(b)(c)\g1\g2\g3)", "abcabc", "y", R"($1$2$3)", "abc");
    test(regex_05, "05", R"(/(?'n'foo) \g{n}/)", "..foo foo..", "y", R"($1)", "foo");
    test(regex_06, "06", R"(/(?'n'foo) \g{ n }/)", "..foo foo..", "y", R"($1)", "foo");
    test(regex_07, "07", R"(/(?'n'foo) \g{n}/)", "..foo foo..", "yM", R"($+{n})", "foo");
    test(regex_08, "08", R"(/(?<n>foo) \g{n}/)", "..foo foo..", "y", R"($1)", "foo");
    test(regex_09, "09", R"(/(?<n>foo) \g{n}/)", "..foo foo..", "yM", R"($+{n})", "foo");
    test(regex_10, "10", R"(/(?<as>as) (\w+) \g{as} (\w+)/)", "as easy as pie", "y", R"($1-$2-$3)", "as-easy-pie");
    test(regex_11, "11", R"(/(?'n'foo) \k<n>/)", "..foo foo..", "y", R"($1)", "foo");
    test(regex_12, "12", R"(/(?'n'foo) \k<n>/)", "..foo foo..", "yM", R"($+{n})", "foo");
    test(regex_13, "13", R"(/(?<n>foo) \k'n'/)", "..foo foo..", "y", R"($1)", "foo");
    test(regex_14, "14", R"(/(?<n>foo) \k'n'/)", "..foo foo..", "yM", R"($+{n})", "foo");
    test(regex_15, "15", R"(/(?'a1'foo) \k'a1'/)", "..foo foo..", "yM", R"($+{a1})", "foo");
    test(regex_16, "16", R"(/(?<a1>foo) \k<a1>/)", "..foo foo..", "yM", R"($+{a1})", "foo");
    test(regex_17, "17", R"(/(?'_'foo) \k'_'/)", "..foo foo..", "yM", R"($+{_})", "foo");
    test(regex_18, "18", R"(/(?<_>foo) \k<_>/)", "..foo foo..", "yM", R"($+{_})", "foo");
    test(regex_19, "19", R"(/(?'_0_'foo) \k'_0_'/)", "..foo foo..", "yM", R"($+{_0_})", "foo");
    test(regex_20, "20", R"(/(?<_0_>foo) \k<_0_>/)", "..foo foo..", "yM", R"($+{_0_})", "foo");
    test(regex_21, "21", R"(/(?<as>as) (\w+) \k<as> (\w+)/)", "as easy as pie", "y", R"($1-$2-$3)", "as-easy-pie");
    test(regex_22, "22", R"(/(?<as>as) (\w+) \k{as} (\w+)/)", "as easy as pie", "y", R"($1-$2-$3)", "as-easy-pie");
    test(regex_23, "23", R"(/(?<as>as) (\w+) \k'as' (\w+)/)", "as easy as pie", "y", R"($1-$2-$3)", "as-easy-pie");
    test(regex_24, "24", R"(/(?<as>as) (\w+) \k{ as } (\w+)/)", "as easy as pie", "y", R"($1-$2-$3)", "as-easy-pie");
    std::cout << std::endl;
  }





  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_01_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_01_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_01_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_01_matcher::to_string() -> std::string{return R"((foo)(\g-2))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_02_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
  ctx.set_group_start(3, r.pos);

  std::array<char,3 + 1> str_tmp_3 {"foo"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_3, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
  ctx.set_group_start(4, r.pos);
  if (!(cpp2::regex::group_ref_token_matcher<char,3,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(4, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(4);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_02_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_02_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_02_matcher::to_string() -> std::string{return R"((foo)(\g-2)(foo)(\g-2))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_0_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_0 {cpp2::regex::make_on_return(cpp2::move(tmp_0_func))}; 
  static_cast<void>(cpp2::move(tmp_0));

  std::array<char,1 + 1> str_tmp_1 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,2,false>(r.pos, ctx))) {r.matched = false;break;}
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
  ctx.set_group_start(3, r.pos);
  ctx.set_group_start(4, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(4, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(4);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));

  std::array<char,1 + 1> str_tmp_4 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,4,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_03_matcher::to_string() -> std::string{return R"((([abc]+) \g-1)(([abc]+) \g{-1}))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_04_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  ctx.set_group_start(2, r.pos);

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
  ctx.set_group_start(3, r.pos);

  std::array<char,1 + 1> str_tmp_4 {"c"}; 
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
  ctx.set_group_end(3, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
  if (!(cpp2::regex::group_ref_token_matcher<char,2,false>(r.pos, ctx))) {r.matched = false;break;}
  if (!(cpp2::regex::group_ref_token_matcher<char,3,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_04_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_04_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_04_matcher::to_string() -> std::string{return R"((a)(b)(c)\g1\g2\g3)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_05_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_05_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_05_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_05_matcher::to_string() -> std::string{return R"(/(?'n'foo) \g{n}/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_06_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_06_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_06_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_06_matcher::to_string() -> std::string{return R"(/(?'n'foo) \g{ n }/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_07_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_07_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_07_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_07_matcher::to_string() -> std::string{return R"(/(?'n'foo) \g{n}/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_08_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_08_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_08_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_08_matcher::to_string() -> std::string{return R"(/(?<n>foo) \g{n}/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_09_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_09_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_09_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_09_matcher::to_string() -> std::string{return R"(/(?<n>foo) \g{n}/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"as"}; 
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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,1 + 1> str_tmp_4 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_5 {" "}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(3, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(3, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "as") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_10_matcher::to_string() -> std::string{return R"(/(?<as>as) (\w+) \g{as} (\w+)/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_11_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_11_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_11_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_11_matcher::to_string() -> std::string{return R"(/(?'n'foo) \k<n>/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_12_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_12_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_12_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_12_matcher::to_string() -> std::string{return R"(/(?'n'foo) \k<n>/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_13_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_13_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_13_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_13_matcher::to_string() -> std::string{return R"(/(?<n>foo) \k'n'/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_14_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_14_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_14_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "n") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_14_matcher::to_string() -> std::string{return R"(/(?<n>foo) \k'n'/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_15_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_15_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_15_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "a1") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_15_matcher::to_string() -> std::string{return R"(/(?'a1'foo) \k'a1'/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_16_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_16_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_16_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "a1") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_16_matcher::to_string() -> std::string{return R"(/(?<a1>foo) \k<a1>/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_17_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_17_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_17_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "_") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_17_matcher::to_string() -> std::string{return R"(/(?'_'foo) \k'_'/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_18_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_18_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_18_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "_") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_18_matcher::to_string() -> std::string{return R"(/(?<_>foo) \k<_>/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_19_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_19_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_19_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "_0_") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_19_matcher::to_string() -> std::string{return R"(/(?'_0_'foo) \k'_0_'/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_20_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_20_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_20_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "_0_") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_20_matcher::to_string() -> std::string{return R"(/(?<_0_>foo) \k<_0_>/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"as"}; 
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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,1 + 1> str_tmp_4 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_5 {" "}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(3, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(3, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "as") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_21_matcher::to_string() -> std::string{return R"(/(?<as>as) (\w+) \k<as> (\w+)/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"as"}; 
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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,1 + 1> str_tmp_4 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_5 {" "}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(3, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(3, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "as") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_22_matcher::to_string() -> std::string{return R"(/(?<as>as) (\w+) \k{as} (\w+)/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"as"}; 
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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,1 + 1> str_tmp_4 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_5 {" "}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(3, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(3, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "as") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_23_matcher::to_string() -> std::string{return R"(/(?<as>as) (\w+) \k'as' (\w+)/)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> str_tmp_0 {"as"}; 
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

  std::array<char,1 + 1> str_tmp_2 {" "}; 
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
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,1 + 1> str_tmp_4 {" "}; 
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> str_tmp_5 {" "}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_5, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(3, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(3, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "as") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_11_group_references::regex_24_matcher::to_string() -> std::string{return R"(/(?<as>as) (\w+) \k{ as } (\w+)/)"; }


#line 219 "pure2-regex_11_group_references.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_11_group_references());
}


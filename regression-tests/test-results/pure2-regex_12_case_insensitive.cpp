
#define CPP2_IMPORT_STD          Yes
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex_12_case_insensitive.cpp2"

#line 165 "pure2-regex_12_case_insensitive.cpp2"
class test_tests_12_case_insensitive;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex_12_case_insensitive.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 112 "pure2-regex_12_case_insensitive.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 124 "pure2-regex_12_case_insensitive.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 165 "pure2-regex_12_case_insensitive.cpp2"
class test_tests_12_case_insensitive {

#line 285 "pure2-regex_12_case_insensitive.cpp2"
  public: auto run() const& -> void;
  public: class regex_01_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_03_matcher() = default;
        public: regex_03_matcher(regex_03_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_03_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_03_matcher> regex_03 {}; public: class regex_04_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

  public: cpp2::regex::regular_expression<char,regex_10_matcher> regex_10 {}; public: class regex_100_matcher {
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

        public: regex_100_matcher() = default;
        public: regex_100_matcher(regex_100_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_100_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_100_matcher> regex_100 {}; public: class regex_101_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
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

        public: regex_101_matcher() = default;
        public: regex_101_matcher(regex_101_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_101_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_101_matcher> regex_101 {}; public: class regex_102_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_10 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_11 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_12 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_13 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_102_matcher() = default;
        public: regex_102_matcher(regex_102_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_102_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_102_matcher> regex_102 {}; public: class regex_103_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_10 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_11 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_12 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_13 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_103_matcher() = default;
        public: regex_103_matcher(regex_103_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_103_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_103_matcher> regex_103 {}; public: class regex_104_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_10 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_11 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_12 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_13 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_104_matcher() = default;
        public: regex_104_matcher(regex_104_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_104_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_104_matcher> regex_104 {}; public: class regex_105_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_10 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_11 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_12 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_13 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_105_matcher() = default;
        public: regex_105_matcher(regex_105_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_105_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_105_matcher> regex_105 {}; public: class regex_106_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_10 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_11 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_12 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_13 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_106_matcher() = default;
        public: regex_106_matcher(regex_106_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_106_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_106_matcher> regex_106 {}; public: class regex_107_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,11>;
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

        public: regex_107_matcher() = default;
        public: regex_107_matcher(regex_107_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_107_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_107_matcher> regex_107 {}; public: class regex_108_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,11>;
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

        public: regex_108_matcher() = default;
        public: regex_108_matcher(regex_108_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_108_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_108_matcher> regex_108 {}; public: class regex_109_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,10>;
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

        public: regex_109_matcher() = default;
        public: regex_109_matcher(regex_109_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_109_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_109_matcher> regex_109 {}; public: class regex_11_matcher {
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

  public: cpp2::regex::regular_expression<char,regex_11_matcher> regex_11 {}; public: class regex_110_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_110_matcher() = default;
        public: regex_110_matcher(regex_110_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_110_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_110_matcher> regex_110 {}; public: class regex_111_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_111_matcher() = default;
        public: regex_111_matcher(regex_111_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_111_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_111_matcher> regex_111 {}; public: class regex_112_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
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

        public: regex_112_matcher() = default;
        public: regex_112_matcher(regex_112_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_112_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_112_matcher> regex_112 {}; public: class regex_113_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
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

        public: regex_113_matcher() = default;
        public: regex_113_matcher(regex_113_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_113_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_113_matcher> regex_113 {}; public: class regex_114_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_114_matcher() = default;
        public: regex_114_matcher(regex_114_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_114_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_114_matcher> regex_114 {}; public: class regex_115_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_115_matcher() = default;
        public: regex_115_matcher(regex_115_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_115_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_115_matcher> regex_115 {}; public: class regex_116_matcher {
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

        public: regex_116_matcher() = default;
        public: regex_116_matcher(regex_116_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_116_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_116_matcher> regex_116 {}; public: class regex_117_matcher {
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

        public: regex_117_matcher() = default;
        public: regex_117_matcher(regex_117_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_117_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_117_matcher> regex_117 {}; public: class regex_118_matcher {
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

        public: regex_118_matcher() = default;
        public: regex_118_matcher(regex_118_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_118_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_118_matcher> regex_118 {}; public: class regex_119_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
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

        public: regex_119_matcher() = default;
        public: regex_119_matcher(regex_119_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_119_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_119_matcher> regex_119 {}; public: class regex_12_matcher {
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

        public: regex_17_matcher() = default;
        public: regex_17_matcher(regex_17_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_17_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_17_matcher> regex_17 {}; public: class regex_18_matcher {
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

        public: regex_18_matcher() = default;
        public: regex_18_matcher(regex_18_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_18_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_18_matcher> regex_18 {}; public: class regex_19_matcher {
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

        public: regex_19_matcher() = default;
        public: regex_19_matcher(regex_19_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_19_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_19_matcher> regex_19 {}; public: class regex_20_matcher {
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

        public: regex_20_matcher() = default;
        public: regex_20_matcher(regex_20_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_20_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_20_matcher> regex_20 {}; public: class regex_21_matcher {
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

        public: regex_21_matcher() = default;
        public: regex_21_matcher(regex_21_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_21_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_21_matcher> regex_21 {}; public: class regex_22_matcher {
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

        public: regex_22_matcher() = default;
        public: regex_22_matcher(regex_22_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_22_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_22_matcher> regex_22 {}; public: class regex_23_matcher {
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

        public: regex_23_matcher() = default;
        public: regex_23_matcher(regex_23_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_23_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_23_matcher> regex_23 {}; public: class regex_24_matcher {
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

        public: regex_24_matcher() = default;
        public: regex_24_matcher(regex_24_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_24_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_24_matcher> regex_24 {}; public: class regex_25_matcher {
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

        public: regex_25_matcher() = default;
        public: regex_25_matcher(regex_25_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_25_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_25_matcher> regex_25 {}; public: class regex_26_matcher {
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

        public: regex_26_matcher() = default;
        public: regex_26_matcher(regex_26_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_26_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_26_matcher> regex_26 {}; public: class regex_27_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_27_matcher() = default;
        public: regex_27_matcher(regex_27_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_27_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_27_matcher> regex_27 {}; public: class regex_28_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_28_matcher() = default;
        public: regex_28_matcher(regex_28_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_28_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_28_matcher> regex_28 {}; public: class regex_29_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_29_matcher() = default;
        public: regex_29_matcher(regex_29_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_29_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_29_matcher> regex_29 {}; public: class regex_30_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_30_matcher() = default;
        public: regex_30_matcher(regex_30_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_30_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_30_matcher> regex_30 {}; public: class regex_31_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_31_matcher() = default;
        public: regex_31_matcher(regex_31_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_31_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_31_matcher> regex_31 {}; public: class regex_32_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_32_matcher() = default;
        public: regex_32_matcher(regex_32_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_32_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_32_matcher> regex_32 {}; public: class regex_33_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_33_matcher() = default;
        public: regex_33_matcher(regex_33_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_33_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_33_matcher> regex_33 {}; public: class regex_34_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_34_matcher() = default;
        public: regex_34_matcher(regex_34_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_34_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_34_matcher> regex_34 {}; public: class regex_35_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_35_matcher() = default;
        public: regex_35_matcher(regex_35_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_35_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_35_matcher> regex_35 {}; public: class regex_36_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_36_matcher() = default;
        public: regex_36_matcher(regex_36_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_36_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_36_matcher> regex_36 {}; public: class regex_37_matcher {
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

        public: regex_37_matcher() = default;
        public: regex_37_matcher(regex_37_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_37_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_37_matcher> regex_37 {}; public: class regex_38_matcher {
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

        public: regex_38_matcher() = default;
        public: regex_38_matcher(regex_38_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_38_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_38_matcher> regex_38 {}; public: class regex_39_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_39_matcher() = default;
        public: regex_39_matcher(regex_39_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_39_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_39_matcher> regex_39 {}; public: class regex_40_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_40_matcher() = default;
        public: regex_40_matcher(regex_40_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_40_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_40_matcher> regex_40 {}; public: class regex_41_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_41_matcher() = default;
        public: regex_41_matcher(regex_41_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_41_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_41_matcher> regex_41 {}; public: class regex_42_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_42_matcher() = default;
        public: regex_42_matcher(regex_42_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_42_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_42_matcher> regex_42 {}; public: class regex_43_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_43_matcher() = default;
        public: regex_43_matcher(regex_43_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_43_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_43_matcher> regex_43 {}; public: class regex_44_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_44_matcher() = default;
        public: regex_44_matcher(regex_44_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_44_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_44_matcher> regex_44 {}; public: class regex_45_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_45_matcher() = default;
        public: regex_45_matcher(regex_45_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_45_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_45_matcher> regex_45 {}; public: class regex_46_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_46_matcher() = default;
        public: regex_46_matcher(regex_46_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_46_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_46_matcher> regex_46 {}; public: class regex_47_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_47_matcher() = default;
        public: regex_47_matcher(regex_47_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_47_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_47_matcher> regex_47 {}; public: class regex_48_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_48_matcher() = default;
        public: regex_48_matcher(regex_48_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_48_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_48_matcher> regex_48 {}; public: class regex_49_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_49_matcher() = default;
        public: regex_49_matcher(regex_49_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_49_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_49_matcher> regex_49 {}; public: class regex_50_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_50_matcher() = default;
        public: regex_50_matcher(regex_50_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_50_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_50_matcher> regex_50 {}; public: class regex_51_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_51_matcher() = default;
        public: regex_51_matcher(regex_51_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_51_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_51_matcher> regex_51 {}; public: class regex_52_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_52_matcher() = default;
        public: regex_52_matcher(regex_52_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_52_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_52_matcher> regex_52 {}; public: class regex_53_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_53_matcher() = default;
        public: regex_53_matcher(regex_53_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_53_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_53_matcher> regex_53 {}; public: class regex_54_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_54_matcher() = default;
        public: regex_54_matcher(regex_54_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_54_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_54_matcher> regex_54 {}; public: class regex_55_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_55_matcher() = default;
        public: regex_55_matcher(regex_55_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_55_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_55_matcher> regex_55 {}; public: class regex_56_matcher {
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

        public: regex_56_matcher() = default;
        public: regex_56_matcher(regex_56_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_56_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_56_matcher> regex_56 {}; public: class regex_57_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_57_matcher() = default;
        public: regex_57_matcher(regex_57_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_57_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_57_matcher> regex_57 {}; public: class regex_58_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_58_matcher() = default;
        public: regex_58_matcher(regex_58_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_58_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_58_matcher> regex_58 {}; public: class regex_59_matcher {
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

        public: regex_59_matcher() = default;
        public: regex_59_matcher(regex_59_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_59_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_59_matcher> regex_59 {}; public: class regex_60_matcher {
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

        public: regex_60_matcher() = default;
        public: regex_60_matcher(regex_60_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_60_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_60_matcher> regex_60 {}; public: class regex_61_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_61_matcher() = default;
        public: regex_61_matcher(regex_61_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_61_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_61_matcher> regex_61 {}; public: class regex_62_matcher {
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

        public: regex_62_matcher() = default;
        public: regex_62_matcher(regex_62_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_62_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_62_matcher> regex_62 {}; public: class regex_63_matcher {
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

        public: regex_63_matcher() = default;
        public: regex_63_matcher(regex_63_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_63_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_63_matcher> regex_63 {}; public: class regex_64_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_64_matcher() = default;
        public: regex_64_matcher(regex_64_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_64_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_64_matcher> regex_64 {}; public: class regex_65_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_65_matcher() = default;
        public: regex_65_matcher(regex_65_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_65_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_65_matcher> regex_65 {}; public: class regex_66_matcher {
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

        public: regex_66_matcher() = default;
        public: regex_66_matcher(regex_66_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_66_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_66_matcher> regex_66 {}; public: class regex_67_matcher {
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

        public: regex_67_matcher() = default;
        public: regex_67_matcher(regex_67_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_67_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_67_matcher> regex_67 {}; public: class regex_68_matcher {
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

        public: regex_68_matcher() = default;
        public: regex_68_matcher(regex_68_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_68_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_68_matcher> regex_68 {}; public: class regex_69_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_69_matcher() = default;
        public: regex_69_matcher(regex_69_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_69_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_69_matcher> regex_69 {}; public: class regex_70_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_70_matcher() = default;
        public: regex_70_matcher(regex_70_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_70_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_70_matcher> regex_70 {}; public: class regex_71_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_71_matcher() = default;
        public: regex_71_matcher(regex_71_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_71_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_71_matcher> regex_71 {}; public: class regex_72_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_72_matcher() = default;
        public: regex_72_matcher(regex_72_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_72_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_72_matcher> regex_72 {}; public: class regex_73_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_73_matcher() = default;
        public: regex_73_matcher(regex_73_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_73_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_73_matcher> regex_73 {}; public: class regex_74_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_74_matcher() = default;
        public: regex_74_matcher(regex_74_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_74_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_74_matcher> regex_74 {}; public: class regex_75_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_75_matcher() = default;
        public: regex_75_matcher(regex_75_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_75_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_75_matcher> regex_75 {}; public: class regex_76_matcher {
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

        public: regex_76_matcher() = default;
        public: regex_76_matcher(regex_76_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_76_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_76_matcher> regex_76 {}; public: class regex_77_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_77_matcher() = default;
        public: regex_77_matcher(regex_77_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_77_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_77_matcher> regex_77 {}; public: class regex_78_matcher {
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

        public: regex_78_matcher() = default;
        public: regex_78_matcher(regex_78_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_78_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_78_matcher> regex_78 {}; public: class regex_79_matcher {
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

        public: regex_79_matcher() = default;
        public: regex_79_matcher(regex_79_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_79_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_79_matcher> regex_79 {}; public: class regex_80_matcher {
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

        public: regex_80_matcher() = default;
        public: regex_80_matcher(regex_80_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_80_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_80_matcher> regex_80 {}; public: class regex_81_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_81_matcher() = default;
        public: regex_81_matcher(regex_81_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_81_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_81_matcher> regex_81 {}; public: class regex_82_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_82_matcher() = default;
        public: regex_82_matcher(regex_82_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_82_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_82_matcher> regex_82 {}; public: class regex_83_matcher {
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

        public: regex_83_matcher() = default;
        public: regex_83_matcher(regex_83_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_83_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_83_matcher> regex_83 {}; public: class regex_84_matcher {
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

        public: regex_84_matcher() = default;
        public: regex_84_matcher(regex_84_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_84_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_84_matcher> regex_84 {}; public: class regex_85_matcher {
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

        public: regex_85_matcher() = default;
        public: regex_85_matcher(regex_85_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_85_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_85_matcher> regex_85 {}; public: class regex_86_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_86_matcher() = default;
        public: regex_86_matcher(regex_86_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_86_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_86_matcher> regex_86 {}; public: class regex_87_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,1>;
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

        public: regex_87_matcher() = default;
        public: regex_87_matcher(regex_87_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_87_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_87_matcher> regex_87 {}; public: class regex_88_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_88_matcher() = default;
        public: regex_88_matcher(regex_88_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_88_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_88_matcher> regex_88 {}; public: class regex_89_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: [[nodiscard]] static auto entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>;

  public: [[nodiscard]] static auto get_named_group_index(auto const& name) -> int;

  public: wrap() = default;
  public: wrap(wrap const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(wrap const&) -> void = delete;

  };

  public: [[nodiscard]] static auto to_string() -> std::string;

        public: regex_89_matcher() = default;
        public: regex_89_matcher(regex_89_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_89_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_89_matcher> regex_89 {}; public: class regex_90_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
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

        public: regex_90_matcher() = default;
        public: regex_90_matcher(regex_90_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_90_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_90_matcher> regex_90 {}; public: class regex_91_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
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

        public: regex_91_matcher() = default;
        public: regex_91_matcher(regex_91_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_91_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_91_matcher> regex_91 {}; public: class regex_92_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
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

        public: regex_92_matcher() = default;
        public: regex_92_matcher(regex_92_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_92_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_92_matcher> regex_92 {}; public: class regex_93_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
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

        public: regex_93_matcher() = default;
        public: regex_93_matcher(regex_93_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_93_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_93_matcher> regex_93 {}; public: class regex_94_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
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

        public: regex_94_matcher() = default;
        public: regex_94_matcher(regex_94_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_94_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_94_matcher> regex_94 {}; public: class regex_95_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,3>;
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

        public: regex_95_matcher() = default;
        public: regex_95_matcher(regex_95_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_95_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_95_matcher> regex_95 {}; public: class regex_96_matcher {
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

        public: regex_96_matcher() = default;
        public: regex_96_matcher(regex_96_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_96_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_96_matcher> regex_96 {}; public: class regex_97_matcher {
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

        public: regex_97_matcher() = default;
        public: regex_97_matcher(regex_97_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_97_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_97_matcher> regex_97 {}; public: class regex_98_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
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

        public: regex_98_matcher() = default;
        public: regex_98_matcher(regex_98_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_98_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_98_matcher> regex_98 {}; public: class regex_99_matcher {
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

        public: regex_99_matcher() = default;
        public: regex_99_matcher(regex_99_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_99_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_99_matcher> regex_99 {}; 
  public: test_tests_12_case_insensitive() = default;
  public: test_tests_12_case_insensitive(test_tests_12_case_insensitive const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_12_case_insensitive const&) -> void = delete;


#line 408 "pure2-regex_12_case_insensitive.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex_12_case_insensitive.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "pure2-regex_12_case_insensitive.cpp2"
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

#line 112 "pure2-regex_12_case_insensitive.cpp2"
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

#line 124 "pure2-regex_12_case_insensitive.cpp2"
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

#line 285 "pure2-regex_12_case_insensitive.cpp2"
  auto test_tests_12_case_insensitive::run() const& -> void{
    std::cout << "Running tests_12_case_insensitive:" << std::endl;
    test(regex_01, "01", R"('abc'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_02, "02", R"('abc'i)", "XBC", "n", R"(-)", "-");
    test(regex_03, "03", R"('abc'i)", "AXC", "n", R"(-)", "-");
    test(regex_04, "04", R"('abc'i)", "ABX", "n", R"(-)", "-");
    test(regex_05, "05", R"('abc'i)", "XABCY", "y", R"($&)", "ABC");
    test(regex_06, "06", R"('abc'i)", "ABABC", "y", R"($&)", "ABC");
    test(regex_07, "07", R"('ab*c'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_08, "08", R"('ab*bc'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_09, "09", R"('ab*bc'i)", "ABBC", "y", R"($&)", "ABBC");
    test(regex_10, "10", R"('ab*?bc'i)", "ABBBBC", "y", R"($&)", "ABBBBC");
    test(regex_11, "11", R"('ab{0,}?bc'i)", "ABBBBC", "y", R"($&)", "ABBBBC");
    test(regex_12, "12", R"('ab+?bc'i)", "ABBC", "y", R"($&)", "ABBC");
    test(regex_13, "13", R"('ab+bc'i)", "ABC", "n", R"(-)", "-");
    test(regex_14, "14", R"('ab+bc'i)", "ABQ", "n", R"(-)", "-");
    test(regex_15, "15", R"('ab{1,}bc'i)", "ABQ", "n", R"(-)", "-");
    test(regex_16, "16", R"('ab+bc'i)", "ABBBBC", "y", R"($&)", "ABBBBC");
    test(regex_17, "17", R"('ab{1,}?bc'i)", "ABBBBC", "y", R"($&)", "ABBBBC");
    test(regex_18, "18", R"('ab{1,3}?bc'i)", "ABBBBC", "y", R"($&)", "ABBBBC");
    test(regex_19, "19", R"('ab{3,4}?bc'i)", "ABBBBC", "y", R"($&)", "ABBBBC");
    test(regex_20, "20", R"('ab{4,5}?bc'i)", "ABBBBC", "n", R"(-)", "-");
    test(regex_21, "21", R"('ab??bc'i)", "ABBC", "y", R"($&)", "ABBC");
    test(regex_22, "22", R"('ab??bc'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_23, "23", R"('ab{0,1}?bc'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_24, "24", R"('ab??bc'i)", "ABBBBC", "n", R"(-)", "-");
    test(regex_25, "25", R"('ab??c'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_26, "26", R"('ab{0,1}?c'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_27, "27", R"('^abc$'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_28, "28", R"('^abc$'i)", "ABCC", "n", R"(-)", "-");
    test(regex_29, "29", R"('^abc'i)", "ABCC", "y", R"($&)", "ABC");
    test(regex_30, "30", R"('^abc$'i)", "AABC", "n", R"(-)", "-");
    test(regex_31, "31", R"('abc$'i)", "AABC", "y", R"($&)", "ABC");
    test(regex_32, "32", R"('^'i)", "ABC", "y", R"($&)", "");
    test(regex_33, "33", R"('$'i)", "ABC", "y", R"($&)", "");
    test(regex_34, "34", R"('a.c'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_35, "35", R"('a.c'i)", "AXC", "y", R"($&)", "AXC");
    test(regex_36, "36", R"('a\Nc'i)", "ABC", "y", R"($&)", "ABC");
    test(regex_37, "37", R"('a.*?c'i)", "AXYZC", "y", R"($&)", "AXYZC");
    test(regex_38, "38", R"('a.*c'i)", "AXYZD", "n", R"(-)", "-");
    test(regex_39, "39", R"('a[bc]d'i)", "ABC", "n", R"(-)", "-");
    test(regex_40, "40", R"('a[bc]d'i)", "ABD", "y", R"($&)", "ABD");
    test(regex_41, "41", R"('a[b-d]e'i)", "ABD", "n", R"(-)", "-");
    test(regex_42, "42", R"('a[b-d]e'i)", "ACE", "y", R"($&)", "ACE");
    test(regex_43, "43", R"('a[b-d]'i)", "AAC", "y", R"($&)", "AC");
    test(regex_44, "44", R"('a[-b]'i)", "A-", "y", R"($&)", "A-");
    test(regex_45, "45", R"('a[b-]'i)", "A-", "y", R"($&)", "A-");
    test(regex_46, "46", R"('a]'i)", "A]", "y", R"($&)", "A]");
    test(regex_47, "47", R"('a[]]b'i)", "A]B", "y", R"($&)", "A]B");
    test(regex_48, "48", R"('a[^bc]d'i)", "AED", "y", R"($&)", "AED");
    test(regex_49, "49", R"('a[^bc]d'i)", "ABD", "n", R"(-)", "-");
    test(regex_50, "50", R"('a[^-b]c'i)", "ADC", "y", R"($&)", "ADC");
    test(regex_51, "51", R"('a[^-b]c'i)", "A-C", "n", R"(-)", "-");
    test(regex_52, "52", R"('a[^]b]c'i)", "A]C", "n", R"(-)", "-");
    test(regex_53, "53", R"('a[^]b]c'i)", "ADC", "y", R"($&)", "ADC");
    test(regex_54, "54", R"('ab|cd'i)", "ABC", "y", R"($&)", "AB");
    test(regex_55, "55", R"('ab|cd'i)", "ABCD", "y", R"($&)", "AB");
    test(regex_56, "56", R"('()ef'i)", "DEF", "y", R"($&-$1)", "EF-");
    test(regex_57, "57", R"('$b'i)", "B", "n", R"(-)", "-");
    test(regex_58, "58", R"('a\(b'i)", "A(B", "y", R"($&-$1)", "A(B-");
    test(regex_59, "59", R"('a\(*b'i)", "AB", "y", R"($&)", "AB");
    test(regex_60, "60", R"('a\(*b'i)", "A((B", "y", R"($&)", "A((B");
    test(regex_61, "61", R"('a\\b'i)", "A\\B", "y", R"($&)", "A\\B");
    test(regex_62, "62", R"('((a))'i)", "ABC", "y", R"($&-$1-$2)", "A-A-A");
    test(regex_63, "63", R"('(a)b(c)'i)", "ABC", "y", R"($&-$1-$2)", "ABC-A-C");
    test(regex_64, "64", R"('a+b+c'i)", "AABBABC", "y", R"($&)", "ABC");
    test(regex_65, "65", R"('a{1,}b{1,}c'i)", "AABBABC", "y", R"($&)", "ABC");
    test(regex_66, "66", R"('a.+?c'i)", "ABCABC", "y", R"($&)", "ABC");
    test(regex_67, "67", R"('a.*?c'i)", "ABCABC", "y", R"($&)", "ABC");
    test(regex_68, "68", R"('a.{0,5}?c'i)", "ABCABC", "y", R"($&)", "ABC");
    test(regex_69, "69", R"('(a+|b)*'i)", "AB", "y", R"($&-$1)", "AB-B");
    test(regex_70, "70", R"('(a+|b){0,}'i)", "AB", "y", R"($&-$1)", "AB-B");
    test(regex_71, "71", R"('(a+|b)+'i)", "AB", "y", R"($&-$1)", "AB-B");
    test(regex_72, "72", R"('(a+|b){1,}'i)", "AB", "y", R"($&-$1)", "AB-B");
    test(regex_73, "73", R"('(a+|b)?'i)", "AB", "y", R"($&-$1)", "A-A");
    test(regex_74, "74", R"('(a+|b){0,1}'i)", "AB", "y", R"($&-$1)", "A-A");
    test(regex_75, "75", R"('(a+|b){0,1}?'i)", "AB", "y", R"($&-$1)", "-");
    test(regex_76, "76", R"('[^ab]*'i)", "CDE", "y", R"($&)", "CDE");
    test(regex_77, "77", R"('abc'i)", "", "n", R"(-)", "-");
    test(regex_78, "78", R"('a*'i)", "", "y", R"($&)", "");
    test(regex_79, "79", R"('([abc])*d'i)", "ABBBCD", "y", R"($&-$1)", "ABBBCD-C");
    test(regex_80, "80", R"('([abc])*bcd'i)", "ABCD", "y", R"($&-$1)", "ABCD-A");
    test(regex_81, "81", R"('a|b|c|d|e'i)", "E", "y", R"($&)", "E");
    test(regex_82, "82", R"('(a|b|c|d|e)f'i)", "EF", "y", R"($&-$1)", "EF-E");
    test(regex_83, "83", R"('abcd*efg'i)", "ABCDEFG", "y", R"($&)", "ABCDEFG");
    test(regex_84, "84", R"('ab*'i)", "XABYABBBZ", "y", R"($&)", "AB");
    test(regex_85, "85", R"('ab*'i)", "XAYABBBZ", "y", R"($&)", "A");
    test(regex_86, "86", R"('(ab|cd)e'i)", "ABCDE", "y", R"($&-$1)", "CDE-CD");
    test(regex_87, "87", R"('[abhgefdc]ij'i)", "HIJ", "y", R"($&)", "HIJ");
    test(regex_88, "88", R"('^(ab|cd)e'i)", "ABCDE", "n", R"(x$1y)", "XY");
    test(regex_89, "89", R"('(abc|)ef'i)", "ABCDEF", "y", R"($&-$1)", "EF-");
    test(regex_90, "90", R"('(a|b)c*d'i)", "ABCD", "y", R"($&-$1)", "BCD-B");
    test(regex_91, "91", R"('(ab|ab*)bc'i)", "ABC", "y", R"($&-$1)", "ABC-A");
    test(regex_92, "92", R"('a([bc]*)c*'i)", "ABC", "y", R"($&-$1)", "ABC-BC");
    test(regex_93, "93", R"('a([bc]*)(c*d)'i)", "ABCD", "y", R"($&-$1-$2)", "ABCD-BC-D");
    test(regex_94, "94", R"('a([bc]+)(c*d)'i)", "ABCD", "y", R"($&-$1-$2)", "ABCD-BC-D");
    test(regex_95, "95", R"('a([bc]*)(c+d)'i)", "ABCD", "y", R"($&-$1-$2)", "ABCD-B-CD");
    test(regex_96, "96", R"('a[bcd]*dcdcde'i)", "ADCDCDE", "y", R"($&)", "ADCDCDE");
    test(regex_97, "97", R"('a[bcd]+dcdcde'i)", "ADCDCDE", "n", R"(-)", "-");
    test(regex_98, "98", R"('(ab|a)b*c'i)", "ABC", "y", R"($&-$1)", "ABC-AB");
    test(regex_99, "99", R"('((a)(b)c)(d)'i)", "ABCD", "y", R"($1-$2-$3-$4)", "ABC-A-B-D");
    test(regex_100, "100", R"('[a-zA-Z_][a-zA-Z0-9_]*'i)", "ALPHA", "y", R"($&)", "ALPHA");
    test(regex_101, "101", R"('^a(bc+|b[eh])g|.h$'i)", "ABH", "y", R"($&-$1)", "BH-");
    test(regex_102, "102", R"('(bc+d$|ef*g.|h?i(j|k))'i)", "EFFGZ", "y", R"($&-$1-$2)", "EFFGZ-EFFGZ-");
    test(regex_103, "103", R"('(bc+d$|ef*g.|h?i(j|k))'i)", "IJ", "y", R"($&-$1-$2)", "IJ-IJ-J");
    test(regex_104, "104", R"('(bc+d$|ef*g.|h?i(j|k))'i)", "EFFG", "n", R"(-)", "-");
    test(regex_105, "105", R"('(bc+d$|ef*g.|h?i(j|k))'i)", "BCDD", "n", R"(-)", "-");
    test(regex_106, "106", R"('(bc+d$|ef*g.|h?i(j|k))'i)", "REFFGZ", "y", R"($&-$1-$2)", "EFFGZ-EFFGZ-");
    test(regex_107, "107", R"('((((((((((a))))))))))'i)", "A", "y", R"($10)", "A");
    test(regex_108, "108", R"('((((((((((a))))))))))\10'i)", "AA", "y", R"($&)", "AA");
    test(regex_109, "109", R"('(((((((((a)))))))))'i)", "A", "y", R"($&)", "A");
    test(regex_110, "110", R"('multiple words of text'i)", "UH-UH", "n", R"(-)", "-");
    test(regex_111, "111", R"('multiple words'i)", "MULTIPLE WORDS, YEAH", "y", R"($&)", "MULTIPLE WORDS");
    test(regex_112, "112", R"('(.*)c(.*)'i)", "ABCDE", "y", R"($&-$1-$2)", "ABCDE-AB-DE");
    test(regex_113, "113", R"('\((.*), (.*)\)'i)", "(A, B)", "y", R"(($2, $1))", "(B, A)");
    test(regex_114, "114", R"('[k]'i)", "AB", "n", R"(-)", "-");
    test(regex_115, "115", R"('abcd'i)", "ABCD", "y", R"($&)", "ABCD");
    test(regex_116, "116", R"('a(bc)d'i)", "ABCD", "y", R"($1)", "BC");
    test(regex_117, "117", R"('a[-]?c'i)", "AC", "y", R"($&)", "AC");
    test(regex_118, "118", R"('(abc)\1'i)", "ABCABC", "y", R"($1)", "ABC");
    test(regex_119, "119", R"('([a-c]*)\1'i)", "ABCABC", "y", R"($1)", "ABC");
    std::cout << std::endl;
  }





  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_01_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_01_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_01_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_01_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_02_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_02_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_02_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_02_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_03_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_03_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_03_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_03_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_04_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_04_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_04_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_04_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_05_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_05_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_05_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_05_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_06_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_06_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_06_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_06_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_07_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_07_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_07_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_07_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_07_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_07_matcher::to_string() -> std::string{return R"('ab*c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_08_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_08_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_08_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_08_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_08_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_08_matcher::to_string() -> std::string{return R"('ab*bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_09_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_09_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_09_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_09_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_09_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_09_matcher::to_string() -> std::string{return R"('ab*bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_10_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_10_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_10_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_10_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_10_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_10_matcher::to_string() -> std::string{return R"('ab*?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_100_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::range_class_entry<char,'a','z'>,::cpp2::regex::range_class_entry<char,'A','Z'>,::cpp2::regex::range_class_entry<char,'0','9'>,::cpp2::regex::single_class_entry<char,'_'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_100_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::range_class_entry<char,'a','z'>,::cpp2::regex::range_class_entry<char,'A','Z'>,::cpp2::regex::single_class_entry<char,'_'>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_100_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_100_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_100_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_100_matcher::to_string() -> std::string{return R"('[a-zA-Z_][a-zA-Z0-9_]*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'e'>,::cpp2::regex::single_class_entry<char,'h'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));

  std::array<char,1 + 1> lower_str_tmp_5 {"g"}; 

  std::array<char,1 + 1> upper_str_tmp_5 {"G"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_6 {"h"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"H"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_1(), reset_0(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_101_matcher::to_string() -> std::string{return R"('^a(bc+|b[eh])g|.h$'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_2(), cpp2::regex::no_reset(), other, func_3());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"f"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"F"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_5(), cpp2::regex::no_reset(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_5 {"g"}; 

  std::array<char,1 + 1> upper_str_tmp_5 {"G"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_6 {"h"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"H"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_8(), cpp2::regex::no_reset(), other, func_9());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_10::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_8 {"j"}; 

  std::array<char,1 + 1> upper_str_tmp_8 {"J"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_11::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_9 {"k"}; 

  std::array<char,1 + 1> upper_str_tmp_9 {"K"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_7 {"i"}; 

  std::array<char,1 + 1> upper_str_tmp_7 {"I"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_12(), func_10(), cpp2::regex::no_reset(), func_11(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_12::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_13(), func_1(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_7(), reset_0());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::func_13::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_11_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_11 {cpp2::regex::make_on_return(cpp2::move(tmp_11_func))}; 
  static_cast<void>(cpp2::move(tmp_11));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_102_matcher::to_string() -> std::string{return R"('(bc+d$|ef*g.|h?i(j|k))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_2(), cpp2::regex::no_reset(), other, func_3());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"f"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"F"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_5(), cpp2::regex::no_reset(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_5 {"g"}; 

  std::array<char,1 + 1> upper_str_tmp_5 {"G"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_6 {"h"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"H"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_8(), cpp2::regex::no_reset(), other, func_9());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_10::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_8 {"j"}; 

  std::array<char,1 + 1> upper_str_tmp_8 {"J"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_11::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_9 {"k"}; 

  std::array<char,1 + 1> upper_str_tmp_9 {"K"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_7 {"i"}; 

  std::array<char,1 + 1> upper_str_tmp_7 {"I"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_12(), func_10(), cpp2::regex::no_reset(), func_11(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_12::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_13(), func_1(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_7(), reset_0());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::func_13::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_11_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_11 {cpp2::regex::make_on_return(cpp2::move(tmp_11_func))}; 
  static_cast<void>(cpp2::move(tmp_11));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_103_matcher::to_string() -> std::string{return R"('(bc+d$|ef*g.|h?i(j|k))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_2(), cpp2::regex::no_reset(), other, func_3());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"f"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"F"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_5(), cpp2::regex::no_reset(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_5 {"g"}; 

  std::array<char,1 + 1> upper_str_tmp_5 {"G"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_6 {"h"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"H"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_8(), cpp2::regex::no_reset(), other, func_9());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_10::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_8 {"j"}; 

  std::array<char,1 + 1> upper_str_tmp_8 {"J"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_11::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_9 {"k"}; 

  std::array<char,1 + 1> upper_str_tmp_9 {"K"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_7 {"i"}; 

  std::array<char,1 + 1> upper_str_tmp_7 {"I"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_12(), func_10(), cpp2::regex::no_reset(), func_11(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_12::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_13(), func_1(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_7(), reset_0());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::func_13::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_11_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_11 {cpp2::regex::make_on_return(cpp2::move(tmp_11_func))}; 
  static_cast<void>(cpp2::move(tmp_11));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_104_matcher::to_string() -> std::string{return R"('(bc+d$|ef*g.|h?i(j|k))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_2(), cpp2::regex::no_reset(), other, func_3());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"f"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"F"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_5(), cpp2::regex::no_reset(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_5 {"g"}; 

  std::array<char,1 + 1> upper_str_tmp_5 {"G"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_6 {"h"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"H"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_8(), cpp2::regex::no_reset(), other, func_9());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_10::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_8 {"j"}; 

  std::array<char,1 + 1> upper_str_tmp_8 {"J"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_11::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_9 {"k"}; 

  std::array<char,1 + 1> upper_str_tmp_9 {"K"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_7 {"i"}; 

  std::array<char,1 + 1> upper_str_tmp_7 {"I"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_12(), func_10(), cpp2::regex::no_reset(), func_11(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_12::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_13(), func_1(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_7(), reset_0());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::func_13::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_11_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_11 {cpp2::regex::make_on_return(cpp2::move(tmp_11_func))}; 
  static_cast<void>(cpp2::move(tmp_11));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_105_matcher::to_string() -> std::string{return R"('(bc+d$|ef*g.|h?i(j|k))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_2(), cpp2::regex::no_reset(), other, func_3());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"f"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"F"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_5(), cpp2::regex::no_reset(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_5 {"g"}; 

  std::array<char,1 + 1> upper_str_tmp_5 {"G"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_5, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_6 {"h"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"H"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_8(), cpp2::regex::no_reset(), other, func_9());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_10::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_8 {"j"}; 

  std::array<char,1 + 1> upper_str_tmp_8 {"J"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_8, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_11::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_9 {"k"}; 

  std::array<char,1 + 1> upper_str_tmp_9 {"K"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_9, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_7 {"i"}; 

  std::array<char,1 + 1> upper_str_tmp_7 {"I"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_7, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_12(), func_10(), cpp2::regex::no_reset(), func_11(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_12::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(2, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_13(), func_1(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_7(), reset_0());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::func_13::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_11_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_11 {cpp2::regex::make_on_return(cpp2::move(tmp_11_func))}; 
  static_cast<void>(cpp2::move(tmp_11));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_106_matcher::to_string() -> std::string{return R"('(bc+d$|ef*g.|h?i(j|k))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_107_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_start(2, r.pos);
  ctx.set_group_start(3, r.pos);
  ctx.set_group_start(4, r.pos);
  ctx.set_group_start(5, r.pos);
  ctx.set_group_start(6, r.pos);
  ctx.set_group_start(7, r.pos);
  ctx.set_group_start(8, r.pos);
  ctx.set_group_start(9, r.pos);
  ctx.set_group_start(10, r.pos);

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(10, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(10);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
  ctx.set_group_end(9, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(9);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
  ctx.set_group_end(8, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(8);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
  ctx.set_group_end(7, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(7);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
  ctx.set_group_end(6, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(6);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
  ctx.set_group_end(5, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(5);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
  ctx.set_group_end(4, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(4);
  }
  }
  }; 

  auto tmp_7 {cpp2::regex::make_on_return(cpp2::move(tmp_7_func))}; 
  static_cast<void>(cpp2::move(tmp_7));
  ctx.set_group_end(3, r.pos);

  auto tmp_8_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_8 {cpp2::regex::make_on_return(cpp2::move(tmp_8_func))}; 
  static_cast<void>(cpp2::move(tmp_8));
  ctx.set_group_end(2, r.pos);

  auto tmp_9_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_9 {cpp2::regex::make_on_return(cpp2::move(tmp_9_func))}; 
  static_cast<void>(cpp2::move(tmp_9));
  ctx.set_group_end(1, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_107_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_107_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_107_matcher::to_string() -> std::string{return R"('((((((((((a))))))))))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_108_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_start(2, r.pos);
  ctx.set_group_start(3, r.pos);
  ctx.set_group_start(4, r.pos);
  ctx.set_group_start(5, r.pos);
  ctx.set_group_start(6, r.pos);
  ctx.set_group_start(7, r.pos);
  ctx.set_group_start(8, r.pos);
  ctx.set_group_start(9, r.pos);
  ctx.set_group_start(10, r.pos);

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(10, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(10);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
  ctx.set_group_end(9, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(9);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
  ctx.set_group_end(8, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(8);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
  ctx.set_group_end(7, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(7);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
  ctx.set_group_end(6, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(6);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
  ctx.set_group_end(5, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(5);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
  ctx.set_group_end(4, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(4);
  }
  }
  }; 

  auto tmp_7 {cpp2::regex::make_on_return(cpp2::move(tmp_7_func))}; 
  static_cast<void>(cpp2::move(tmp_7));
  ctx.set_group_end(3, r.pos);

  auto tmp_8_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_8 {cpp2::regex::make_on_return(cpp2::move(tmp_8_func))}; 
  static_cast<void>(cpp2::move(tmp_8));
  ctx.set_group_end(2, r.pos);

  auto tmp_9_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_9 {cpp2::regex::make_on_return(cpp2::move(tmp_9_func))}; 
  static_cast<void>(cpp2::move(tmp_9));
  ctx.set_group_end(1, r.pos);

  auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
  static_cast<void>(cpp2::move(tmp_10));
  if (!(cpp2::regex::group_ref_token_matcher<char,10,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_108_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_108_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_108_matcher::to_string() -> std::string{return R"('((((((((((a))))))))))\10'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_109_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_start(2, r.pos);
  ctx.set_group_start(3, r.pos);
  ctx.set_group_start(4, r.pos);
  ctx.set_group_start(5, r.pos);
  ctx.set_group_start(6, r.pos);
  ctx.set_group_start(7, r.pos);
  ctx.set_group_start(8, r.pos);
  ctx.set_group_start(9, r.pos);

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(9, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(9);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
  ctx.set_group_end(8, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(8);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));
  ctx.set_group_end(7, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(7);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));
  ctx.set_group_end(6, r.pos);

  auto tmp_4_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(6);
  }
  }
  }; 

  auto tmp_4 {cpp2::regex::make_on_return(cpp2::move(tmp_4_func))}; 
  static_cast<void>(cpp2::move(tmp_4));
  ctx.set_group_end(5, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(5);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
  ctx.set_group_end(4, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(4);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));
  ctx.set_group_end(3, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_7 {cpp2::regex::make_on_return(cpp2::move(tmp_7_func))}; 
  static_cast<void>(cpp2::move(tmp_7));
  ctx.set_group_end(2, r.pos);

  auto tmp_8_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_8 {cpp2::regex::make_on_return(cpp2::move(tmp_8_func))}; 
  static_cast<void>(cpp2::move(tmp_8));
  ctx.set_group_end(1, r.pos);

  auto tmp_9_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_9 {cpp2::regex::make_on_return(cpp2::move(tmp_9_func))}; 
  static_cast<void>(cpp2::move(tmp_9));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_109_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_109_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_109_matcher::to_string() -> std::string{return R"('(((((((((a)))))))))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_11_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_11_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_11_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_11_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_11_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_11_matcher::to_string() -> std::string{return R"('ab{0,}?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_110_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,22 + 1> lower_str_tmp_0 {"multiple words of text"}; 

  std::array<char,22 + 1> upper_str_tmp_0 {"MULTIPLE WORDS OF TEXT"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),22)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,22); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 22;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_110_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_110_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_110_matcher::to_string() -> std::string{return R"('multiple words of text'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_111_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,14 + 1> lower_str_tmp_0 {"multiple words"}; 

  std::array<char,14 + 1> upper_str_tmp_0 {"MULTIPLE WORDS"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),14)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,14); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 14;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_111_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_111_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_111_matcher::to_string() -> std::string{return R"('multiple words'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_0_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_0 {cpp2::regex::make_on_return(cpp2::move(tmp_0_func))}; 
  static_cast<void>(cpp2::move(tmp_0));

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_112_matcher::to_string() -> std::string{return R"('(.*)c(.*)'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_0 {"("}; 
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
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,2 + 1> str_tmp_2 {", "}; 
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
  ctx.set_group_start(2, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  std::array<char,1 + 1> str_tmp_4 {")"}; 
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_113_matcher::to_string() -> std::string{return R"('\((.*), (.*)\)'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_114_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'k'>>::match(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_114_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_114_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_114_matcher::to_string() -> std::string{return R"('[k]'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_115_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,4 + 1> lower_str_tmp_0 {"abcd"}; 

  std::array<char,4 + 1> upper_str_tmp_0 {"ABCD"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),4)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,4); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 4;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_115_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_115_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_115_matcher::to_string() -> std::string{return R"('abcd'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_116_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);

  std::array<char,2 + 1> lower_str_tmp_1 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_1 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  std::array<char,1 + 1> lower_str_tmp_3 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_116_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_116_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_116_matcher::to_string() -> std::string{return R"('a(bc)d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_117_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'-'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_117_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_117_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_117_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_117_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_117_matcher::to_string() -> std::string{return R"('a[-]?c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_118_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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
  if (!(cpp2::regex::group_ref_token_matcher<char,1,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_118_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_118_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_118_matcher::to_string() -> std::string{return R"('(abc)\1'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_119_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::range_class_entry<char,'a','c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_119_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_119_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_0_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_0 {cpp2::regex::make_on_return(cpp2::move(tmp_0_func))}; 
  static_cast<void>(cpp2::move(tmp_0));
  if (!(cpp2::regex::group_ref_token_matcher<char,1,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_119_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_119_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_119_matcher::to_string() -> std::string{return R"('([a-c]*)\1'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_12_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_12_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_12_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_12_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_12_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_12_matcher::to_string() -> std::string{return R"('ab+?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_13_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_13_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_13_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_13_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_13_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_13_matcher::to_string() -> std::string{return R"('ab+bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_14_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_14_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_14_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_14_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_14_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_14_matcher::to_string() -> std::string{return R"('ab+bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_15_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_15_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_15_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_15_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_15_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_15_matcher::to_string() -> std::string{return R"('ab{1,}bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_16_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_16_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_16_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_16_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_16_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_16_matcher::to_string() -> std::string{return R"('ab+bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_17_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_17_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_17_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_17_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_17_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_17_matcher::to_string() -> std::string{return R"('ab{1,}?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_18_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_18_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,3,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_18_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_18_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_18_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_18_matcher::to_string() -> std::string{return R"('ab{1,3}?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_19_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_19_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,3,4,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_19_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_19_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_19_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_19_matcher::to_string() -> std::string{return R"('ab{3,4}?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_20_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_20_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,4,5,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_20_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_20_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_20_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_20_matcher::to_string() -> std::string{return R"('ab{4,5}?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_21_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_21_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_21_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_21_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_21_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_21_matcher::to_string() -> std::string{return R"('ab??bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_22_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_22_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_22_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_22_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_22_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_22_matcher::to_string() -> std::string{return R"('ab??bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_23_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_23_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_23_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_23_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_23_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_23_matcher::to_string() -> std::string{return R"('ab{0,1}?bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_24_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_24_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_24_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_2 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_24_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_24_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_24_matcher::to_string() -> std::string{return R"('ab??bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_25_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_25_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_25_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_25_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_25_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_25_matcher::to_string() -> std::string{return R"('ab??c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_26_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_26_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_26_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_26_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_26_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_26_matcher::to_string() -> std::string{return R"('ab{0,1}?c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_27_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_27_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_27_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_27_matcher::to_string() -> std::string{return R"('^abc$'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_28_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_28_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_28_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_28_matcher::to_string() -> std::string{return R"('^abc$'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_29_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_29_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_29_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_29_matcher::to_string() -> std::string{return R"('^abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_30_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_30_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_30_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_30_matcher::to_string() -> std::string{return R"('^abc$'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_31_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_31_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_31_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_31_matcher::to_string() -> std::string{return R"('abc$'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_32_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_32_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_32_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_32_matcher::to_string() -> std::string{return R"('^'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_33_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_33_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_33_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_33_matcher::to_string() -> std::string{return R"('$'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_34_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_34_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_34_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_34_matcher::to_string() -> std::string{return R"('a.c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_35_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_35_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_35_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_35_matcher::to_string() -> std::string{return R"('a.c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_36_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::named_class_no_new_line<char,true>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_36_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_36_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_36_matcher::to_string() -> std::string{return R"('a\Nc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_37_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_37_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_37_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_37_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_37_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_37_matcher::to_string() -> std::string{return R"('a.*?c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_38_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_38_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_38_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_38_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_38_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_38_matcher::to_string() -> std::string{return R"('a.*c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_39_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_39_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_39_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_39_matcher::to_string() -> std::string{return R"('a[bc]d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_40_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_40_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_40_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_40_matcher::to_string() -> std::string{return R"('a[bc]d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_41_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::range_class_entry<char,'b','d'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_41_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_41_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_41_matcher::to_string() -> std::string{return R"('a[b-d]e'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_42_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::range_class_entry<char,'b','d'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_42_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_42_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_42_matcher::to_string() -> std::string{return R"('a[b-d]e'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_43_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::range_class_entry<char,'b','d'>>::match(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_43_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_43_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_43_matcher::to_string() -> std::string{return R"('a[b-d]'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_44_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>::match(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_44_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_44_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_44_matcher::to_string() -> std::string{return R"('a[-b]'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_45_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'-'>>::match(r.pos, ctx))) {r.matched = false;break;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_45_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_45_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_45_matcher::to_string() -> std::string{return R"('a[b-]'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_46_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"a]"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"A]"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_46_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_46_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_46_matcher::to_string() -> std::string{return R"('a]'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_47_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,']'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_47_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_47_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_47_matcher::to_string() -> std::string{return R"('a[]]b'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_48_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_48_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_48_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_48_matcher::to_string() -> std::string{return R"('a[^bc]d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_49_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_49_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_49_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_49_matcher::to_string() -> std::string{return R"('a[^bc]d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_50_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_50_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_50_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_50_matcher::to_string() -> std::string{return R"('a[^-b]c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_51_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_51_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_51_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_51_matcher::to_string() -> std::string{return R"('a[^-b]c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_52_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_52_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_52_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_52_matcher::to_string() -> std::string{return R"('a[^]b]c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_53_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_53_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_53_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_53_matcher::to_string() -> std::string{return R"('a[^]b]c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"ab"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"AB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_1 {"cd"}; 

  std::array<char,2 + 1> upper_str_tmp_1 {"CD"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_54_matcher::to_string() -> std::string{return R"('ab|cd'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"ab"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"AB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_1 {"cd"}; 

  std::array<char,2 + 1> upper_str_tmp_1 {"CD"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_55_matcher::to_string() -> std::string{return R"('ab|cd'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_56_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_end(1, r.pos);

  auto tmp_0_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_0 {cpp2::regex::make_on_return(cpp2::move(tmp_0_func))}; 
  static_cast<void>(cpp2::move(tmp_0));

  std::array<char,2 + 1> lower_str_tmp_1 {"ef"}; 

  std::array<char,2 + 1> upper_str_tmp_1 {"EF"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_56_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_56_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_56_matcher::to_string() -> std::string{return R"('()ef'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_57_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_end_token_matcher<char,false,true>(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,1 + 1> lower_str_tmp_0 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_57_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_57_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_57_matcher::to_string() -> std::string{return R"('$b'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_58_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"a(b"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"A(B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_58_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_58_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_58_matcher::to_string() -> std::string{return R"('a\(b'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_59_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"("}; 
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_59_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_59_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_59_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_59_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_59_matcher::to_string() -> std::string{return R"('a\(*b'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_60_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {"("}; 
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_60_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_60_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_60_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_60_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_60_matcher::to_string() -> std::string{return R"('a\(*b'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_61_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"a\\b"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"A\\B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_61_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_61_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_61_matcher::to_string() -> std::string{return R"('a\\b'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_62_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_start(2, r.pos);

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_62_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_62_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_62_matcher::to_string() -> std::string{return R"('((a))'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_63_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  std::array<char,1 + 1> lower_str_tmp_2 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(2, r.pos);

  std::array<char,1 + 1> lower_str_tmp_3 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_63_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_63_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_63_matcher::to_string() -> std::string{return R"('(a)b(c)'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_64_matcher::to_string() -> std::string{return R"('a+b+c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_65_matcher::to_string() -> std::string{return R"('a{1,}b{1,}c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_66_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_66_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_66_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_66_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_66_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_66_matcher::to_string() -> std::string{return R"('a.+?c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_67_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_67_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_67_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_67_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_67_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_67_matcher::to_string() -> std::string{return R"('a.*?c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_68_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_68_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,5,1>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_68_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_68_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_68_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_68_matcher::to_string() -> std::string{return R"('a.{0,5}?c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_69_matcher::to_string() -> std::string{return R"('(a+|b)*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_70_matcher::to_string() -> std::string{return R"('(a+|b){0,}'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_71_matcher::to_string() -> std::string{return R"('(a+|b)+'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_72_matcher::to_string() -> std::string{return R"('(a+|b){1,}'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_73_matcher::to_string() -> std::string{return R"('(a+|b)?'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_74_matcher::to_string() -> std::string{return R"('(a+|b){0,1}'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_2(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,1>::match(r.pos, ctx, func_1(), reset_0(), other, func_7());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_75_matcher::to_string() -> std::string{return R"('(a+|b){0,1}?'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_76_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,true,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_76_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_76_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_76_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_76_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_76_matcher::to_string() -> std::string{return R"('[^ab]*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_77_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_77_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_77_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_77_matcher::to_string() -> std::string{return R"('abc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_78_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_78_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_78_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_78_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_78_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_78_matcher::to_string() -> std::string{return R"('a*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_79_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_0_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_0 {cpp2::regex::make_on_return(cpp2::move(tmp_0_func))}; 
  static_cast<void>(cpp2::move(tmp_0));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_79_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_79_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_79_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_79_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_79_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_79_matcher::to_string() -> std::string{return R"('([abc])*d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_80_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_0_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_0 {cpp2::regex::make_on_return(cpp2::move(tmp_0_func))}; 
  static_cast<void>(cpp2::move(tmp_0));
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


  template <typename Iter, typename CharT> auto test_tests_12_case_insensitive::regex_80_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_80_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_80_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_1 {"bcd"}; 

  std::array<char,3 + 1> upper_str_tmp_1 {"BCD"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_80_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_80_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_80_matcher::to_string() -> std::string{return R"('([abc])*bcd'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_81_matcher::to_string() -> std::string{return R"('a|b|c|d|e'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_6(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset(), func_3(), cpp2::regex::no_reset(), func_4(), cpp2::regex::no_reset(), func_5(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_end(1, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));

  std::array<char,1 + 1> lower_str_tmp_6 {"f"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"F"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_82_matcher::to_string() -> std::string{return R"('(a|b|c|d|e)f'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_83_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_83_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_83_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_2 {"efg"}; 

  std::array<char,3 + 1> upper_str_tmp_2 {"EFG"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_83_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_83_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_83_matcher::to_string() -> std::string{return R"('abcd*efg'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_84_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_84_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_84_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_84_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_84_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_84_matcher::to_string() -> std::string{return R"('ab*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_85_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_85_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_85_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_85_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_85_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_85_matcher::to_string() -> std::string{return R"('ab*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"ab"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"AB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_1 {"cd"}; 

  std::array<char,2 + 1> upper_str_tmp_1 {"CD"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_86_matcher::to_string() -> std::string{return R"('(ab|cd)e'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_87_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'h'>,::cpp2::regex::single_class_entry<char,'g'>,::cpp2::regex::single_class_entry<char,'e'>,::cpp2::regex::single_class_entry<char,'f'>,::cpp2::regex::single_class_entry<char,'d'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}

  std::array<char,2 + 1> lower_str_tmp_0 {"ij"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"IJ"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_87_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_87_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_87_matcher::to_string() -> std::string{return R"('[abhgefdc]ij'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"ab"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"AB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_1 {"cd"}; 

  std::array<char,2 + 1> upper_str_tmp_1 {"CD"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  std::array<char,1 + 1> lower_str_tmp_3 {"e"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"E"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_88_matcher::to_string() -> std::string{return R"('^(ab|cd)e'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,3 + 1> lower_str_tmp_0 {"abc"}; 

  std::array<char,3 + 1> upper_str_tmp_0 {"ABC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),3)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,3); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 3;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  std::array<char,2 + 1> lower_str_tmp_2 {"ef"}; 

  std::array<char,2 + 1> upper_str_tmp_2 {"EF"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_89_matcher::to_string() -> std::string{return R"('(abc|)ef'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_4(), cpp2::regex::no_reset(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_90_matcher::to_string() -> std::string{return R"('(a|b)c*d'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"ab"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"AB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_5(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  std::array<char,2 + 1> lower_str_tmp_4 {"bc"}; 

  std::array<char,2 + 1> upper_str_tmp_4 {"BC"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_91_matcher::to_string() -> std::string{return R"('(ab|ab*)bc'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_92_matcher::to_string() -> std::string{return R"('a([bc]*)c*'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_93_matcher::to_string() -> std::string{return R"('a([bc]*)(c*d)'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_94_matcher::to_string() -> std::string{return R"('a([bc]+)(c*d)'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_2 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_95_matcher::to_string() -> std::string{return R"('a([bc]*)(c+d)'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_96_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>,::cpp2::regex::single_class_entry<char,'d'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_96_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_96_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,6 + 1> lower_str_tmp_1 {"dcdcde"}; 

  std::array<char,6 + 1> upper_str_tmp_1 {"DCDCDE"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),6)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,6); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 6;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_96_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_96_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_96_matcher::to_string() -> std::string{return R"('a[bcd]*dcdcde'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_97_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,false,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>,::cpp2::regex::single_class_entry<char,'d'>>::match(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_97_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_97_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,6 + 1> lower_str_tmp_1 {"dcdcde"}; 

  std::array<char,6 + 1> upper_str_tmp_1 {"DCDCDE"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),6)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,6); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 6;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_97_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_97_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_97_matcher::to_string() -> std::string{return R"('a[bcd]+dcdcde'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> lower_str_tmp_0 {"ab"}; 

  std::array<char,2 + 1> upper_str_tmp_0 {"AB"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),2)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_1 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_1 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_1, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), cpp2::regex::no_reset(), func_2(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_3 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_3 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_3, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_4(), cpp2::regex::no_reset(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> lower_str_tmp_4 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_98_matcher::to_string() -> std::string{return R"('(ab|a)b*c'i)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_99_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  ctx.set_group_start(2, r.pos);

  std::array<char,1 + 1> lower_str_tmp_0 {"a"}; 

  std::array<char,1 + 1> upper_str_tmp_0 {"A"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_0, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(2, r.pos);

  auto tmp_1_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(2);
  }
  }
  }; 

  auto tmp_1 {cpp2::regex::make_on_return(cpp2::move(tmp_1_func))}; 
  static_cast<void>(cpp2::move(tmp_1));
  ctx.set_group_start(3, r.pos);

  std::array<char,1 + 1> lower_str_tmp_2 {"b"}; 

  std::array<char,1 + 1> upper_str_tmp_2 {"B"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_2, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_3_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_3 {cpp2::regex::make_on_return(cpp2::move(tmp_3_func))}; 
  static_cast<void>(cpp2::move(tmp_3));

  std::array<char,1 + 1> lower_str_tmp_4 {"c"}; 

  std::array<char,1 + 1> upper_str_tmp_4 {"C"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_4, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_5_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_5 {cpp2::regex::make_on_return(cpp2::move(tmp_5_func))}; 
  static_cast<void>(cpp2::move(tmp_5));
  ctx.set_group_start(4, r.pos);

  std::array<char,1 + 1> lower_str_tmp_6 {"d"}; 

  std::array<char,1 + 1> upper_str_tmp_6 {"D"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (!((CPP2_ASSERT_IN_BOUNDS(lower_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i) || CPP2_ASSERT_IN_BOUNDS(upper_str_tmp_6, i) == CPP2_ASSERT_IN_BOUNDS(r.pos, i)))) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(4, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(4);
  }
  }
  }; 

  auto tmp_7 {cpp2::regex::make_on_return(cpp2::move(tmp_7_func))}; 
  static_cast<void>(cpp2::move(tmp_7));
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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_99_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_12_case_insensitive::regex_99_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_12_case_insensitive::regex_99_matcher::to_string() -> std::string{return R"('((a)(b)c)(d)'i)"; }


#line 409 "pure2-regex_12_case_insensitive.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_12_case_insensitive());
}


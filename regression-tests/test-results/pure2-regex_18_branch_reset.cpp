
#define CPP2_IMPORT_STD          Yes
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex_18_branch_reset.cpp2"

#line 165 "pure2-regex_18_branch_reset.cpp2"
class test_tests_18_branch_reset;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex_18_branch_reset.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 112 "pure2-regex_18_branch_reset.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 124 "pure2-regex_18_branch_reset.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 165 "pure2-regex_18_branch_reset.cpp2"
class test_tests_18_branch_reset {

#line 181 "pure2-regex_18_branch_reset.cpp2"
  public: auto run() const& -> void;
  public: class regex_01_matcher {
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

        public: regex_01_matcher() = default;
        public: regex_01_matcher(regex_01_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_01_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_01_matcher> regex_01 {}; public: class regex_02_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
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

        public: regex_02_matcher() = default;
        public: regex_02_matcher(regex_02_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_02_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_02_matcher> regex_02 {}; public: class regex_03_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,4>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
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
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
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

        public: regex_04_matcher() = default;
        public: regex_04_matcher(regex_04_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_04_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_04_matcher> regex_04 {}; public: class regex_05_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_3 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_4 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_5 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
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
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_3 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_4 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_5 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
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
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_3 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_4 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_5 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
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
public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_3 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_2 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_6 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_3 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_7 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_4 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_5 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_5 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
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
  public: using context = cpp2::regex::match_context<CharT,Iter,5>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

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

        public: regex_09_matcher() = default;
        public: regex_09_matcher(regex_09_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_09_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_09_matcher> regex_09 {}; public: class regex_10_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,5>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

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
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

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

        public: regex_12_matcher() = default;
        public: regex_12_matcher(regex_12_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_12_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_12_matcher> regex_12 {}; public: class regex_13_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

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

        public: regex_13_matcher() = default;
        public: regex_13_matcher(regex_13_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_13_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_13_matcher> regex_13 {}; public: class regex_14_matcher {
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

        public: regex_14_matcher() = default;
        public: regex_14_matcher(regex_14_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_14_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_14_matcher> regex_14 {}; public: class regex_15_matcher {
  public: template<typename Iter, typename CharT> class wrap {
  public: using context = cpp2::regex::match_context<CharT,Iter,182>;
public: class func_1 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_2 {
  public: [[nodiscard]] auto operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_1 {
  public: auto operator()(auto& ctx) const& -> void;

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

        public: regex_15_matcher() = default;
        public: regex_15_matcher(regex_15_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_15_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_15_matcher> regex_15 {}; 
  public: test_tests_18_branch_reset() = default;
  public: test_tests_18_branch_reset(test_tests_18_branch_reset const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_18_branch_reset const&) -> void = delete;


#line 200 "pure2-regex_18_branch_reset.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex_18_branch_reset.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "pure2-regex_18_branch_reset.cpp2"
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

#line 112 "pure2-regex_18_branch_reset.cpp2"
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

#line 124 "pure2-regex_18_branch_reset.cpp2"
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

#line 181 "pure2-regex_18_branch_reset.cpp2"
  auto test_tests_18_branch_reset::run() const& -> void{
    std::cout << "Running tests_18_branch_reset:" << std::endl;
    test(regex_01, "01", R"((?|(a)))", "a", "y", R"($1-$+)", "a-a");
    test(regex_02, "02", R"((?|a(.)b|d(.(o).)d|i(.)(.)j)(.))", "d!o!da", "y", R"($1-$2-$3)", "!o!-o-a");
    test(regex_03, "03", R"((?|a(.)b|d(.(o).)d|i(.)(.)j)(.))", "aabc", "y", R"($1-$2-$3)", "a--c");
    test(regex_04, "04", R"((?|a(.)b|d(.(o).)d|i(.)(.)j)(.))", "ixyjp", "y", R"($1-$2-$3)", "x-y-p");
    test(regex_05, "05", R"((?|(?|(a)|(b))|(?|(c)|(d))))", "a", "y", R"($1)", "a");
    test(regex_06, "06", R"((?|(?|(a)|(b))|(?|(c)|(d))))", "b", "y", R"($1)", "b");
    test(regex_07, "07", R"((?|(?|(a)|(b))|(?|(c)|(d))))", "c", "y", R"($1)", "c");
    test(regex_08, "08", R"((?|(?|(a)|(b))|(?|(c)|(d))))", "d", "y", R"($1)", "d");
    test(regex_09, "09", R"((.)(?|(.)(.)x|(.)d)(.))", "abcde", "y", R"($1-$2-$3-$4-$5-)", "b-c--e--");
    test(regex_10, "10", R"((\N)(?|(\N)(\N)x|(\N)d)(\N))", "abcde", "y", R"($1-$2-$3-$4-$5-)", "b-c--e--");
    test(regex_11, "11", R"((?|(?<foo>x)))", "x", "yM", R"($+{foo})", "x");
    test(regex_12, "12", R"((?|(?<foo>x)|(?<bar>y)))", "x", "yM", R"($+{foo})", "x");
    test(regex_13, "13", R"((?|(?<bar>y)|(?<foo>x)))", "x", "yM", R"($+{foo})", "x");
    test(regex_14, "14", R"((?<bar>)(?|(?<foo>x)))", "x", "yM", R"($+{foo})", "x");
    test(regex_15, "15", R"((?|(b)|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()(a)))", "a", "y", R"($&)", "a");
    std::cout << std::endl;
  }





  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_01_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_01_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_01_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_01_matcher::to_string() -> std::string{return R"((?|(a)))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"d"}; 
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
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_start(2, r.pos);

  std::array<char,1 + 1> str_tmp_4 {"o"}; 
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
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));

  std::array<char,1 + 1> str_tmp_7 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_7, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_8 {"i"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_8, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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

  std::array<char,1 + 1> str_tmp_11 {"j"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_11, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_1(), reset_0(), func_2(), reset_1(), func_3(), reset_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(3, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_12_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_12 {cpp2::regex::make_on_return(cpp2::move(tmp_12_func))}; 
  static_cast<void>(cpp2::move(tmp_12));
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_02_matcher::to_string() -> std::string{return R"((?|a(.)b|d(.(o).)d|i(.)(.)j)(.))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"d"}; 
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
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_start(2, r.pos);

  std::array<char,1 + 1> str_tmp_4 {"o"}; 
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
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));

  std::array<char,1 + 1> str_tmp_7 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_7, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_8 {"i"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_8, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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

  std::array<char,1 + 1> str_tmp_11 {"j"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_11, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_1(), reset_0(), func_2(), reset_1(), func_3(), reset_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(3, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_12_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_12 {cpp2::regex::make_on_return(cpp2::move(tmp_12_func))}; 
  static_cast<void>(cpp2::move(tmp_12));
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_03_matcher::to_string() -> std::string{return R"((?|a(.)b|d(.(o).)d|i(.)(.)j)(.))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_3 {"d"}; 
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
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_start(2, r.pos);

  std::array<char,1 + 1> str_tmp_4 {"o"}; 
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
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_6_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
  }
  }
  }; 

  auto tmp_6 {cpp2::regex::make_on_return(cpp2::move(tmp_6_func))}; 
  static_cast<void>(cpp2::move(tmp_6));

  std::array<char,1 + 1> str_tmp_7 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_7, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_8 {"i"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_8, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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

  std::array<char,1 + 1> str_tmp_11 {"j"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_11, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_1(), reset_0(), func_2(), reset_1(), func_3(), reset_2());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(3, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_12_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_12 {cpp2::regex::make_on_return(cpp2::move(tmp_12_func))}; 
  static_cast<void>(cpp2::move(tmp_12));
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_04_matcher::to_string() -> std::string{return R"((?|a(.)b|d(.(o).)d|i(.)(.)j)(.))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), reset_0(), func_3(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::reset_3::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_6 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_6, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::reset_4::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), reset_3(), func_7(), reset_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::reset_5::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_9(), func_1(), reset_2(), func_5(), reset_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_05_matcher::to_string() -> std::string{return R"((?|(?|(a)|(b))|(?|(c)|(d))))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), reset_0(), func_3(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::reset_3::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_6 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_6, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::reset_4::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), reset_3(), func_7(), reset_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::reset_5::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_9(), func_1(), reset_2(), func_5(), reset_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_06_matcher::to_string() -> std::string{return R"((?|(?|(a)|(b))|(?|(c)|(d))))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), reset_0(), func_3(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::reset_3::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_6 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_6, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::reset_4::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), reset_3(), func_7(), reset_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::reset_5::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_9(), func_1(), reset_2(), func_5(), reset_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_07_matcher::to_string() -> std::string{return R"((?|(?|(a)|(b))|(?|(c)|(d))))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_4(), func_2(), reset_0(), func_3(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_4::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::reset_2::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_6::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::reset_3::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_7::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_6 {"d"}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_6, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 1;}
  else {break;}
  ctx.set_group_end(1, r.pos);

  auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(1);
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::reset_4::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_5::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_8(), func_6(), reset_3(), func_7(), reset_4());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_8::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::reset_5::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_9(), func_1(), reset_2(), func_5(), reset_5());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::func_9::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_08_matcher::to_string() -> std::string{return R"((?|(?|(a)|(b))|(?|(c)|(d))))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));

  std::array<char,1 + 1> str_tmp_3 {"x"}; 
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  ctx.set_group_invalid(3);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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

  std::array<char,1 + 1> str_tmp_5 {"d"}; 
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), reset_0(), func_2(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(4, r.pos);
  if (!(cpp2::regex::any_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_09_matcher::to_string() -> std::string{return R"((.)(?|(.)(.)x|(.)d)(.))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::named_class_no_new_line<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
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
  if (!(cpp2::regex::named_class_no_new_line<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_end(3, r.pos);

  auto tmp_2_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
  if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
  (*cpp2::impl::assert_not_null(_2)).set_group_invalid(3);
  }
  }
  }; 

  auto tmp_2 {cpp2::regex::make_on_return(cpp2::move(tmp_2_func))}; 
  static_cast<void>(cpp2::move(tmp_2));

  std::array<char,1 + 1> str_tmp_3 {"x"}; 
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  ctx.set_group_invalid(3);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(2, r.pos);
  if (!(cpp2::regex::named_class_no_new_line<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
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

  std::array<char,1 + 1> str_tmp_5 {"d"}; 
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(2);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  if (!(cpp2::regex::named_class_no_new_line<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
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
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), reset_0(), func_2(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(4, r.pos);
  if (!(cpp2::regex::named_class_no_new_line<char,false>::match(r.pos, ctx))) {r.matched = false;break;}
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_10_matcher::to_string() -> std::string{return R"((\N)(?|(\N)(\N)x|(\N)d)(\N))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_11_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_0 {"x"}; 
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_11_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_11_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "foo") {return 1; }else {return -1; }
  }

  [[nodiscard]] auto test_tests_18_branch_reset::regex_11_matcher::to_string() -> std::string{return R"((?|(?<foo>x)))"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_0 {"x"}; 
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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);

  std::array<char,1 + 1> str_tmp_2 {"y"}; 
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


  template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), reset_0(), func_2(), reset_1());
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }


  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  if (name == "bar") {return 1; }else {if (name == "foo") {return 1; }else {return -1; }
#line 1 "pure2-regex_18_branch_reset.cpp2"
}
}

[[nodiscard]] auto test_tests_18_branch_reset::regex_12_matcher::to_string() -> std::string{return R"((?|(?<foo>x)|(?<bar>y)))"; }






template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

auto r {ctx.pass(cur)}; 
do {
ctx.set_group_start(1, r.pos);

std::array<char,1 + 1> str_tmp_0 {"y"}; 
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
}
 while ( 
false
);
if (r.matched) {
r = other(r.pos, ctx);
}
else {
r.pos = ctx.end;
}
return r; 
}


template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
ctx.set_group_invalid(1);
}


template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

auto r {ctx.pass(cur)}; 
do {
ctx.set_group_start(1, r.pos);

std::array<char,1 + 1> str_tmp_2 {"x"}; 
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


template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
ctx.set_group_invalid(1);
}


template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

auto r {ctx.pass(cur)}; 
do {
}
 while ( 
false
);
if (r.matched) {
r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), reset_0(), func_2(), reset_1());
}
else {
r.pos = ctx.end;
}
return r; 
}


template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
ctx.set_group_start(0, cur);

auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
if (r.matched) {ctx.set_group_end(0, r.pos);}
return r; 
}

template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
if (name == "bar") {return 1; }else {if (name == "foo") {return 1; }else {return -1; }}
}

[[nodiscard]] auto test_tests_18_branch_reset::regex_13_matcher::to_string() -> std::string{return R"((?|(?<bar>y)|(?<foo>x)))"; }






template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_14_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
ctx.set_group_start(2, r.pos);

std::array<char,1 + 1> str_tmp_1 {"x"}; 
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

template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_14_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
ctx.set_group_start(0, cur);

auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
if (r.matched) {ctx.set_group_end(0, r.pos);}
return r; 
}

template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_14_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
if (name == "bar") {return 1; }else {if (name == "foo") {return 2; }else {return -1; }}
}

[[nodiscard]] auto test_tests_18_branch_reset::regex_14_matcher::to_string() -> std::string{return R"((?<bar>)(?|(?<foo>x)))"; }






template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::func_1::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

auto r {ctx.pass(cur)}; 
do {
ctx.set_group_start(1, r.pos);

std::array<char,1 + 1> str_tmp_0 {"b"}; 
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
}
 while ( 
false
);
if (r.matched) {
r = other(r.pos, ctx);
}
else {
r.pos = ctx.end;
}
return r; 
}


template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::reset_0::operator()(auto& ctx) const& -> void{
ctx.set_group_invalid(1);
}


template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::func_2::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

auto r {ctx.pass(cur)}; 
do {
ctx.set_group_start(1, r.pos);
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
ctx.set_group_start(2, r.pos);
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
ctx.set_group_start(5, r.pos);
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
ctx.set_group_start(6, r.pos);
ctx.set_group_end(6, r.pos);

auto tmp_7_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(6);
}
}
}; 

auto tmp_7 {cpp2::regex::make_on_return(cpp2::move(tmp_7_func))}; 
static_cast<void>(cpp2::move(tmp_7));
ctx.set_group_start(7, r.pos);
ctx.set_group_end(7, r.pos);

auto tmp_8_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(7);
}
}
}; 

auto tmp_8 {cpp2::regex::make_on_return(cpp2::move(tmp_8_func))}; 
static_cast<void>(cpp2::move(tmp_8));
ctx.set_group_start(8, r.pos);
ctx.set_group_end(8, r.pos);

auto tmp_9_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(8);
}
}
}; 

auto tmp_9 {cpp2::regex::make_on_return(cpp2::move(tmp_9_func))}; 
static_cast<void>(cpp2::move(tmp_9));
ctx.set_group_start(9, r.pos);
ctx.set_group_end(9, r.pos);

auto tmp_10_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(9);
}
}
}; 

auto tmp_10 {cpp2::regex::make_on_return(cpp2::move(tmp_10_func))}; 
static_cast<void>(cpp2::move(tmp_10));
ctx.set_group_start(10, r.pos);
ctx.set_group_end(10, r.pos);

auto tmp_11_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(10);
}
}
}; 

auto tmp_11 {cpp2::regex::make_on_return(cpp2::move(tmp_11_func))}; 
static_cast<void>(cpp2::move(tmp_11));
ctx.set_group_start(11, r.pos);
ctx.set_group_end(11, r.pos);

auto tmp_12_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(11);
}
}
}; 

auto tmp_12 {cpp2::regex::make_on_return(cpp2::move(tmp_12_func))}; 
static_cast<void>(cpp2::move(tmp_12));
ctx.set_group_start(12, r.pos);
ctx.set_group_end(12, r.pos);

auto tmp_13_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(12);
}
}
}; 

auto tmp_13 {cpp2::regex::make_on_return(cpp2::move(tmp_13_func))}; 
static_cast<void>(cpp2::move(tmp_13));
ctx.set_group_start(13, r.pos);
ctx.set_group_end(13, r.pos);

auto tmp_14_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(13);
}
}
}; 

auto tmp_14 {cpp2::regex::make_on_return(cpp2::move(tmp_14_func))}; 
static_cast<void>(cpp2::move(tmp_14));
ctx.set_group_start(14, r.pos);
ctx.set_group_end(14, r.pos);

auto tmp_15_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(14);
}
}
}; 

auto tmp_15 {cpp2::regex::make_on_return(cpp2::move(tmp_15_func))}; 
static_cast<void>(cpp2::move(tmp_15));
ctx.set_group_start(15, r.pos);
ctx.set_group_end(15, r.pos);

auto tmp_16_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(15);
}
}
}; 

auto tmp_16 {cpp2::regex::make_on_return(cpp2::move(tmp_16_func))}; 
static_cast<void>(cpp2::move(tmp_16));
ctx.set_group_start(16, r.pos);
ctx.set_group_end(16, r.pos);

auto tmp_17_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(16);
}
}
}; 

auto tmp_17 {cpp2::regex::make_on_return(cpp2::move(tmp_17_func))}; 
static_cast<void>(cpp2::move(tmp_17));
ctx.set_group_start(17, r.pos);
ctx.set_group_end(17, r.pos);

auto tmp_18_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(17);
}
}
}; 

auto tmp_18 {cpp2::regex::make_on_return(cpp2::move(tmp_18_func))}; 
static_cast<void>(cpp2::move(tmp_18));
ctx.set_group_start(18, r.pos);
ctx.set_group_end(18, r.pos);

auto tmp_19_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(18);
}
}
}; 

auto tmp_19 {cpp2::regex::make_on_return(cpp2::move(tmp_19_func))}; 
static_cast<void>(cpp2::move(tmp_19));
ctx.set_group_start(19, r.pos);
ctx.set_group_end(19, r.pos);

auto tmp_20_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(19);
}
}
}; 

auto tmp_20 {cpp2::regex::make_on_return(cpp2::move(tmp_20_func))}; 
static_cast<void>(cpp2::move(tmp_20));
ctx.set_group_start(20, r.pos);
ctx.set_group_end(20, r.pos);

auto tmp_21_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(20);
}
}
}; 

auto tmp_21 {cpp2::regex::make_on_return(cpp2::move(tmp_21_func))}; 
static_cast<void>(cpp2::move(tmp_21));
ctx.set_group_start(21, r.pos);
ctx.set_group_end(21, r.pos);

auto tmp_22_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(21);
}
}
}; 

auto tmp_22 {cpp2::regex::make_on_return(cpp2::move(tmp_22_func))}; 
static_cast<void>(cpp2::move(tmp_22));
ctx.set_group_start(22, r.pos);
ctx.set_group_end(22, r.pos);

auto tmp_23_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(22);
}
}
}; 

auto tmp_23 {cpp2::regex::make_on_return(cpp2::move(tmp_23_func))}; 
static_cast<void>(cpp2::move(tmp_23));
ctx.set_group_start(23, r.pos);
ctx.set_group_end(23, r.pos);

auto tmp_24_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(23);
}
}
}; 

auto tmp_24 {cpp2::regex::make_on_return(cpp2::move(tmp_24_func))}; 
static_cast<void>(cpp2::move(tmp_24));
ctx.set_group_start(24, r.pos);
ctx.set_group_end(24, r.pos);

auto tmp_25_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(24);
}
}
}; 

auto tmp_25 {cpp2::regex::make_on_return(cpp2::move(tmp_25_func))}; 
static_cast<void>(cpp2::move(tmp_25));
ctx.set_group_start(25, r.pos);
ctx.set_group_end(25, r.pos);

auto tmp_26_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(25);
}
}
}; 

auto tmp_26 {cpp2::regex::make_on_return(cpp2::move(tmp_26_func))}; 
static_cast<void>(cpp2::move(tmp_26));
ctx.set_group_start(26, r.pos);
ctx.set_group_end(26, r.pos);

auto tmp_27_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(26);
}
}
}; 

auto tmp_27 {cpp2::regex::make_on_return(cpp2::move(tmp_27_func))}; 
static_cast<void>(cpp2::move(tmp_27));
ctx.set_group_start(27, r.pos);
ctx.set_group_end(27, r.pos);

auto tmp_28_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(27);
}
}
}; 

auto tmp_28 {cpp2::regex::make_on_return(cpp2::move(tmp_28_func))}; 
static_cast<void>(cpp2::move(tmp_28));
ctx.set_group_start(28, r.pos);
ctx.set_group_end(28, r.pos);

auto tmp_29_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(28);
}
}
}; 

auto tmp_29 {cpp2::regex::make_on_return(cpp2::move(tmp_29_func))}; 
static_cast<void>(cpp2::move(tmp_29));
ctx.set_group_start(29, r.pos);
ctx.set_group_end(29, r.pos);

auto tmp_30_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(29);
}
}
}; 

auto tmp_30 {cpp2::regex::make_on_return(cpp2::move(tmp_30_func))}; 
static_cast<void>(cpp2::move(tmp_30));
ctx.set_group_start(30, r.pos);
ctx.set_group_end(30, r.pos);

auto tmp_31_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(30);
}
}
}; 

auto tmp_31 {cpp2::regex::make_on_return(cpp2::move(tmp_31_func))}; 
static_cast<void>(cpp2::move(tmp_31));
ctx.set_group_start(31, r.pos);
ctx.set_group_end(31, r.pos);

auto tmp_32_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(31);
}
}
}; 

auto tmp_32 {cpp2::regex::make_on_return(cpp2::move(tmp_32_func))}; 
static_cast<void>(cpp2::move(tmp_32));
ctx.set_group_start(32, r.pos);
ctx.set_group_end(32, r.pos);

auto tmp_33_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(32);
}
}
}; 

auto tmp_33 {cpp2::regex::make_on_return(cpp2::move(tmp_33_func))}; 
static_cast<void>(cpp2::move(tmp_33));
ctx.set_group_start(33, r.pos);
ctx.set_group_end(33, r.pos);

auto tmp_34_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(33);
}
}
}; 

auto tmp_34 {cpp2::regex::make_on_return(cpp2::move(tmp_34_func))}; 
static_cast<void>(cpp2::move(tmp_34));
ctx.set_group_start(34, r.pos);
ctx.set_group_end(34, r.pos);

auto tmp_35_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(34);
}
}
}; 

auto tmp_35 {cpp2::regex::make_on_return(cpp2::move(tmp_35_func))}; 
static_cast<void>(cpp2::move(tmp_35));
ctx.set_group_start(35, r.pos);
ctx.set_group_end(35, r.pos);

auto tmp_36_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(35);
}
}
}; 

auto tmp_36 {cpp2::regex::make_on_return(cpp2::move(tmp_36_func))}; 
static_cast<void>(cpp2::move(tmp_36));
ctx.set_group_start(36, r.pos);
ctx.set_group_end(36, r.pos);

auto tmp_37_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(36);
}
}
}; 

auto tmp_37 {cpp2::regex::make_on_return(cpp2::move(tmp_37_func))}; 
static_cast<void>(cpp2::move(tmp_37));
ctx.set_group_start(37, r.pos);
ctx.set_group_end(37, r.pos);

auto tmp_38_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(37);
}
}
}; 

auto tmp_38 {cpp2::regex::make_on_return(cpp2::move(tmp_38_func))}; 
static_cast<void>(cpp2::move(tmp_38));
ctx.set_group_start(38, r.pos);
ctx.set_group_end(38, r.pos);

auto tmp_39_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(38);
}
}
}; 

auto tmp_39 {cpp2::regex::make_on_return(cpp2::move(tmp_39_func))}; 
static_cast<void>(cpp2::move(tmp_39));
ctx.set_group_start(39, r.pos);
ctx.set_group_end(39, r.pos);

auto tmp_40_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(39);
}
}
}; 

auto tmp_40 {cpp2::regex::make_on_return(cpp2::move(tmp_40_func))}; 
static_cast<void>(cpp2::move(tmp_40));
ctx.set_group_start(40, r.pos);
ctx.set_group_end(40, r.pos);

auto tmp_41_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(40);
}
}
}; 

auto tmp_41 {cpp2::regex::make_on_return(cpp2::move(tmp_41_func))}; 
static_cast<void>(cpp2::move(tmp_41));
ctx.set_group_start(41, r.pos);
ctx.set_group_end(41, r.pos);

auto tmp_42_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(41);
}
}
}; 

auto tmp_42 {cpp2::regex::make_on_return(cpp2::move(tmp_42_func))}; 
static_cast<void>(cpp2::move(tmp_42));
ctx.set_group_start(42, r.pos);
ctx.set_group_end(42, r.pos);

auto tmp_43_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(42);
}
}
}; 

auto tmp_43 {cpp2::regex::make_on_return(cpp2::move(tmp_43_func))}; 
static_cast<void>(cpp2::move(tmp_43));
ctx.set_group_start(43, r.pos);
ctx.set_group_end(43, r.pos);

auto tmp_44_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(43);
}
}
}; 

auto tmp_44 {cpp2::regex::make_on_return(cpp2::move(tmp_44_func))}; 
static_cast<void>(cpp2::move(tmp_44));
ctx.set_group_start(44, r.pos);
ctx.set_group_end(44, r.pos);

auto tmp_45_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(44);
}
}
}; 

auto tmp_45 {cpp2::regex::make_on_return(cpp2::move(tmp_45_func))}; 
static_cast<void>(cpp2::move(tmp_45));
ctx.set_group_start(45, r.pos);
ctx.set_group_end(45, r.pos);

auto tmp_46_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(45);
}
}
}; 

auto tmp_46 {cpp2::regex::make_on_return(cpp2::move(tmp_46_func))}; 
static_cast<void>(cpp2::move(tmp_46));
ctx.set_group_start(46, r.pos);
ctx.set_group_end(46, r.pos);

auto tmp_47_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(46);
}
}
}; 

auto tmp_47 {cpp2::regex::make_on_return(cpp2::move(tmp_47_func))}; 
static_cast<void>(cpp2::move(tmp_47));
ctx.set_group_start(47, r.pos);
ctx.set_group_end(47, r.pos);

auto tmp_48_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(47);
}
}
}; 

auto tmp_48 {cpp2::regex::make_on_return(cpp2::move(tmp_48_func))}; 
static_cast<void>(cpp2::move(tmp_48));
ctx.set_group_start(48, r.pos);
ctx.set_group_end(48, r.pos);

auto tmp_49_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(48);
}
}
}; 

auto tmp_49 {cpp2::regex::make_on_return(cpp2::move(tmp_49_func))}; 
static_cast<void>(cpp2::move(tmp_49));
ctx.set_group_start(49, r.pos);
ctx.set_group_end(49, r.pos);

auto tmp_50_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(49);
}
}
}; 

auto tmp_50 {cpp2::regex::make_on_return(cpp2::move(tmp_50_func))}; 
static_cast<void>(cpp2::move(tmp_50));
ctx.set_group_start(50, r.pos);
ctx.set_group_end(50, r.pos);

auto tmp_51_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(50);
}
}
}; 

auto tmp_51 {cpp2::regex::make_on_return(cpp2::move(tmp_51_func))}; 
static_cast<void>(cpp2::move(tmp_51));
ctx.set_group_start(51, r.pos);
ctx.set_group_end(51, r.pos);

auto tmp_52_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(51);
}
}
}; 

auto tmp_52 {cpp2::regex::make_on_return(cpp2::move(tmp_52_func))}; 
static_cast<void>(cpp2::move(tmp_52));
ctx.set_group_start(52, r.pos);
ctx.set_group_end(52, r.pos);

auto tmp_53_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(52);
}
}
}; 

auto tmp_53 {cpp2::regex::make_on_return(cpp2::move(tmp_53_func))}; 
static_cast<void>(cpp2::move(tmp_53));
ctx.set_group_start(53, r.pos);
ctx.set_group_end(53, r.pos);

auto tmp_54_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(53);
}
}
}; 

auto tmp_54 {cpp2::regex::make_on_return(cpp2::move(tmp_54_func))}; 
static_cast<void>(cpp2::move(tmp_54));
ctx.set_group_start(54, r.pos);
ctx.set_group_end(54, r.pos);

auto tmp_55_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(54);
}
}
}; 

auto tmp_55 {cpp2::regex::make_on_return(cpp2::move(tmp_55_func))}; 
static_cast<void>(cpp2::move(tmp_55));
ctx.set_group_start(55, r.pos);
ctx.set_group_end(55, r.pos);

auto tmp_56_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(55);
}
}
}; 

auto tmp_56 {cpp2::regex::make_on_return(cpp2::move(tmp_56_func))}; 
static_cast<void>(cpp2::move(tmp_56));
ctx.set_group_start(56, r.pos);
ctx.set_group_end(56, r.pos);

auto tmp_57_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(56);
}
}
}; 

auto tmp_57 {cpp2::regex::make_on_return(cpp2::move(tmp_57_func))}; 
static_cast<void>(cpp2::move(tmp_57));
ctx.set_group_start(57, r.pos);
ctx.set_group_end(57, r.pos);

auto tmp_58_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(57);
}
}
}; 

auto tmp_58 {cpp2::regex::make_on_return(cpp2::move(tmp_58_func))}; 
static_cast<void>(cpp2::move(tmp_58));
ctx.set_group_start(58, r.pos);
ctx.set_group_end(58, r.pos);

auto tmp_59_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(58);
}
}
}; 

auto tmp_59 {cpp2::regex::make_on_return(cpp2::move(tmp_59_func))}; 
static_cast<void>(cpp2::move(tmp_59));
ctx.set_group_start(59, r.pos);
ctx.set_group_end(59, r.pos);

auto tmp_60_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(59);
}
}
}; 

auto tmp_60 {cpp2::regex::make_on_return(cpp2::move(tmp_60_func))}; 
static_cast<void>(cpp2::move(tmp_60));
ctx.set_group_start(60, r.pos);
ctx.set_group_end(60, r.pos);

auto tmp_61_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(60);
}
}
}; 

auto tmp_61 {cpp2::regex::make_on_return(cpp2::move(tmp_61_func))}; 
static_cast<void>(cpp2::move(tmp_61));
ctx.set_group_start(61, r.pos);
ctx.set_group_end(61, r.pos);

auto tmp_62_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(61);
}
}
}; 

auto tmp_62 {cpp2::regex::make_on_return(cpp2::move(tmp_62_func))}; 
static_cast<void>(cpp2::move(tmp_62));
ctx.set_group_start(62, r.pos);
ctx.set_group_end(62, r.pos);

auto tmp_63_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(62);
}
}
}; 

auto tmp_63 {cpp2::regex::make_on_return(cpp2::move(tmp_63_func))}; 
static_cast<void>(cpp2::move(tmp_63));
ctx.set_group_start(63, r.pos);
ctx.set_group_end(63, r.pos);

auto tmp_64_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(63);
}
}
}; 

auto tmp_64 {cpp2::regex::make_on_return(cpp2::move(tmp_64_func))}; 
static_cast<void>(cpp2::move(tmp_64));
ctx.set_group_start(64, r.pos);
ctx.set_group_end(64, r.pos);

auto tmp_65_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(64);
}
}
}; 

auto tmp_65 {cpp2::regex::make_on_return(cpp2::move(tmp_65_func))}; 
static_cast<void>(cpp2::move(tmp_65));
ctx.set_group_start(65, r.pos);
ctx.set_group_end(65, r.pos);

auto tmp_66_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(65);
}
}
}; 

auto tmp_66 {cpp2::regex::make_on_return(cpp2::move(tmp_66_func))}; 
static_cast<void>(cpp2::move(tmp_66));
ctx.set_group_start(66, r.pos);
ctx.set_group_end(66, r.pos);

auto tmp_67_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(66);
}
}
}; 

auto tmp_67 {cpp2::regex::make_on_return(cpp2::move(tmp_67_func))}; 
static_cast<void>(cpp2::move(tmp_67));
ctx.set_group_start(67, r.pos);
ctx.set_group_end(67, r.pos);

auto tmp_68_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(67);
}
}
}; 

auto tmp_68 {cpp2::regex::make_on_return(cpp2::move(tmp_68_func))}; 
static_cast<void>(cpp2::move(tmp_68));
ctx.set_group_start(68, r.pos);
ctx.set_group_end(68, r.pos);

auto tmp_69_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(68);
}
}
}; 

auto tmp_69 {cpp2::regex::make_on_return(cpp2::move(tmp_69_func))}; 
static_cast<void>(cpp2::move(tmp_69));
ctx.set_group_start(69, r.pos);
ctx.set_group_end(69, r.pos);

auto tmp_70_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(69);
}
}
}; 

auto tmp_70 {cpp2::regex::make_on_return(cpp2::move(tmp_70_func))}; 
static_cast<void>(cpp2::move(tmp_70));
ctx.set_group_start(70, r.pos);
ctx.set_group_end(70, r.pos);

auto tmp_71_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(70);
}
}
}; 

auto tmp_71 {cpp2::regex::make_on_return(cpp2::move(tmp_71_func))}; 
static_cast<void>(cpp2::move(tmp_71));
ctx.set_group_start(71, r.pos);
ctx.set_group_end(71, r.pos);

auto tmp_72_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(71);
}
}
}; 

auto tmp_72 {cpp2::regex::make_on_return(cpp2::move(tmp_72_func))}; 
static_cast<void>(cpp2::move(tmp_72));
ctx.set_group_start(72, r.pos);
ctx.set_group_end(72, r.pos);

auto tmp_73_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(72);
}
}
}; 

auto tmp_73 {cpp2::regex::make_on_return(cpp2::move(tmp_73_func))}; 
static_cast<void>(cpp2::move(tmp_73));
ctx.set_group_start(73, r.pos);
ctx.set_group_end(73, r.pos);

auto tmp_74_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(73);
}
}
}; 

auto tmp_74 {cpp2::regex::make_on_return(cpp2::move(tmp_74_func))}; 
static_cast<void>(cpp2::move(tmp_74));
ctx.set_group_start(74, r.pos);
ctx.set_group_end(74, r.pos);

auto tmp_75_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(74);
}
}
}; 

auto tmp_75 {cpp2::regex::make_on_return(cpp2::move(tmp_75_func))}; 
static_cast<void>(cpp2::move(tmp_75));
ctx.set_group_start(75, r.pos);
ctx.set_group_end(75, r.pos);

auto tmp_76_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(75);
}
}
}; 

auto tmp_76 {cpp2::regex::make_on_return(cpp2::move(tmp_76_func))}; 
static_cast<void>(cpp2::move(tmp_76));
ctx.set_group_start(76, r.pos);
ctx.set_group_end(76, r.pos);

auto tmp_77_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(76);
}
}
}; 

auto tmp_77 {cpp2::regex::make_on_return(cpp2::move(tmp_77_func))}; 
static_cast<void>(cpp2::move(tmp_77));
ctx.set_group_start(77, r.pos);
ctx.set_group_end(77, r.pos);

auto tmp_78_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(77);
}
}
}; 

auto tmp_78 {cpp2::regex::make_on_return(cpp2::move(tmp_78_func))}; 
static_cast<void>(cpp2::move(tmp_78));
ctx.set_group_start(78, r.pos);
ctx.set_group_end(78, r.pos);

auto tmp_79_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(78);
}
}
}; 

auto tmp_79 {cpp2::regex::make_on_return(cpp2::move(tmp_79_func))}; 
static_cast<void>(cpp2::move(tmp_79));
ctx.set_group_start(79, r.pos);
ctx.set_group_end(79, r.pos);

auto tmp_80_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(79);
}
}
}; 

auto tmp_80 {cpp2::regex::make_on_return(cpp2::move(tmp_80_func))}; 
static_cast<void>(cpp2::move(tmp_80));
ctx.set_group_start(80, r.pos);
ctx.set_group_end(80, r.pos);

auto tmp_81_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(80);
}
}
}; 

auto tmp_81 {cpp2::regex::make_on_return(cpp2::move(tmp_81_func))}; 
static_cast<void>(cpp2::move(tmp_81));
ctx.set_group_start(81, r.pos);
ctx.set_group_end(81, r.pos);

auto tmp_82_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(81);
}
}
}; 

auto tmp_82 {cpp2::regex::make_on_return(cpp2::move(tmp_82_func))}; 
static_cast<void>(cpp2::move(tmp_82));
ctx.set_group_start(82, r.pos);
ctx.set_group_end(82, r.pos);

auto tmp_83_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(82);
}
}
}; 

auto tmp_83 {cpp2::regex::make_on_return(cpp2::move(tmp_83_func))}; 
static_cast<void>(cpp2::move(tmp_83));
ctx.set_group_start(83, r.pos);
ctx.set_group_end(83, r.pos);

auto tmp_84_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(83);
}
}
}; 

auto tmp_84 {cpp2::regex::make_on_return(cpp2::move(tmp_84_func))}; 
static_cast<void>(cpp2::move(tmp_84));
ctx.set_group_start(84, r.pos);
ctx.set_group_end(84, r.pos);

auto tmp_85_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(84);
}
}
}; 

auto tmp_85 {cpp2::regex::make_on_return(cpp2::move(tmp_85_func))}; 
static_cast<void>(cpp2::move(tmp_85));
ctx.set_group_start(85, r.pos);
ctx.set_group_end(85, r.pos);

auto tmp_86_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(85);
}
}
}; 

auto tmp_86 {cpp2::regex::make_on_return(cpp2::move(tmp_86_func))}; 
static_cast<void>(cpp2::move(tmp_86));
ctx.set_group_start(86, r.pos);
ctx.set_group_end(86, r.pos);

auto tmp_87_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(86);
}
}
}; 

auto tmp_87 {cpp2::regex::make_on_return(cpp2::move(tmp_87_func))}; 
static_cast<void>(cpp2::move(tmp_87));
ctx.set_group_start(87, r.pos);
ctx.set_group_end(87, r.pos);

auto tmp_88_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(87);
}
}
}; 

auto tmp_88 {cpp2::regex::make_on_return(cpp2::move(tmp_88_func))}; 
static_cast<void>(cpp2::move(tmp_88));
ctx.set_group_start(88, r.pos);
ctx.set_group_end(88, r.pos);

auto tmp_89_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(88);
}
}
}; 

auto tmp_89 {cpp2::regex::make_on_return(cpp2::move(tmp_89_func))}; 
static_cast<void>(cpp2::move(tmp_89));
ctx.set_group_start(89, r.pos);
ctx.set_group_end(89, r.pos);

auto tmp_90_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(89);
}
}
}; 

auto tmp_90 {cpp2::regex::make_on_return(cpp2::move(tmp_90_func))}; 
static_cast<void>(cpp2::move(tmp_90));
ctx.set_group_start(90, r.pos);
ctx.set_group_end(90, r.pos);

auto tmp_91_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(90);
}
}
}; 

auto tmp_91 {cpp2::regex::make_on_return(cpp2::move(tmp_91_func))}; 
static_cast<void>(cpp2::move(tmp_91));
ctx.set_group_start(91, r.pos);
ctx.set_group_end(91, r.pos);

auto tmp_92_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(91);
}
}
}; 

auto tmp_92 {cpp2::regex::make_on_return(cpp2::move(tmp_92_func))}; 
static_cast<void>(cpp2::move(tmp_92));
ctx.set_group_start(92, r.pos);
ctx.set_group_end(92, r.pos);

auto tmp_93_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(92);
}
}
}; 

auto tmp_93 {cpp2::regex::make_on_return(cpp2::move(tmp_93_func))}; 
static_cast<void>(cpp2::move(tmp_93));
ctx.set_group_start(93, r.pos);
ctx.set_group_end(93, r.pos);

auto tmp_94_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(93);
}
}
}; 

auto tmp_94 {cpp2::regex::make_on_return(cpp2::move(tmp_94_func))}; 
static_cast<void>(cpp2::move(tmp_94));
ctx.set_group_start(94, r.pos);
ctx.set_group_end(94, r.pos);

auto tmp_95_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(94);
}
}
}; 

auto tmp_95 {cpp2::regex::make_on_return(cpp2::move(tmp_95_func))}; 
static_cast<void>(cpp2::move(tmp_95));
ctx.set_group_start(95, r.pos);
ctx.set_group_end(95, r.pos);

auto tmp_96_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(95);
}
}
}; 

auto tmp_96 {cpp2::regex::make_on_return(cpp2::move(tmp_96_func))}; 
static_cast<void>(cpp2::move(tmp_96));
ctx.set_group_start(96, r.pos);
ctx.set_group_end(96, r.pos);

auto tmp_97_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(96);
}
}
}; 

auto tmp_97 {cpp2::regex::make_on_return(cpp2::move(tmp_97_func))}; 
static_cast<void>(cpp2::move(tmp_97));
ctx.set_group_start(97, r.pos);
ctx.set_group_end(97, r.pos);

auto tmp_98_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(97);
}
}
}; 

auto tmp_98 {cpp2::regex::make_on_return(cpp2::move(tmp_98_func))}; 
static_cast<void>(cpp2::move(tmp_98));
ctx.set_group_start(98, r.pos);
ctx.set_group_end(98, r.pos);

auto tmp_99_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(98);
}
}
}; 

auto tmp_99 {cpp2::regex::make_on_return(cpp2::move(tmp_99_func))}; 
static_cast<void>(cpp2::move(tmp_99));
ctx.set_group_start(99, r.pos);
ctx.set_group_end(99, r.pos);

auto tmp_100_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(99);
}
}
}; 

auto tmp_100 {cpp2::regex::make_on_return(cpp2::move(tmp_100_func))}; 
static_cast<void>(cpp2::move(tmp_100));
ctx.set_group_start(100, r.pos);
ctx.set_group_end(100, r.pos);

auto tmp_101_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(100);
}
}
}; 

auto tmp_101 {cpp2::regex::make_on_return(cpp2::move(tmp_101_func))}; 
static_cast<void>(cpp2::move(tmp_101));
ctx.set_group_start(101, r.pos);
ctx.set_group_end(101, r.pos);

auto tmp_102_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(101);
}
}
}; 

auto tmp_102 {cpp2::regex::make_on_return(cpp2::move(tmp_102_func))}; 
static_cast<void>(cpp2::move(tmp_102));
ctx.set_group_start(102, r.pos);
ctx.set_group_end(102, r.pos);

auto tmp_103_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(102);
}
}
}; 

auto tmp_103 {cpp2::regex::make_on_return(cpp2::move(tmp_103_func))}; 
static_cast<void>(cpp2::move(tmp_103));
ctx.set_group_start(103, r.pos);
ctx.set_group_end(103, r.pos);

auto tmp_104_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(103);
}
}
}; 

auto tmp_104 {cpp2::regex::make_on_return(cpp2::move(tmp_104_func))}; 
static_cast<void>(cpp2::move(tmp_104));
ctx.set_group_start(104, r.pos);
ctx.set_group_end(104, r.pos);

auto tmp_105_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(104);
}
}
}; 

auto tmp_105 {cpp2::regex::make_on_return(cpp2::move(tmp_105_func))}; 
static_cast<void>(cpp2::move(tmp_105));
ctx.set_group_start(105, r.pos);
ctx.set_group_end(105, r.pos);

auto tmp_106_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(105);
}
}
}; 

auto tmp_106 {cpp2::regex::make_on_return(cpp2::move(tmp_106_func))}; 
static_cast<void>(cpp2::move(tmp_106));
ctx.set_group_start(106, r.pos);
ctx.set_group_end(106, r.pos);

auto tmp_107_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(106);
}
}
}; 

auto tmp_107 {cpp2::regex::make_on_return(cpp2::move(tmp_107_func))}; 
static_cast<void>(cpp2::move(tmp_107));
ctx.set_group_start(107, r.pos);
ctx.set_group_end(107, r.pos);

auto tmp_108_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(107);
}
}
}; 

auto tmp_108 {cpp2::regex::make_on_return(cpp2::move(tmp_108_func))}; 
static_cast<void>(cpp2::move(tmp_108));
ctx.set_group_start(108, r.pos);
ctx.set_group_end(108, r.pos);

auto tmp_109_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(108);
}
}
}; 

auto tmp_109 {cpp2::regex::make_on_return(cpp2::move(tmp_109_func))}; 
static_cast<void>(cpp2::move(tmp_109));
ctx.set_group_start(109, r.pos);
ctx.set_group_end(109, r.pos);

auto tmp_110_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(109);
}
}
}; 

auto tmp_110 {cpp2::regex::make_on_return(cpp2::move(tmp_110_func))}; 
static_cast<void>(cpp2::move(tmp_110));
ctx.set_group_start(110, r.pos);
ctx.set_group_end(110, r.pos);

auto tmp_111_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(110);
}
}
}; 

auto tmp_111 {cpp2::regex::make_on_return(cpp2::move(tmp_111_func))}; 
static_cast<void>(cpp2::move(tmp_111));
ctx.set_group_start(111, r.pos);
ctx.set_group_end(111, r.pos);

auto tmp_112_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(111);
}
}
}; 

auto tmp_112 {cpp2::regex::make_on_return(cpp2::move(tmp_112_func))}; 
static_cast<void>(cpp2::move(tmp_112));
ctx.set_group_start(112, r.pos);
ctx.set_group_end(112, r.pos);

auto tmp_113_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(112);
}
}
}; 

auto tmp_113 {cpp2::regex::make_on_return(cpp2::move(tmp_113_func))}; 
static_cast<void>(cpp2::move(tmp_113));
ctx.set_group_start(113, r.pos);
ctx.set_group_end(113, r.pos);

auto tmp_114_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(113);
}
}
}; 

auto tmp_114 {cpp2::regex::make_on_return(cpp2::move(tmp_114_func))}; 
static_cast<void>(cpp2::move(tmp_114));
ctx.set_group_start(114, r.pos);
ctx.set_group_end(114, r.pos);

auto tmp_115_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(114);
}
}
}; 

auto tmp_115 {cpp2::regex::make_on_return(cpp2::move(tmp_115_func))}; 
static_cast<void>(cpp2::move(tmp_115));
ctx.set_group_start(115, r.pos);
ctx.set_group_end(115, r.pos);

auto tmp_116_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(115);
}
}
}; 

auto tmp_116 {cpp2::regex::make_on_return(cpp2::move(tmp_116_func))}; 
static_cast<void>(cpp2::move(tmp_116));
ctx.set_group_start(116, r.pos);
ctx.set_group_end(116, r.pos);

auto tmp_117_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(116);
}
}
}; 

auto tmp_117 {cpp2::regex::make_on_return(cpp2::move(tmp_117_func))}; 
static_cast<void>(cpp2::move(tmp_117));
ctx.set_group_start(117, r.pos);
ctx.set_group_end(117, r.pos);

auto tmp_118_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(117);
}
}
}; 

auto tmp_118 {cpp2::regex::make_on_return(cpp2::move(tmp_118_func))}; 
static_cast<void>(cpp2::move(tmp_118));
ctx.set_group_start(118, r.pos);
ctx.set_group_end(118, r.pos);

auto tmp_119_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(118);
}
}
}; 

auto tmp_119 {cpp2::regex::make_on_return(cpp2::move(tmp_119_func))}; 
static_cast<void>(cpp2::move(tmp_119));
ctx.set_group_start(119, r.pos);
ctx.set_group_end(119, r.pos);

auto tmp_120_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(119);
}
}
}; 

auto tmp_120 {cpp2::regex::make_on_return(cpp2::move(tmp_120_func))}; 
static_cast<void>(cpp2::move(tmp_120));
ctx.set_group_start(120, r.pos);
ctx.set_group_end(120, r.pos);

auto tmp_121_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(120);
}
}
}; 

auto tmp_121 {cpp2::regex::make_on_return(cpp2::move(tmp_121_func))}; 
static_cast<void>(cpp2::move(tmp_121));
ctx.set_group_start(121, r.pos);
ctx.set_group_end(121, r.pos);

auto tmp_122_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(121);
}
}
}; 

auto tmp_122 {cpp2::regex::make_on_return(cpp2::move(tmp_122_func))}; 
static_cast<void>(cpp2::move(tmp_122));
ctx.set_group_start(122, r.pos);
ctx.set_group_end(122, r.pos);

auto tmp_123_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(122);
}
}
}; 

auto tmp_123 {cpp2::regex::make_on_return(cpp2::move(tmp_123_func))}; 
static_cast<void>(cpp2::move(tmp_123));
ctx.set_group_start(123, r.pos);
ctx.set_group_end(123, r.pos);

auto tmp_124_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(123);
}
}
}; 

auto tmp_124 {cpp2::regex::make_on_return(cpp2::move(tmp_124_func))}; 
static_cast<void>(cpp2::move(tmp_124));
ctx.set_group_start(124, r.pos);
ctx.set_group_end(124, r.pos);

auto tmp_125_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(124);
}
}
}; 

auto tmp_125 {cpp2::regex::make_on_return(cpp2::move(tmp_125_func))}; 
static_cast<void>(cpp2::move(tmp_125));
ctx.set_group_start(125, r.pos);
ctx.set_group_end(125, r.pos);

auto tmp_126_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(125);
}
}
}; 

auto tmp_126 {cpp2::regex::make_on_return(cpp2::move(tmp_126_func))}; 
static_cast<void>(cpp2::move(tmp_126));
ctx.set_group_start(126, r.pos);
ctx.set_group_end(126, r.pos);

auto tmp_127_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(126);
}
}
}; 

auto tmp_127 {cpp2::regex::make_on_return(cpp2::move(tmp_127_func))}; 
static_cast<void>(cpp2::move(tmp_127));
ctx.set_group_start(127, r.pos);
ctx.set_group_end(127, r.pos);

auto tmp_128_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(127);
}
}
}; 

auto tmp_128 {cpp2::regex::make_on_return(cpp2::move(tmp_128_func))}; 
static_cast<void>(cpp2::move(tmp_128));
ctx.set_group_start(128, r.pos);
ctx.set_group_end(128, r.pos);

auto tmp_129_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(128);
}
}
}; 

auto tmp_129 {cpp2::regex::make_on_return(cpp2::move(tmp_129_func))}; 
static_cast<void>(cpp2::move(tmp_129));
ctx.set_group_start(129, r.pos);
ctx.set_group_end(129, r.pos);

auto tmp_130_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(129);
}
}
}; 

auto tmp_130 {cpp2::regex::make_on_return(cpp2::move(tmp_130_func))}; 
static_cast<void>(cpp2::move(tmp_130));
ctx.set_group_start(130, r.pos);
ctx.set_group_end(130, r.pos);

auto tmp_131_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(130);
}
}
}; 

auto tmp_131 {cpp2::regex::make_on_return(cpp2::move(tmp_131_func))}; 
static_cast<void>(cpp2::move(tmp_131));
ctx.set_group_start(131, r.pos);
ctx.set_group_end(131, r.pos);

auto tmp_132_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(131);
}
}
}; 

auto tmp_132 {cpp2::regex::make_on_return(cpp2::move(tmp_132_func))}; 
static_cast<void>(cpp2::move(tmp_132));
ctx.set_group_start(132, r.pos);
ctx.set_group_end(132, r.pos);

auto tmp_133_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(132);
}
}
}; 

auto tmp_133 {cpp2::regex::make_on_return(cpp2::move(tmp_133_func))}; 
static_cast<void>(cpp2::move(tmp_133));
ctx.set_group_start(133, r.pos);
ctx.set_group_end(133, r.pos);

auto tmp_134_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(133);
}
}
}; 

auto tmp_134 {cpp2::regex::make_on_return(cpp2::move(tmp_134_func))}; 
static_cast<void>(cpp2::move(tmp_134));
ctx.set_group_start(134, r.pos);
ctx.set_group_end(134, r.pos);

auto tmp_135_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(134);
}
}
}; 

auto tmp_135 {cpp2::regex::make_on_return(cpp2::move(tmp_135_func))}; 
static_cast<void>(cpp2::move(tmp_135));
ctx.set_group_start(135, r.pos);
ctx.set_group_end(135, r.pos);

auto tmp_136_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(135);
}
}
}; 

auto tmp_136 {cpp2::regex::make_on_return(cpp2::move(tmp_136_func))}; 
static_cast<void>(cpp2::move(tmp_136));
ctx.set_group_start(136, r.pos);
ctx.set_group_end(136, r.pos);

auto tmp_137_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(136);
}
}
}; 

auto tmp_137 {cpp2::regex::make_on_return(cpp2::move(tmp_137_func))}; 
static_cast<void>(cpp2::move(tmp_137));
ctx.set_group_start(137, r.pos);
ctx.set_group_end(137, r.pos);

auto tmp_138_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(137);
}
}
}; 

auto tmp_138 {cpp2::regex::make_on_return(cpp2::move(tmp_138_func))}; 
static_cast<void>(cpp2::move(tmp_138));
ctx.set_group_start(138, r.pos);
ctx.set_group_end(138, r.pos);

auto tmp_139_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(138);
}
}
}; 

auto tmp_139 {cpp2::regex::make_on_return(cpp2::move(tmp_139_func))}; 
static_cast<void>(cpp2::move(tmp_139));
ctx.set_group_start(139, r.pos);
ctx.set_group_end(139, r.pos);

auto tmp_140_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(139);
}
}
}; 

auto tmp_140 {cpp2::regex::make_on_return(cpp2::move(tmp_140_func))}; 
static_cast<void>(cpp2::move(tmp_140));
ctx.set_group_start(140, r.pos);
ctx.set_group_end(140, r.pos);

auto tmp_141_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(140);
}
}
}; 

auto tmp_141 {cpp2::regex::make_on_return(cpp2::move(tmp_141_func))}; 
static_cast<void>(cpp2::move(tmp_141));
ctx.set_group_start(141, r.pos);
ctx.set_group_end(141, r.pos);

auto tmp_142_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(141);
}
}
}; 

auto tmp_142 {cpp2::regex::make_on_return(cpp2::move(tmp_142_func))}; 
static_cast<void>(cpp2::move(tmp_142));
ctx.set_group_start(142, r.pos);
ctx.set_group_end(142, r.pos);

auto tmp_143_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(142);
}
}
}; 

auto tmp_143 {cpp2::regex::make_on_return(cpp2::move(tmp_143_func))}; 
static_cast<void>(cpp2::move(tmp_143));
ctx.set_group_start(143, r.pos);
ctx.set_group_end(143, r.pos);

auto tmp_144_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(143);
}
}
}; 

auto tmp_144 {cpp2::regex::make_on_return(cpp2::move(tmp_144_func))}; 
static_cast<void>(cpp2::move(tmp_144));
ctx.set_group_start(144, r.pos);
ctx.set_group_end(144, r.pos);

auto tmp_145_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(144);
}
}
}; 

auto tmp_145 {cpp2::regex::make_on_return(cpp2::move(tmp_145_func))}; 
static_cast<void>(cpp2::move(tmp_145));
ctx.set_group_start(145, r.pos);
ctx.set_group_end(145, r.pos);

auto tmp_146_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(145);
}
}
}; 

auto tmp_146 {cpp2::regex::make_on_return(cpp2::move(tmp_146_func))}; 
static_cast<void>(cpp2::move(tmp_146));
ctx.set_group_start(146, r.pos);
ctx.set_group_end(146, r.pos);

auto tmp_147_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(146);
}
}
}; 

auto tmp_147 {cpp2::regex::make_on_return(cpp2::move(tmp_147_func))}; 
static_cast<void>(cpp2::move(tmp_147));
ctx.set_group_start(147, r.pos);
ctx.set_group_end(147, r.pos);

auto tmp_148_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(147);
}
}
}; 

auto tmp_148 {cpp2::regex::make_on_return(cpp2::move(tmp_148_func))}; 
static_cast<void>(cpp2::move(tmp_148));
ctx.set_group_start(148, r.pos);
ctx.set_group_end(148, r.pos);

auto tmp_149_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(148);
}
}
}; 

auto tmp_149 {cpp2::regex::make_on_return(cpp2::move(tmp_149_func))}; 
static_cast<void>(cpp2::move(tmp_149));
ctx.set_group_start(149, r.pos);
ctx.set_group_end(149, r.pos);

auto tmp_150_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(149);
}
}
}; 

auto tmp_150 {cpp2::regex::make_on_return(cpp2::move(tmp_150_func))}; 
static_cast<void>(cpp2::move(tmp_150));
ctx.set_group_start(150, r.pos);
ctx.set_group_end(150, r.pos);

auto tmp_151_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(150);
}
}
}; 

auto tmp_151 {cpp2::regex::make_on_return(cpp2::move(tmp_151_func))}; 
static_cast<void>(cpp2::move(tmp_151));
ctx.set_group_start(151, r.pos);
ctx.set_group_end(151, r.pos);

auto tmp_152_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(151);
}
}
}; 

auto tmp_152 {cpp2::regex::make_on_return(cpp2::move(tmp_152_func))}; 
static_cast<void>(cpp2::move(tmp_152));
ctx.set_group_start(152, r.pos);
ctx.set_group_end(152, r.pos);

auto tmp_153_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(152);
}
}
}; 

auto tmp_153 {cpp2::regex::make_on_return(cpp2::move(tmp_153_func))}; 
static_cast<void>(cpp2::move(tmp_153));
ctx.set_group_start(153, r.pos);
ctx.set_group_end(153, r.pos);

auto tmp_154_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(153);
}
}
}; 

auto tmp_154 {cpp2::regex::make_on_return(cpp2::move(tmp_154_func))}; 
static_cast<void>(cpp2::move(tmp_154));
ctx.set_group_start(154, r.pos);
ctx.set_group_end(154, r.pos);

auto tmp_155_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(154);
}
}
}; 

auto tmp_155 {cpp2::regex::make_on_return(cpp2::move(tmp_155_func))}; 
static_cast<void>(cpp2::move(tmp_155));
ctx.set_group_start(155, r.pos);
ctx.set_group_end(155, r.pos);

auto tmp_156_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(155);
}
}
}; 

auto tmp_156 {cpp2::regex::make_on_return(cpp2::move(tmp_156_func))}; 
static_cast<void>(cpp2::move(tmp_156));
ctx.set_group_start(156, r.pos);
ctx.set_group_end(156, r.pos);

auto tmp_157_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(156);
}
}
}; 

auto tmp_157 {cpp2::regex::make_on_return(cpp2::move(tmp_157_func))}; 
static_cast<void>(cpp2::move(tmp_157));
ctx.set_group_start(157, r.pos);
ctx.set_group_end(157, r.pos);

auto tmp_158_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(157);
}
}
}; 

auto tmp_158 {cpp2::regex::make_on_return(cpp2::move(tmp_158_func))}; 
static_cast<void>(cpp2::move(tmp_158));
ctx.set_group_start(158, r.pos);
ctx.set_group_end(158, r.pos);

auto tmp_159_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(158);
}
}
}; 

auto tmp_159 {cpp2::regex::make_on_return(cpp2::move(tmp_159_func))}; 
static_cast<void>(cpp2::move(tmp_159));
ctx.set_group_start(159, r.pos);
ctx.set_group_end(159, r.pos);

auto tmp_160_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(159);
}
}
}; 

auto tmp_160 {cpp2::regex::make_on_return(cpp2::move(tmp_160_func))}; 
static_cast<void>(cpp2::move(tmp_160));
ctx.set_group_start(160, r.pos);
ctx.set_group_end(160, r.pos);

auto tmp_161_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(160);
}
}
}; 

auto tmp_161 {cpp2::regex::make_on_return(cpp2::move(tmp_161_func))}; 
static_cast<void>(cpp2::move(tmp_161));
ctx.set_group_start(161, r.pos);
ctx.set_group_end(161, r.pos);

auto tmp_162_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(161);
}
}
}; 

auto tmp_162 {cpp2::regex::make_on_return(cpp2::move(tmp_162_func))}; 
static_cast<void>(cpp2::move(tmp_162));
ctx.set_group_start(162, r.pos);
ctx.set_group_end(162, r.pos);

auto tmp_163_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(162);
}
}
}; 

auto tmp_163 {cpp2::regex::make_on_return(cpp2::move(tmp_163_func))}; 
static_cast<void>(cpp2::move(tmp_163));
ctx.set_group_start(163, r.pos);
ctx.set_group_end(163, r.pos);

auto tmp_164_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(163);
}
}
}; 

auto tmp_164 {cpp2::regex::make_on_return(cpp2::move(tmp_164_func))}; 
static_cast<void>(cpp2::move(tmp_164));
ctx.set_group_start(164, r.pos);
ctx.set_group_end(164, r.pos);

auto tmp_165_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(164);
}
}
}; 

auto tmp_165 {cpp2::regex::make_on_return(cpp2::move(tmp_165_func))}; 
static_cast<void>(cpp2::move(tmp_165));
ctx.set_group_start(165, r.pos);
ctx.set_group_end(165, r.pos);

auto tmp_166_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(165);
}
}
}; 

auto tmp_166 {cpp2::regex::make_on_return(cpp2::move(tmp_166_func))}; 
static_cast<void>(cpp2::move(tmp_166));
ctx.set_group_start(166, r.pos);
ctx.set_group_end(166, r.pos);

auto tmp_167_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(166);
}
}
}; 

auto tmp_167 {cpp2::regex::make_on_return(cpp2::move(tmp_167_func))}; 
static_cast<void>(cpp2::move(tmp_167));
ctx.set_group_start(167, r.pos);
ctx.set_group_end(167, r.pos);

auto tmp_168_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(167);
}
}
}; 

auto tmp_168 {cpp2::regex::make_on_return(cpp2::move(tmp_168_func))}; 
static_cast<void>(cpp2::move(tmp_168));
ctx.set_group_start(168, r.pos);
ctx.set_group_end(168, r.pos);

auto tmp_169_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(168);
}
}
}; 

auto tmp_169 {cpp2::regex::make_on_return(cpp2::move(tmp_169_func))}; 
static_cast<void>(cpp2::move(tmp_169));
ctx.set_group_start(169, r.pos);
ctx.set_group_end(169, r.pos);

auto tmp_170_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(169);
}
}
}; 

auto tmp_170 {cpp2::regex::make_on_return(cpp2::move(tmp_170_func))}; 
static_cast<void>(cpp2::move(tmp_170));
ctx.set_group_start(170, r.pos);
ctx.set_group_end(170, r.pos);

auto tmp_171_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(170);
}
}
}; 

auto tmp_171 {cpp2::regex::make_on_return(cpp2::move(tmp_171_func))}; 
static_cast<void>(cpp2::move(tmp_171));
ctx.set_group_start(171, r.pos);
ctx.set_group_end(171, r.pos);

auto tmp_172_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(171);
}
}
}; 

auto tmp_172 {cpp2::regex::make_on_return(cpp2::move(tmp_172_func))}; 
static_cast<void>(cpp2::move(tmp_172));
ctx.set_group_start(172, r.pos);
ctx.set_group_end(172, r.pos);

auto tmp_173_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(172);
}
}
}; 

auto tmp_173 {cpp2::regex::make_on_return(cpp2::move(tmp_173_func))}; 
static_cast<void>(cpp2::move(tmp_173));
ctx.set_group_start(173, r.pos);
ctx.set_group_end(173, r.pos);

auto tmp_174_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(173);
}
}
}; 

auto tmp_174 {cpp2::regex::make_on_return(cpp2::move(tmp_174_func))}; 
static_cast<void>(cpp2::move(tmp_174));
ctx.set_group_start(174, r.pos);
ctx.set_group_end(174, r.pos);

auto tmp_175_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(174);
}
}
}; 

auto tmp_175 {cpp2::regex::make_on_return(cpp2::move(tmp_175_func))}; 
static_cast<void>(cpp2::move(tmp_175));
ctx.set_group_start(175, r.pos);
ctx.set_group_end(175, r.pos);

auto tmp_176_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(175);
}
}
}; 

auto tmp_176 {cpp2::regex::make_on_return(cpp2::move(tmp_176_func))}; 
static_cast<void>(cpp2::move(tmp_176));
ctx.set_group_start(176, r.pos);
ctx.set_group_end(176, r.pos);

auto tmp_177_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(176);
}
}
}; 

auto tmp_177 {cpp2::regex::make_on_return(cpp2::move(tmp_177_func))}; 
static_cast<void>(cpp2::move(tmp_177));
ctx.set_group_start(177, r.pos);
ctx.set_group_end(177, r.pos);

auto tmp_178_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(177);
}
}
}; 

auto tmp_178 {cpp2::regex::make_on_return(cpp2::move(tmp_178_func))}; 
static_cast<void>(cpp2::move(tmp_178));
ctx.set_group_start(178, r.pos);
ctx.set_group_end(178, r.pos);

auto tmp_179_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(178);
}
}
}; 

auto tmp_179 {cpp2::regex::make_on_return(cpp2::move(tmp_179_func))}; 
static_cast<void>(cpp2::move(tmp_179));
ctx.set_group_start(179, r.pos);
ctx.set_group_end(179, r.pos);

auto tmp_180_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(179);
}
}
}; 

auto tmp_180 {cpp2::regex::make_on_return(cpp2::move(tmp_180_func))}; 
static_cast<void>(cpp2::move(tmp_180));
ctx.set_group_start(180, r.pos);
ctx.set_group_end(180, r.pos);

auto tmp_181_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(180);
}
}
}; 

auto tmp_181 {cpp2::regex::make_on_return(cpp2::move(tmp_181_func))}; 
static_cast<void>(cpp2::move(tmp_181));
ctx.set_group_start(181, r.pos);

std::array<char,1 + 1> str_tmp_182 {"a"}; 
if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),1)) {
r.matched = false;
break;
}
{
int i{0};
for( ; cpp2::impl::cmp_less(i,1); (i += 1) ) {
if (CPP2_ASSERT_IN_BOUNDS(str_tmp_182, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
}
}
if (r.matched) {r.pos += 1;}
else {break;}
ctx.set_group_end(181, r.pos);

auto tmp_183_func {
[&, _1 = (&r), _2 = (&ctx)]() mutable -> void{
if (!((*cpp2::impl::assert_not_null(_1)).matched)) {
(*cpp2::impl::assert_not_null(_2)).set_group_invalid(181);
}
}
}; 

auto tmp_183 {cpp2::regex::make_on_return(cpp2::move(tmp_183_func))}; 
static_cast<void>(cpp2::move(tmp_183));
}
 while ( 
false
);
if (r.matched) {
r = other(r.pos, ctx);
}
else {
r.pos = ctx.end;
}
return r; 
}


template <typename Iter, typename CharT> auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::reset_1::operator()(auto& ctx) const& -> void{
ctx.set_group_invalid(1);
ctx.set_group_invalid(2);
ctx.set_group_invalid(3);
ctx.set_group_invalid(4);
ctx.set_group_invalid(5);
ctx.set_group_invalid(6);
ctx.set_group_invalid(7);
ctx.set_group_invalid(8);
ctx.set_group_invalid(9);
ctx.set_group_invalid(10);
ctx.set_group_invalid(11);
ctx.set_group_invalid(12);
ctx.set_group_invalid(13);
ctx.set_group_invalid(14);
ctx.set_group_invalid(15);
ctx.set_group_invalid(16);
ctx.set_group_invalid(17);
ctx.set_group_invalid(18);
ctx.set_group_invalid(19);
ctx.set_group_invalid(20);
ctx.set_group_invalid(21);
ctx.set_group_invalid(22);
ctx.set_group_invalid(23);
ctx.set_group_invalid(24);
ctx.set_group_invalid(25);
ctx.set_group_invalid(26);
ctx.set_group_invalid(27);
ctx.set_group_invalid(28);
ctx.set_group_invalid(29);
ctx.set_group_invalid(30);
ctx.set_group_invalid(31);
ctx.set_group_invalid(32);
ctx.set_group_invalid(33);
ctx.set_group_invalid(34);
ctx.set_group_invalid(35);
ctx.set_group_invalid(36);
ctx.set_group_invalid(37);
ctx.set_group_invalid(38);
ctx.set_group_invalid(39);
ctx.set_group_invalid(40);
ctx.set_group_invalid(41);
ctx.set_group_invalid(42);
ctx.set_group_invalid(43);
ctx.set_group_invalid(44);
ctx.set_group_invalid(45);
ctx.set_group_invalid(46);
ctx.set_group_invalid(47);
ctx.set_group_invalid(48);
ctx.set_group_invalid(49);
ctx.set_group_invalid(50);
ctx.set_group_invalid(51);
ctx.set_group_invalid(52);
ctx.set_group_invalid(53);
ctx.set_group_invalid(54);
ctx.set_group_invalid(55);
ctx.set_group_invalid(56);
ctx.set_group_invalid(57);
ctx.set_group_invalid(58);
ctx.set_group_invalid(59);
ctx.set_group_invalid(60);
ctx.set_group_invalid(61);
ctx.set_group_invalid(62);
ctx.set_group_invalid(63);
ctx.set_group_invalid(64);
ctx.set_group_invalid(65);
ctx.set_group_invalid(66);
ctx.set_group_invalid(67);
ctx.set_group_invalid(68);
ctx.set_group_invalid(69);
ctx.set_group_invalid(70);
ctx.set_group_invalid(71);
ctx.set_group_invalid(72);
ctx.set_group_invalid(73);
ctx.set_group_invalid(74);
ctx.set_group_invalid(75);
ctx.set_group_invalid(76);
ctx.set_group_invalid(77);
ctx.set_group_invalid(78);
ctx.set_group_invalid(79);
ctx.set_group_invalid(80);
ctx.set_group_invalid(81);
ctx.set_group_invalid(82);
ctx.set_group_invalid(83);
ctx.set_group_invalid(84);
ctx.set_group_invalid(85);
ctx.set_group_invalid(86);
ctx.set_group_invalid(87);
ctx.set_group_invalid(88);
ctx.set_group_invalid(89);
ctx.set_group_invalid(90);
ctx.set_group_invalid(91);
ctx.set_group_invalid(92);
ctx.set_group_invalid(93);
ctx.set_group_invalid(94);
ctx.set_group_invalid(95);
ctx.set_group_invalid(96);
ctx.set_group_invalid(97);
ctx.set_group_invalid(98);
ctx.set_group_invalid(99);
ctx.set_group_invalid(100);
ctx.set_group_invalid(101);
ctx.set_group_invalid(102);
ctx.set_group_invalid(103);
ctx.set_group_invalid(104);
ctx.set_group_invalid(105);
ctx.set_group_invalid(106);
ctx.set_group_invalid(107);
ctx.set_group_invalid(108);
ctx.set_group_invalid(109);
ctx.set_group_invalid(110);
ctx.set_group_invalid(111);
ctx.set_group_invalid(112);
ctx.set_group_invalid(113);
ctx.set_group_invalid(114);
ctx.set_group_invalid(115);
ctx.set_group_invalid(116);
ctx.set_group_invalid(117);
ctx.set_group_invalid(118);
ctx.set_group_invalid(119);
ctx.set_group_invalid(120);
ctx.set_group_invalid(121);
ctx.set_group_invalid(122);
ctx.set_group_invalid(123);
ctx.set_group_invalid(124);
ctx.set_group_invalid(125);
ctx.set_group_invalid(126);
ctx.set_group_invalid(127);
ctx.set_group_invalid(128);
ctx.set_group_invalid(129);
ctx.set_group_invalid(130);
ctx.set_group_invalid(131);
ctx.set_group_invalid(132);
ctx.set_group_invalid(133);
ctx.set_group_invalid(134);
ctx.set_group_invalid(135);
ctx.set_group_invalid(136);
ctx.set_group_invalid(137);
ctx.set_group_invalid(138);
ctx.set_group_invalid(139);
ctx.set_group_invalid(140);
ctx.set_group_invalid(141);
ctx.set_group_invalid(142);
ctx.set_group_invalid(143);
ctx.set_group_invalid(144);
ctx.set_group_invalid(145);
ctx.set_group_invalid(146);
ctx.set_group_invalid(147);
ctx.set_group_invalid(148);
ctx.set_group_invalid(149);
ctx.set_group_invalid(150);
ctx.set_group_invalid(151);
ctx.set_group_invalid(152);
ctx.set_group_invalid(153);
ctx.set_group_invalid(154);
ctx.set_group_invalid(155);
ctx.set_group_invalid(156);
ctx.set_group_invalid(157);
ctx.set_group_invalid(158);
ctx.set_group_invalid(159);
ctx.set_group_invalid(160);
ctx.set_group_invalid(161);
ctx.set_group_invalid(162);
ctx.set_group_invalid(163);
ctx.set_group_invalid(164);
ctx.set_group_invalid(165);
ctx.set_group_invalid(166);
ctx.set_group_invalid(167);
ctx.set_group_invalid(168);
ctx.set_group_invalid(169);
ctx.set_group_invalid(170);
ctx.set_group_invalid(171);
ctx.set_group_invalid(172);
ctx.set_group_invalid(173);
ctx.set_group_invalid(174);
ctx.set_group_invalid(175);
ctx.set_group_invalid(176);
ctx.set_group_invalid(177);
ctx.set_group_invalid(178);
ctx.set_group_invalid(179);
ctx.set_group_invalid(180);
ctx.set_group_invalid(181);
}


template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

auto r {ctx.pass(cur)}; 
do {
}
 while ( 
false
);
if (r.matched) {
r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_3(), func_1(), reset_0(), func_2(), reset_1());
}
else {
r.pos = ctx.end;
}
return r; 
}


template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::func_3::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
ctx.set_group_start(0, cur);

auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
if (r.matched) {ctx.set_group_end(0, r.pos);}
return r; 
}

template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
static_cast<void>(name);
return -1; 
}

[[nodiscard]] auto test_tests_18_branch_reset::regex_15_matcher::to_string() -> std::string{return R"((?|(b)|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()(a)))"; }


#line 201 "pure2-regex_18_branch_reset.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_18_branch_reset());
}


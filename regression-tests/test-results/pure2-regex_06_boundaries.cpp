
#define CPP2_IMPORT_STD          Yes
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex_06_boundaries.cpp2"

#line 165 "pure2-regex_06_boundaries.cpp2"
class test_tests_06_boundaries;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex_06_boundaries.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 112 "pure2-regex_06_boundaries.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 124 "pure2-regex_06_boundaries.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 165 "pure2-regex_06_boundaries.cpp2"
class test_tests_06_boundaries {

#line 183 "pure2-regex_06_boundaries.cpp2"
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

        public: regex_08_matcher() = default;
        public: regex_08_matcher(regex_08_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_08_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_08_matcher> regex_08 {}; public: class regex_09_matcher {
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

        public: regex_09_matcher() = default;
        public: regex_09_matcher(regex_09_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_09_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_09_matcher> regex_09 {}; public: class regex_10_matcher {
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

        public: regex_10_matcher() = default;
        public: regex_10_matcher(regex_10_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_10_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_10_matcher> regex_10 {}; public: class regex_11_matcher {
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

        public: regex_11_matcher() = default;
        public: regex_11_matcher(regex_11_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_11_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_11_matcher> regex_11 {}; public: class regex_12_matcher {
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

        public: regex_12_matcher() = default;
        public: regex_12_matcher(regex_12_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_12_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_12_matcher> regex_12 {}; public: class regex_13_matcher {
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

        public: regex_13_matcher() = default;
        public: regex_13_matcher(regex_13_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_13_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_13_matcher> regex_13 {}; public: class regex_14_matcher {
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

        public: regex_14_matcher() = default;
        public: regex_14_matcher(regex_14_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_14_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_14_matcher> regex_14 {}; public: class regex_15_matcher {
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

        public: regex_15_matcher() = default;
        public: regex_15_matcher(regex_15_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_15_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_15_matcher> regex_15 {}; public: class regex_16_matcher {
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

        public: regex_16_matcher() = default;
        public: regex_16_matcher(regex_16_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_16_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_16_matcher> regex_16 {}; public: class regex_17_matcher {
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

        public: regex_17_matcher() = default;
        public: regex_17_matcher(regex_17_matcher const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(regex_17_matcher const&) -> void = delete;

  };

  public: cpp2::regex::regular_expression<char,regex_17_matcher> regex_17 {}; 
  public: test_tests_06_boundaries() = default;
  public: test_tests_06_boundaries(test_tests_06_boundaries const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_06_boundaries const&) -> void = delete;


#line 204 "pure2-regex_06_boundaries.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex_06_boundaries.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "pure2-regex_06_boundaries.cpp2"
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

#line 112 "pure2-regex_06_boundaries.cpp2"
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

#line 124 "pure2-regex_06_boundaries.cpp2"
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

#line 183 "pure2-regex_06_boundaries.cpp2"
  auto test_tests_06_boundaries::run() const& -> void{
    std::cout << "Running tests_06_boundaries:" << std::endl;
    test(regex_01, "01", R"(\ba\b)", "a-", "y", R"(-)", "-");
    test(regex_02, "02", R"(\ba\b)", "-a", "y", R"(-)", "-");
    test(regex_03, "03", R"(\ba\b)", "-a-", "y", R"(-)", "-");
    test(regex_04, "04", R"(\by\b)", "xy", "n", R"(-)", "-");
    test(regex_05, "05", R"(\by\b)", "yz", "n", R"(-)", "-");
    test(regex_06, "06", R"(\by\b)", "xyz", "n", R"(-)", "-");
    test(regex_07, "07", R"(\Ba\B)", "a-", "n", R"(-)", "-");
    test(regex_08, "08", R"(\Ba\B)", "-a", "n", R"(-)", "-");
    test(regex_09, "09", R"(\Ba\B)", "-a-", "n", R"(-)", "-");
    test(regex_10, "10", R"(\By\b)", "xy", "y", R"(-)", "-");
    test(regex_11, "11", R"(\By\b)", "xy", "y", R"($-[0])", "1");
    test(regex_12, "12", R"(\By\b)", "xy", "y", R"($+[0])", "2");
    test(regex_13, "13", R"(\By\b)", "xy", "y", R"(-)", "-");
    test(regex_14, "14", R"(\by\B)", "yz", "y", R"(-)", "-");
    test(regex_15, "15", R"(\By\B)", "xyz", "y", R"(-)", "-");
    test(regex_16, "16", R"(\b)", "", "n", R"(-)", "-");
    test(regex_17, "17", R"(\B)", "", "y", R"(-)", "-");
    std::cout << std::endl;
  }





  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_01_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_01_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_01_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_01_matcher::to_string() -> std::string{return R"(\ba\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_02_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_02_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_02_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_02_matcher::to_string() -> std::string{return R"(\ba\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_03_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_03_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_03_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_03_matcher::to_string() -> std::string{return R"(\ba\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_04_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_04_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_04_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_04_matcher::to_string() -> std::string{return R"(\by\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_05_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_05_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_05_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_05_matcher::to_string() -> std::string{return R"(\by\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_06_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_06_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_06_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_06_matcher::to_string() -> std::string{return R"(\by\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_07_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_07_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_07_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_07_matcher::to_string() -> std::string{return R"(\Ba\B)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_08_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_08_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_08_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_08_matcher::to_string() -> std::string{return R"(\Ba\B)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_09_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_09_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_09_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_09_matcher::to_string() -> std::string{return R"(\Ba\B)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_10_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_10_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_10_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_10_matcher::to_string() -> std::string{return R"(\By\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_11_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_11_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_11_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_11_matcher::to_string() -> std::string{return R"(\By\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_12_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_12_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_12_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_12_matcher::to_string() -> std::string{return R"(\By\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_13_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_13_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_13_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_13_matcher::to_string() -> std::string{return R"(\By\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_14_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_14_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_14_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_14_matcher::to_string() -> std::string{return R"(\by\B)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_15_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}

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
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_15_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_15_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_15_matcher::to_string() -> std::string{return R"(\By\B)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_16_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_16_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_16_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_16_matcher::to_string() -> std::string{return R"(\b)"; }






  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_17_matcher::wrap<Iter,CharT>::func_0::operator()(cpp2::impl::in<Iter> cur, context& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::word_boundary_token_matcher<char,true>(r.pos, ctx))) {r.matched = false;break;}
  }
   while ( 
  false
  );
  if (r.matched) {
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_17_matcher::wrap<Iter,CharT>::entry(cpp2::impl::in<Iter> cur, context& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename Iter, typename CharT> [[nodiscard]] auto test_tests_06_boundaries::regex_17_matcher::wrap<Iter,CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  [[nodiscard]] auto test_tests_06_boundaries::regex_17_matcher::to_string() -> std::string{return R"(\B)"; }


#line 205 "pure2-regex_06_boundaries.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_06_boundaries());
}


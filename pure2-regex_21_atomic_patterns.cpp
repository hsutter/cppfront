
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"

#line 166 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
class test_tests_21_atomic_patterns;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string;

#line 113 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
[[nodiscard]] auto sanitize(std::string str) -> std::string;

#line 125 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
template<typename M> auto test(M const& regex, cpp2::impl::in<std::string> id, cpp2::impl::in<std::string> regex_str, cpp2::impl::in<std::string> str, cpp2::impl::in<std::string> kind, cpp2::impl::in<std::string> resultExpr, 
           cpp2::impl::in<std::string> resultExpected) -> void;

#line 166 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
class test_tests_21_atomic_patterns {

#line 173 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
  public: auto run() const& -> void;
  public: template<typename CharT> class regex_01_matcher {
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,1>;
public: class func_2 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_4 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_8 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_7 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_9 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_10 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class reset_0 {
  public: auto operator()(auto& ctx) const& -> void;

  };

  public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_11 {
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
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_2 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_3 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
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
  public: template<typename Iter> using context = cpp2::regex::match_context<CharT,Iter,2>;
public: class func_3 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_2 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_4 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_5 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_0 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

  public: class func_6 {
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

  public: cpp2::regex::regular_expression<char,regex_06_matcher<char>> regex_06 {}; 
  public: test_tests_21_atomic_patterns() = default;
  public: test_tests_21_atomic_patterns(test_tests_21_atomic_patterns const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_tests_21_atomic_patterns const&) -> void = delete;


#line 183 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
[[nodiscard]] auto create_result(cpp2::impl::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
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

#line 113 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
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

#line 125 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
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

#line 173 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
  auto test_tests_21_atomic_patterns::run() const& -> void{
    std::cout << "Running tests_21_atomic_patterns:" << std::endl;
    test(regex_01, "01", R"((?>a+)b)", "aaab", "y", R"(-)", "-");
    test(regex_02, "02", R"(((?>a+)b))", "aaab", "y", R"($1)", "aaab");
    test(regex_03, "03", R"((?>(a+))b)", "aaab", "y", R"($1)", "aaa");
    test(regex_04, "04", R"(((?>[^()]+)|\([^()]*\))+)", "((abc(ade)ufh()()x", "y", R"($&)", "abc(ade)ufh()()x");
    test(regex_05, "05", R"(round\(((?>[^()]+))\))", "_I(round(xs * sz),1)", "y", R"($1)", "xs * sz");
    test(regex_06, "06", R"(^((?>(?:aa)?b)?))", "aab", "y", R"($1)", "aab");
    std::cout << std::endl;
  }




  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::func_2::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::func_3::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::atomic_group_matcher<char>(r.pos, ctx, func_1(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::func_4::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_01_matcher<CharT>::to_string() -> std::string{return R"((?>a+)b)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::func_2::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::func_3::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::atomic_group_matcher<char>(r.pos, ctx, func_1(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::func_4::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_02_matcher<CharT>::to_string() -> std::string{return R"(((?>a+)b))"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::func_2::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::func_3::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  r = other(r.pos, ctx);
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::atomic_group_matcher<char>(r.pos, ctx, func_1(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::func_4::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_03_matcher<CharT>::to_string() -> std::string{return R"((?>(a+))b)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_4::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,true,false,::cpp2::regex::single_class_entry<char,'('>,::cpp2::regex::single_class_entry<char,')'>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
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


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_3::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_4(), cpp2::regex::no_reset(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_5::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_2::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::atomic_group_matcher<char>(r.pos, ctx, func_3(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_6::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_8::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,true,false,::cpp2::regex::single_class_entry<char,'('>,::cpp2::regex::single_class_entry<char,')'>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
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


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_7::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,-1,2>::match(r.pos, ctx, func_8(), cpp2::regex::no_reset(), other, func_9());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_9::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,1 + 1> str_tmp_1 {")"}; 
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


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::alternative_token_matcher<char>::match(r.pos, ctx, other, func_10(), func_2(), cpp2::regex::no_reset(), func_7(), cpp2::regex::no_reset());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_10::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::reset_0::operator()(auto& ctx) const& -> void{
  ctx.set_group_invalid(1);
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,1,-1,2>::match(r.pos, ctx, func_1(), reset_0(), other, func_11());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::func_11::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_04_matcher<CharT>::to_string() -> std::string{return R"(((?>[^()]+)|\([^()]*\))+)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::func_2::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::class_token_matcher<char,true,false,::cpp2::regex::single_class_entry<char,'('>,::cpp2::regex::single_class_entry<char,')'>>::match(r.pos, ctx))) {r.matched = false;break;}
  }
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


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::func_3::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,6 + 1> str_tmp_0 {"round("}; 
  if (cpp2::impl::cmp_less(std::distance(r.pos, ctx.end),6)) {
  r.matched = false;
  break;
  }
{
int i{0};
  for( ; cpp2::impl::cmp_less(i,6); (i += 1) ) {
  if (CPP2_ASSERT_IN_BOUNDS(str_tmp_0, i) != CPP2_ASSERT_IN_BOUNDS(r.pos, i)) {r.matched = false;}
  }
}
  if (r.matched) {r.pos += 6;}
  else {break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::atomic_group_matcher<char>(r.pos, ctx, func_1(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::func_4::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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

  std::array<char,1 + 1> str_tmp_2 {")"}; 
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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_05_matcher<CharT>::to_string() -> std::string{return R"(round\(((?>[^()]+))\))"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_3::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"aa"}; 
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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_2::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_3(), cpp2::regex::no_reset(), other, func_4());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_4::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::atomic_group_matcher<char>(r.pos, ctx, func_2(), other, func_5());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_5::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::line_start_token_matcher<char,false>(r.pos, ctx))) {r.matched = false;break;}
  ctx.set_group_start(1, r.pos);
  }
   while ( 
  false
  );
  if (r.matched) {
  r = cpp2::regex::range_token_matcher<char,0,1,2>::match(r.pos, ctx, func_1(), cpp2::regex::no_reset(), other, func_6());
  }
  else {
  r.pos = ctx.end;
  }
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }


  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::func_6::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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
  static_cast<void>(CPP2_FORWARD(ctx));
  return r; 
  }

  template <typename CharT> template<typename Iter> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto test_tests_21_atomic_patterns::regex_06_matcher<CharT>::to_string() -> std::string{return R"(^((?>(?:aa)?b)?))"; }


#line 184 "regression-tests/pure2-regex_21_atomic_patterns.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(test_tests_21_atomic_patterns());
}


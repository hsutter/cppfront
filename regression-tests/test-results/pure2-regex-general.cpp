
#define CPP2_IMPORT_STD          Yes
#include "cpp2regex.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex-general.cpp2"
class general_regex_test;
#line 2 "pure2-regex-general.cpp2"
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex-general.cpp2"
class general_regex_test {

#line 4 "pure2-regex-general.cpp2"
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
public: class func_1 {
  public: template<typename Iter> [[nodiscard]] auto operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>;

  };

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

  public: cpp2::regex::regular_expression<char,regex_02_matcher<char>> regex_02 {}; 
  public: general_regex_test() = default;
  public: general_regex_test(general_regex_test const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(general_regex_test const&) -> void = delete;


#line 28 "pure2-regex-general.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex-general.cpp2"

#line 4 "pure2-regex-general.cpp2"
  auto general_regex_test::run() const& -> void{
    std::cout << "Running tests_01_char_matcher:" << std::endl;

    std::cout << "Not full match fails: " << CPP2_UFCS(match)(regex_01, "AAaa").matched << std::endl;
    std::cout << "Full match is ok:     " << CPP2_UFCS(match)(regex_01, "AA").matched << std::endl;
    std::cout << "Search finds at position 1: " << CPP2_UFCS(group_start)(CPP2_UFCS(search)(regex_01, "aAAaa"), 0) << std::endl;
    std::cout << "Search finds at position 3: " << CPP2_UFCS(group_start)(CPP2_UFCS(search)(regex_01, "aaaAAaa"), 0) << std::endl;

    auto count {0}; 
    auto func {[&, _1 = (&count)](auto const& r) -> bool{
      *cpp2::impl::assert_not_null(_1) += 1;
      std::cout << "Find all finds at position: " << CPP2_UFCS(group_start)(r, 0) << std::endl;
      return true; 
    }}; 

    std::string str {"aAAaAAaAAa"}; 
    regex_01.find_all(func, str);
    std::cout << "Find all found 3 matched: " << count << std::endl;

    count = 0;
    str = "bbaabb";
    regex_02.find_all(cpp2::move(func), cpp2::move(str));
    std::cout << "Find all found 1 match: " << cpp2::move(count) << std::endl;
  }




  template <typename CharT> template<typename Iter> [[nodiscard]] auto general_regex_test::regex_01_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {

  std::array<char,2 + 1> str_tmp_0 {"AA"}; 
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

  template <typename CharT> template<typename Iter> [[nodiscard]] auto general_regex_test::regex_01_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto general_regex_test::regex_01_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto general_regex_test::regex_01_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto general_regex_test::regex_01_matcher<CharT>::to_string() -> std::string{return R"(AA)"; }





  template <typename CharT> template<typename Iter> [[nodiscard]] auto general_regex_test::regex_02_matcher<CharT>::func_1::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

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


  template <typename CharT> template<typename Iter> [[nodiscard]] auto general_regex_test::regex_02_matcher<CharT>::func_0::operator()(Iter const& cur, auto&& ctx, auto const& other) const& -> cpp2::regex::match_return<Iter>{

  auto r {ctx.pass(cur)}; 
  do {
  if (!(cpp2::regex::lookahead_token_matcher<char,true>(r.pos, ctx, func_1()))) {r.matched = false;break;}
  }
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

  template <typename CharT> template<typename Iter> [[nodiscard]] auto general_regex_test::regex_02_matcher<CharT>::entry(Iter const& cur, context<Iter>& ctx) -> cpp2::regex::match_return<Iter>{
  ctx.set_group_start(0, cur);

  auto r {func_0()(cur, ctx, cpp2::regex::true_end_func())}; 
  if (r.matched) {ctx.set_group_end(0, r.pos);}
  return r; 
  }

  template <typename CharT> [[nodiscard]] auto general_regex_test::regex_02_matcher<CharT>::get_named_group_index(auto const& name) -> int{
  static_cast<void>(name);
  return -1; 
  }

  template <typename CharT> [[nodiscard]] constexpr auto general_regex_test::regex_02_matcher<CharT>::is_start_match() -> bool { return false; }
template <typename CharT> [[nodiscard]] auto general_regex_test::regex_02_matcher<CharT>::to_string() -> std::string{return R"((?=aa))"; }


#line 30 "pure2-regex-general.cpp2"
auto main() -> int{
    CPP2_UFCS(run)(general_regex_test());
}


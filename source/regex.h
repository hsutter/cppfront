
#ifndef REGEX_H_CPP2
#define REGEX_H_CPP2


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regex.h2"

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

#line 20 "regex.h2"
class list_end;

class match_return;

#line 37 "regex.h2"
template<typename CharT, size_t max_groups> class match_context;

#line 49 "regex.h2"
template<typename CharT> class any_matcher_logic;

#line 55 "regex.h2"
template<typename CharT, CharT C> class char_matcher_logic;

#line 61 "regex.h2"
template<typename CharT, typename ...List> class list_matcher_logic;

#line 120 "regex.h2"
}
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regex.h2"

//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

template<typename CharT> using view = std::basic_string_view<CharT>;
template<typename CharT> using bstring = std::basic_string<CharT>;

class list_end {
      public: list_end() = default;
      public: list_end(list_end const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(list_end const&) -> void = delete;
};
#line 21 "regex.h2"

class match_return
 {
    public: bool matched {false}; 
    public: size_t length {0}; 

    public: [[nodiscard]] static auto create(auto const& m, auto const& l) -> match_return;

#line 35 "regex.h2"
};

template<typename CharT, size_t max_groups> class match_context
 {

    private: std::array<view<CharT>,max_groups> groups; 
    public: match_context() = default;
    public: match_context(match_context const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(match_context const&) -> void = delete;


#line 42 "regex.h2"
};

/*regular_expression: @interface <CharT> type = {

    match: <Ctx> (str: view<CharT>, inout ctx: Ctx) -> bool;
}*/

template<typename CharT> class any_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: any_matcher_logic() = default;
    public: any_matcher_logic(any_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(any_matcher_logic const&) -> void = delete;

#line 53 "regex.h2"
};

template<typename CharT, CharT C> class char_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;
    public: char_matcher_logic() = default;
    public: char_matcher_logic(char_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(char_matcher_logic const&) -> void = delete;

#line 59 "regex.h2"
};

template<typename CharT, typename ...List> class list_matcher_logic
 {
    public: [[nodiscard]] static auto match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;

#line 67 "regex.h2"
    public: [[nodiscard]] static auto to_string() -> bstring<CharT>;

#line 71 "regex.h2"
    private: template<typename First, typename ...Other> [[nodiscard]] static auto match_all(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;

#line 90 "regex.h2"
    private: [[nodiscard]] static auto match_all(cpp2::in<view<CharT>> str, auto& ctx) -> match_return;
    public: list_matcher_logic() = default;
    public: list_matcher_logic(list_matcher_logic const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(list_matcher_logic const&) -> void = delete;


#line 94 "regex.h2"
};

[[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex) -> std::string;

#line 120 "regex.h2"
}
}


//=== Cpp2 function definitions =================================================

#line 1 "regex.h2"

#line 13 "regex.h2"
namespace cpp2 {

namespace regex {

#line 27 "regex.h2"
    [[nodiscard]] auto match_return::create(auto const& m, auto const& l) -> match_return{
      if (m) {
        return { true, l }; 
      }
      else {
        return { false, 0 }; 
      }
    }

#line 51 "regex.h2"
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return { return match_return::create(!(CPP2_UFCS(empty)(str)), 1);  }
    template <typename CharT> [[nodiscard]] auto any_matcher_logic<CharT>::to_string() -> bstring<CharT> { return bstring<CharT>(1, '.');  }

#line 57 "regex.h2"
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return { return match_return::create(!(CPP2_UFCS(empty)(str)) && CPP2_UFCS(front)(str) == C, 1);  }
    template <typename CharT, CharT C> [[nodiscard]] auto char_matcher_logic<CharT,C>::to_string() -> bstring<CharT> { return bstring<CharT>(1, C);  }

#line 63 "regex.h2"
    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
      return match_all<List...>(str, ctx); 
    }

    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::to_string() -> bstring<CharT>{
      return { (bstring<CharT>() + ... + List::to_string()) }; 
    }

    template <typename CharT, typename ...List> template<typename First, typename ...Other> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match_all(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
      match_return r {First::match(str, ctx)}; 

      if (r.matched) {
        if constexpr (0 != sizeof...(Other)) {
          match_return o {match_all<Other...>(CPP2_UFCS(substr)(str, 1), ctx)}; 

          if (o.matched) {
            r.length += std::move(o).length;
          }
          else {
            r = { false, 0 };
          }
        }
      }

      return r; 
    }

    template <typename CharT, typename ...List> [[nodiscard]] auto list_matcher_logic<CharT,List...>::match_all(cpp2::in<view<CharT>> str, auto& ctx) -> match_return{
      // TODO: Assert End == list_end
      return { true, 0 }; 
    }

#line 96 "regex.h2"
[[nodiscard]] auto generate_template(cpp2::in<std::string_view> regex) -> std::string{
  std::string template_expression {""}; 
  std::string seperator {""}; 

  template_expression += "::cpp2::regex::list_matcher_logic<char, ";

  for ( auto const& c : regex ) {
    template_expression += seperator;
    if (c == '.') {
      template_expression += "::cpp2::regex::any_matcher_logic<char>";
    }
    else {
      template_expression += "::cpp2::regex::char_matcher_logic<char, '" + cpp2::to_string(c) + "'>";
    }

    seperator = ", ";
  }
  template_expression += ">";

  return template_expression; 

#line 118 "regex.h2"
}

}
}

#endif

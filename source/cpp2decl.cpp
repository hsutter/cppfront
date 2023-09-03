//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

// ----

// cpp2decl prints the declarations in a cpp2 file. For example, running on
// regression-tests/pure2-types-inheritance.cpp2 (at commit 1764f0c) prints:
//
// Human                           : type
// Human::speak                    : (this)
// Human::operator=                : (move this)
// N::Machine                      : type
// N::Machine::operator=           : (out this, _: std::string)
// N::Machine::work                : (this)
// N::Machine::operator=           : (move this)
// Cyborg                          : type
// Cyborg::name                    : std::string
// Cyborg::this                    : Human
// Cyborg::address                 : std::string
// Cyborg::this                    : N::Machine<(expression)>
// Cyborg::operator=               : (out this, n: std::string)
// Cyborg::speak                   : (this)
// Cyborg::work                    : (this)
// Cyborg::print                   : (this)
// Cyborg::operator=               : (move this)
// make_speak                      : (h: Human)
// do_work                         : (m: N::Machine<(expression)>)
// main                            : ()
//
// Declarations are printed one per line and their names are flattened, so that
// the line for the `work` method on the `Machine` type in the `N` namespace
// starts with `N::Machine::work`. This flattening is similar to how gron
// (https://github.com/tomnomnom/gron) flattens JSON and has the same
// motivation. Flattening combines well with classic, line-oriented, Unix-style
// tools like diff, grep, sed and sort. Unlike the original C++2 source file,
// which may have "N: namespace" and "Machine: type" on different lines,
// sorting the lines of cpp2decl's output will not change its meaning.
//
// Many IDEs already have a "table of contents" view, but this command does not
// require an IDE to provide a GUI or further context. For example, automated
// tooling can combine cpp2decl, sort and diff to derive "what API changed
// between two versions", similar to https://go.dev/api/go1.19.txt
//
// cpp2decl can also be used to get a quick overview of an unfamiliar corpus of
// C++2 source code, and cpp2decl+grep can quickly answer ad hoc queries like
// "show me all of the 'speak' methods implemented by cpp2 files in this
// directory", without having to first import that project into an IDE or to
// build (and keep up-to-date, e.g. when checking out different branches) a
// code-search index.

// ----

// Build instructions: build cpp2decl.cpp just like building cppfront.cpp, per
// the top-level README.md.

// ----

// TODO: a flag for writing to a file (a .cpp2decl file??) instead of always to
// stdout. That would probably best start by refactoring cppfront.cpp.
//
// TODO: a flag for hiding private or anonymous-namespace names?
//
// TODO: a flag for hiding argument names (or replacing them with `_`)? Going
// from `f(x: int)` to `f(y: int)` isn't actually an API change.
//
// TODO: fix the `(expression)` in `N::Machine<(expression)>`.
//
// TODO: also parse C++1 syntax, which is obviously easier said than done.
//
// TODO: paint the bikeshed about cpp2decl's output syntax.

// ----

// This file was formatted by clang-format (using its default options).

// ----

#include <cstdio>
#include <iostream>
#include <optional>
#include <sstream>

// TODO: is there a better header? We don't actually need semantic analysis.
#include "sema.h"

namespace cpp2 {

namespace {

auto do_declaration_name(std::ostream& out, declaration_node const& n)
    -> size_t {
  size_t num_printed = 0;
  if (n.parent_declaration) {
    num_printed = 2 + do_declaration_name(out, *n.parent_declaration);
    out << "::";
  }
  std::string_view sv = std::string_view(*n.identifier->identifier);
  out << sv;
  return num_printed + sv.size();
};

auto do_parameters(std::ostream& out,
                   parameter_declaration_list_node& n,
                   passing_style default_passing_style) -> void {
  out << "(";
  bool first = true;
  for (std::unique_ptr<parameter_declaration_node> const& pdn : n.parameters) {
    if (!first) {
      out << ", ";
    }
    std::string_view const& name = *pdn->name();
    // TODO: print modifiers like "override".
    if (passing_style ps = pdn->direction(); ps != default_passing_style) {
      out << to_string_view(ps) << " ";
    }
    out << name;
    if (name != "this") {
      out << ": ";
      if (pdn->declaration->is_object()) {
        auto const& o =
            std::get<declaration_node::an_object>(pdn->declaration->type);
        for (auto const& q : o->pc_qualifiers) {
          out << *q << " ";
        }
        out << pdn->declaration->object_type();
      } else {
        out << "???";
      }
    }
    first = false;
  }
  out << ")";
}

auto do_function(std::ostream& out, function_type_node& n) -> void {
  do_parameters(out, *n.parameters, passing_style::in);

  switch (n.returns.index()) {
    case function_type_node::empty: {
      break;
    }
    case function_type_node::id: {
      function_type_node::single_type_id const& sti =
          std::get<function_type_node::id>(n.returns);
      out << " -> ";
      if (passing_style ps = sti.pass; ps != passing_style::move) {
        out << to_string_view(ps) << " ";
      }
      out << sti.type->to_string();
      break;
    }
    case function_type_node::list: {
      std::unique_ptr<parameter_declaration_list_node>& pdln =
          std::get<function_type_node::list>(n.returns);
      out << " -> ";
      do_parameters(out, *pdln, passing_style::out);
      break;
    }
  }
}

auto do_declaration(std::ostream& out, declaration_node const& n) -> void {
  if (!n.is_namespace()) {
    size_t num_printed = do_declaration_name(out, n);
    if (num_printed < 32) {
      static const char* thirty_two_spaces = "                                ";
      out << thirty_two_spaces + num_printed << ": ";
    } else {
      out << " : ";
    }

    switch (n.type.index()) {
      case declaration_node::a_function: {
        do_function(out, *std::get<declaration_node::a_function>(n.type));
        break;
      }
      case declaration_node::an_object: {
        auto const& o = std::get<declaration_node::an_object>(n.type);
        for (auto const& q : o->pc_qualifiers) {
          out << *q << " ";
        }
        out << n.object_type();
        break;
      }
      case declaration_node::a_type: {
        // TODO: print "@interface", "@polymorphic_base", "<I:int>", etc.
        out << "type";
        break;
      }
    }
    out << "\n";
  }

  if (n.is_namespace() || n.is_type()) {
    auto& c = std::get<statement_node::compound>(n.initializer->statement);
    for (auto& s : c->statements) {
      if (s->is_declaration()) {
        auto& d = std::get<statement_node::declaration>(s->statement);
        do_declaration(out, *d);
      }
    }
  }
}

}  // namespace

auto cmdline_processor::print(std::string_view s, int width) -> void {
  if (width > 0) {
    std::cout << std::setw(width) << std::left;
  }
  std::cout << s;
}

auto error_entry::print(auto& o, std::string const& file) const -> void {
  o << file;
  if (where.lineno > 0) {
    o << "(" << (where.lineno);
    if (where.colno >= 0) {
      o << "," << where.colno;
    }
    o << ")";
  }
  o << ":";
  if (internal) {
    o << " internal compiler";
  }
  o << " error: " << msg << "\n";
}

class cpp2decl {
  std::string sourcefile;
  std::vector<error_entry> errors;

  cpp2::source source;
  cpp2::tokens tokens;
  cpp2::parser parser;

 public:
  cpp2decl(std::string const& filename)
      : sourcefile{filename}, source{errors}, tokens{errors}, parser{errors} {
    if (!sourcefile.ends_with(".cpp2") && !sourcefile.ends_with(".h2")) {
      errors.emplace_back(
          source_position(-1, -1),
          "source filename must end with .cpp2 or .h2: " + sourcefile);
    } else if (!source.load(sourcefile)) {
      if (errors.empty()) {
        errors.emplace_back(source_position(-1, -1),
                            "file not found: " + sourcefile);
      }
    } else {
      tokens.lex(source.get_lines());
      try {
        for (auto const& [line, entry] : tokens.get_map()) {
          if (!parser.parse(entry, tokens.get_generated())) {
            errors.emplace_back(source_position(line, 0),
                                "parse failed for section starting here", false,
                                true);
          }
        }
      } catch (std::runtime_error& e) {
        errors.emplace_back(source_position(-1, -1), e.what());
      }
    }
  }

  auto run(std::ostream& out) -> void {
    for (auto& section : tokens.get_map()) {
      auto decls = parser.get_parse_tree_declarations_in_range(section.second);
      for (auto const& decl : decls) {
        do_declaration(out, *decl);
      }
    }
  }

  auto print_errors(std::ostream& out) -> void {
    error_entry const* prev = {};
    bool print_fallback_errors = true;
    for (auto&& error : errors) {
      if (!error.fallback) {
        print_fallback_errors = false;
      }
      if (error.fallback && !print_fallback_errors) {
        continue;
      }
      if (!prev || error != *prev) {
        error.print(out, strip_path(sourcefile));
      }
      prev = &error;
    }
  }

  auto had_no_errors() -> bool { return errors.empty(); }
};

}  // namespace cpp2

auto main(int argc, char* argv[]) -> int {
  cpp2::cmdline.set_args(argc, argv);
  cpp2::cmdline.process_flags();
  std::stringbuf str_buf;
  std::ostream os(&str_buf);
  int exit_status = EXIT_SUCCESS;
  for (auto const& arg : cpp2::cmdline.arguments()) {
    cpp2::cpp2decl c(arg.text);
    c.run(os);
    if (!c.had_no_errors()) {
      c.print_errors(std::cerr);
      exit_status = EXIT_FAILURE;
    }
  }
  std::cout << str_buf.str();
  return exit_status;
}

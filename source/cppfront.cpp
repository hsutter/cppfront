
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//===========================================================================
//  main - driver
//===========================================================================

#include "to_cpp1.h"

static auto flag_debug_output = false;
static cpp2::cmdline_processor::register_flag cmd_debug(
    9,
    "debug",
    "Emit compiler debug output",
    []{ flag_debug_output = true; }
);

static auto flag_quiet = false;
static cpp2::cmdline_processor::register_flag cmd_quiet(
    9,
    "quiet",
    "Print only error output",
    []{ flag_quiet = true; }
);

auto main(
    int   argc,
    char* argv[]
)
    -> int
{
    using namespace cpp2;

    cmdline.set_args(argc, argv);
    cmdline.process_flags();

    if (cmdline.help_was_requested()) {
        return EXIT_SUCCESS;
    }

    if (cmdline.arguments().empty()) {
        std::cerr << "cppfront: error: no input files (try -help)\n";
        return EXIT_FAILURE;
    }

    //  For each Cpp2 source file
    int exit_status = EXIT_SUCCESS;
    for (auto const& arg : cmdline.arguments())
    {
        cpp2::timer t;
        t.start();

        auto& out = flag_cpp1_filename != "stdout" ? std::cout : std::cerr;

        if (!flag_quiet) {
            out << arg.text << "...";
        }

        //  Load + lex + parse + sema
        cppfront c(arg.text);

        //  Generate Cpp1 (this may catch additional late errors)
        auto count = c.lower_to_cpp1();

        //  If there were no errors, say so and generate Cpp1
        if (c.had_no_errors())
        {
            if (!flag_quiet)
            {
                if (!c.has_cpp1()) {
                    out << " ok (all Cpp2, passes safety checks)\n";
                }
                else if (c.has_cpp2()) {
                    out << " ok (mixed Cpp1/Cpp2, Cpp2 code passes safety checks)\n";
                }
                else {
                    out << " ok (all Cpp1)\n";
                }

                if (flag_verbose) {
                    auto total = count.cpp1_lines + count.cpp2_lines;
                    auto total_lines = print_with_thousands(total);
                    out << "   Cpp1  "
                        << std::right << std::setw(total_lines.size())
                        << print_with_thousands(count.cpp1_lines) << " line" << (count.cpp1_lines != 1 ? "s" : "");
                    out << "\n   Cpp2  "
                        << std::right << std::setw(total_lines.size())
                        << print_with_thousands(count.cpp2_lines) << " line" << (count.cpp2_lines != 1 ? "s" : "");
                    if (total > 0) {
                        out << " (";
                        if (count.cpp1_lines == 0) {
                            out << 100;
                        }
                        else if (count.cpp2_lines / count.cpp1_lines > 25) {
                            out << std::setprecision(3)
                                << 100.0 * count.cpp2_lines / total;
                        }
                        else {
                            out << 100 * count.cpp2_lines / total;
                        }
                        out << "%)";
                    }

                    t.stop();
                    auto total_time = print_with_thousands(t.elapsed().count());
                    std::cout << "\n   Time  " << total_time << " ms";

                    std::multimap< long long, std::string_view, std::greater<long long> > sorted_timers;
                    for (auto [name, t] : timers) {
                        sorted_timers.insert({t.elapsed().count(), name});
                    }

                    for (auto [elapsed, name] : sorted_timers) {
                        std::cout
                            << "\n         "
                            << std::right << std::setw(total_time.size())
                            << print_with_thousands(elapsed) << " ms" << " in " << name;
                    }
                }

                out << "\n";
            }
        }
        //  Otherwise, print the errors
        else
        {
            std::cerr << "\n";
            c.print_errors();
            std::cerr << "\n";
            exit_status = EXIT_FAILURE;
        }

        //  And, if requested, the debug information
        if (flag_debug_output) {
            c.debug_print();
        }
    }

    //if (flag_internal_debug) {
    //    stackinstr::print_deepest();
    //    stackinstr::print_largest();
    //}

    return exit_status;
}

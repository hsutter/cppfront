
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

static auto enable_debug_output_files = false;
static cpp2::cmdline_processor::register_flag cmd_debug(
    9,
    "debug",
    "Emit compiler debug output files",
    []{ enable_debug_output_files = true; }
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
        auto& out = flag_cpp1_filename != "stdout" ? std::cout : std::cerr;

        out << arg.text << "...";

        //  Load + lex + parse + sema
        cppfront c(arg.text);

        //  Generate Cpp1 (this may catch additional late errors)
        auto count = c.lower_to_cpp1();

        //  If there were no errors, say so and generate Cpp1
        if (c.had_no_errors())
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
                out << "   Cpp1: " << count.cpp1_lines << " line" << (count.cpp1_lines != 1 ? "s" : "");
                out << "\n   Cpp2: " << count.cpp2_lines << " line" << (count.cpp2_lines != 1 ? "s" : "");
                auto total = count.cpp1_lines + count.cpp2_lines;
                if (total > 0) {
                    out << " (";
                    if (count.cpp2_lines / count.cpp1_lines > 25) {
                        out << std::setprecision(3)
                            << 100.0 * count.cpp2_lines / total;
                    }
                    else {
                        out << 100 * count.cpp2_lines / total;
                    }
                    out << "%)";
                }
            }

            out << "\n";
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
        if (enable_debug_output_files) {
            c.debug_print();
        }
    }

    return exit_status;
}

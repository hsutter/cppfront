import pprint
from typing import Dict
from pathlib import Path
from dataclasses import dataclass, field

TARGETS_MAPPING: Dict[str, str] = {
	"apple-clang-14-c++2b" : "TBD01",
	"apple-clang-15-c++2b" : "TBD02",
	"clang-12-c++20"       : "TBD03",
	"clang-15-c++20"       : "TBD04",
	"clang-15-c++20-libcpp": "TBD05",
	"clang-18-c++20"       : "TBD06",
	"clang-18-c++23-libcpp": "TBD07",
	"gcc-10-c++20"         : "TBD08",
	"gcc-13-c++2b"         : "TBD09",
	"gcc-14-c++2b"         : "TBD10",
	"msvc-2022-c++20"      : "TBD11",
	"msvc-2022-c++latest"  : "TBD12",
}

@dataclass
class TestProp:
	has_lowered_output: bool
	has_cppfront_output: bool
	targets_with_cpp_exec: Dict[str, int] = field(default_factory=dict)
	targets_with_cpp_output: Dict[str, int] = field(default_factory=dict)

def main():
	if not Path("README.md").is_file():
		print("CWD should be root of the cppfront repo")
		exit()

	p = Path(".")
	trp = p / "regression-tests" / "test-results"

	files_accounted_for = []
	def try_account_for(pp):
		if pp.is_file():
			files_accounted_for.append(pp)
			return True
		return False

	# Account for cppfront version
	afcftp = try_account_for(trp / "version")
	assert afcftp

	# Account for target compiler versions
	for target in TARGETS_MAPPING.keys():
		compiler_prefix = "clang"
		if "gcc" in target:
			compiler_prefix = "gcc"
		if "msvc" in target:
			compiler_prefix = "MSVC"
		afcvp = try_account_for(trp / target / (compiler_prefix + "-version.output"))
		assert afcvp

	# Account for extraneous files (disable once fixed)
	if True:
		for efs in (
				"regression-tests/test-results/clang-18-c++20/pure2-bugfix-for-ufcs-arguments.cpp copy.execution",
				"regression-tests/test-results/clang-18-c++23-libcpp/pure2-bugfix-for-ufcs-arguments.cpp copy.execution",
				"regression-tests/test-results/apple-clang-14-c++2b/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/apple-clang-15-c++2b/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/clang-15-c++20-libcpp/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/clang-15-c++20/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/clang-18-c++20/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/clang-18-c++23-libcpp/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/gcc-13-c++2b/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/msvc-2022-c++20/pure2-regex_13_posessive_modifier.cpp.execution",
				"regression-tests/test-results/msvc-2022-c++20/pure2-regex_13_posessive_modifier.cpp.output",
			):
			afefp = try_account_for(Path(efs))
			assert afefp

	removable_msvc_files_count = 0
	tests: Dict[str, TestProp] = {}
	for tp in p.glob("regression-tests/*.cpp2"):
		aftp = try_account_for(tp)
		assert aftp

		name = tp.name[:-5]
		cppfront_lowered_output = trp / (name + ".cpp")
		cppfront_output = trp / (name + ".cpp2.output")

		assert name not in tests
		t = tests[name] = TestProp(
			has_lowered_output=try_account_for(cppfront_lowered_output),
			has_cppfront_output=try_account_for(cppfront_output),
		)

		for target in TARGETS_MAPPING.keys():
			cep = trp / target / (name + ".cpp.execution")
			if try_account_for(cep):
				t.targets_with_cpp_exec[target] = hash(open(cep).read())
			cop = trp / target / (name + ".cpp.output")
			if try_account_for(cop):
				# t.targets_with_cpp_output[target] = hash(open(cop).read())
				fcontent = open(cop).read()
				if fcontent.strip() != (name + ".cpp"):
					t.targets_with_cpp_output[target] = hash(fcontent)
				else:
					removable_msvc_files_count += 1

	files_accounted_for_set = set([f for f in files_accounted_for])
	assert len(files_accounted_for_set) == len(files_accounted_for)

	all_files = set(fp for fp in p.glob("regression-tests/**/*") if not fp.is_dir())

	redundant_file_count = len(all_files) - len(files_accounted_for)

	print(f"MSVC redundant removable files: {removable_msvc_files_count}\n")
	redundant_file_count += removable_msvc_files_count

	print(f"Files unnacounted for ({redundant_file_count}):")
	for f in sorted(all_files - files_accounted_for_set):
		print(f"\t{f}")
	print()

	print("All tests and their redundancy count:")
	for k,v in sorted(tests.items()):
		rk1 = _count_redundant_keys(v.targets_with_cpp_exec)
		rk2 = _count_redundant_keys(v.targets_with_cpp_output)
		redundant_file_count += rk1 + rk2

		print(k)
		pprint.pp(v)
		print(f"-> {rk1}, {rk2}")
		print()
	print(f"Total redundant files = {redundant_file_count}")
	print()

	tests_with_compiler_output = 0
	print("Tests with compiler output:")
	for k,v in sorted(tests.items()):
		if len(v.targets_with_cpp_output) == 0:
			continue
		tests_with_compiler_output += 1

		print(k)
		pprint.pp(v)
		print()
	print(f"Total = {tests_with_compiler_output}")
	print()

def _count_redundant_keys(d):
	counts = {}
	for k,v in d.items():
		counts[v] = counts.get(v,0)+1
	total = 0
	for v in counts.values():
		total += v - 1
	return total

if __name__ == "__main__":
	main()

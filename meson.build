project(
  'cppfront',
  ['cpp'],
  version: files('./source/version.info'),
  meson_version: '>= 1.1',
  default_options: ['cpp_std=c++20'],
)

threads_dep = dependency('threads', required : true)

cppfront = executable('cppfront', './source/cppfront.cpp',
  cpp_args : [
    '-Wall',
    '-Wextra',
    '-Wold-style-cast',
    '-Wunused-parameter',
    '-Wpedantic',
    '-Werror',
    '-Wno-unknown-warning',
    '-Wno-unknown-warning-option'
  ],
  dependencies: [threads_dep],
  install:true
)

install_headers([
    './include/cpp2regex.h',
    './include/cpp2regex.h2',
    './include/cpp2util.h'
])

meson.override_find_program('cppfront', cppfront)
cpp2_dep = declare_dependency(include_directories: 'include')

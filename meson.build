project('libajax', 'cpp', version: 'master')

include = include_directories('include')
libcurl_dep = dependency('libcurl')

libajax = library('libajax', [
    'src/libajax/method.cc',
    'src/libajax/request_builder.cc',
    'src/libajax/request.cc',
    'src/libajax/response.cc',
    'src/libajax/ajax.cc'
  ], include_directories: include,
  dependencies: [libcurl_dep])

main = executable('main.exe', [
    'src/main.cc',
  ], include_directories : include,
  link_with: libajax)

libajax_dep = declare_dependency(
  include_directories : include,
  link_with : libajax)

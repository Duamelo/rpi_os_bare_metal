
include_directories(
  ${CMAKE_SOURCE_DIR}/os_bare_metal/
  )

set(srcs ./src/average.c)

add_library(average OBJECT ${srcs})

add_subdirectory(tests)

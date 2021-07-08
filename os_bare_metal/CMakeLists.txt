
include_directories(
  ${CMAKE_SOURCE_DIR}/os_bare_metal/
  )

set(srcs ./src/gpio.c)

add_library(gpio OBJECT ${srcs})

add_subdirectory(tests)

cmake_minimum_required (VERSION 3.0)
project ( rpi_os_bare_metal C )

include(CTest)
link_directories("/usr/local/lib")
include_directories("/usr/local/include/unity")

find_program(MEMORYCHECK_COMMAND valgrind)
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full --show-leak-kinds=all" )

add_definitions(-ggdb3)
add_subdirectory (os_bare_metal)  

include_directories(
 ${CMAKE_SOURCE_DIR}/os_bare_metal/
  )

add_executable(t_aver EXCLUDE_FROM_ALL
  test_average.c ../src/average.c) 
target_link_libraries(t_aver unity)


#add_test(test_sexp tsexpr)
add_test(test_average_three_integer t_aver )

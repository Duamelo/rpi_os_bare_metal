include_directories(
 ${CMAKE_SOURCE_DIR}/os_bare_metal/
  )

add_executable(tgpio EXCLUDE_FROM_ALL
  test_gpio.c ../src/gpio.c) 
target_link_libraries(tgpio unity)



add_executable(tgpiohi EXCLUDE_FROM_ALL
  test_gpio.c ../src/gpio.c) 
target_link_libraries(tgpiohi unity)


#add_executable(tgpiolev0 EXCLUDE_FROM_ALL
#  test_gpio.c ../src/gpio.c) 
#target_link_libraries(tgpiolev0 unity)

#add_executable(tvaluegplev0 EXCLUDE_FROM_ALL
#  test_gpio.c ../src/gpio.c) 
#target_link_libraries(tvaluegplev0 unity)


#add_test(test_sexp tsexpr)
add_test(test_gpio_value tgpio )
add_test(test_gpio_high tgpiohi)
#add_test(test_value_gpio_gplev0 tvaluegplev0)
#add_test(test_address_gpio_gplev0 tgpiolev0)
cmake_minimum_required(VERSION 3.11)
enable_testing()

find_package(doctest REQUIRED)

if(NOT TARGET gemv)
  message(SEND_ERROR "\nNO TESTING TARGET!")
endif()

add_executable(main_test test_gemv.cc)

target_link_libraries(main_test
  PRIVATE
    doctest::doctest
    gemv
)

add_test(gemv_test
  main_test
)
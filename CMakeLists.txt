cmake_minimum_required(VERSION 3.11)
project(General-CPP-Project-Setup CXX)

enable_testing()

add_subdirectory(gemv)
add_subdirectory(tests)

add_executable(main main.cc)	
target_link_libraries(main PUBLIC gemv)
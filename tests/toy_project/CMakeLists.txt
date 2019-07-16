cmake_minimum_required(VERSION 3.1)
project (toy_project)

find_package(cpptools CONFIG REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC cpptools)  
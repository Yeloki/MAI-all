cmake_minimum_required(VERSION 3.16)
project(kp8)

set(CMAKE_CXX_STANDARD 20)

#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
set(SRC core.hpp debug.hpp thread_pool.hpp)
add_executable(kp8 main.cpp ${SRC})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#target_link_libraries(kp8 sfml-graphics sfml-audio)

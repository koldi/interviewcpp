cmake_minimum_required(VERSION 3.6)

project(interview)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Werror")

add_executable(parenthesis 
  parenthesis.cpp
)

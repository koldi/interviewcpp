cmake_minimum_required(VERSION 3.6)

project(interview)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Werror")

enable_testing()

add_executable(interviewtest
  test_main.cpp
  parenthesis.cpp
  wordbackward.cpp
)

add_test(
  NAME    interviewtest
  COMMAND interviewtest
)

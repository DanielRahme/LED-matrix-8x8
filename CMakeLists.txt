cmake_minimum_required(VERSION 3.10)
project(led_matrix VERSION 1.0.0 LANGUAGES C)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib")


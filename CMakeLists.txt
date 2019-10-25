cmake_minimum_required(VERSION 2.8)
project(mptest)
enable_testing()

set(SOURCES
	src/main.cpp
	src/modulo_mersenne.h
	src/number.h
	src/primetest.h)

add_executable(mptest ${SOURCES})
target_link_libraries(mptest gmp)

if (MSVC)
	set(CMAKE_CXX_FLAGS "/std:c++17 /W4 /bigobj /EHsc /wd4503 /wd4996 /wd4702 /wd4100")
else()
	set(CMAKE_CXX_FLAGS "-std=c++17 -pedantic -Wall -Wextra -Wconversion")
endif()

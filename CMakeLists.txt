set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
set(CMAKE_PREFIX_PATH "~/anaconda3/envs/arrow-dev")
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(qarrow)

find_package(Arrow REQUIRED)

ADD_DEFINITIONS(-D_GLIBCXX_USE_CXX11_ABI=0)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK)
find_package(Boost 1.66.0 COMPONENTS log log_setup system thread timer prg_exec_monitor)
#include_directories(${Boost_INCLUDE_DIRS})
#link_libraries(${Boost_LIBRARIES} -Lbin -lc)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

find_package (Threads)

include_directories(src)
#link_directories()
#link_libraries()


add_executable(main main.cpp main.cpp tests/test.cpp src/qarrow.cpp)

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options( main PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options( main PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( main PRIVATE /W4 /w44265 /w44061 /w44062 )
endif()


target_link_libraries(main qarrow ${CMAKE_THREAD_LIBS_INIT})
enable_testing()
add_subdirectory(src)
add_subdirectory(tests)

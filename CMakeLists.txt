set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
cmake_minimum_required(VERSION 2.8)
project(qarrow)

find_package(arrow REQUIRED)
include(arrow)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK)
find_package(Boost 1.58.0 COMPONENTS log log_setup system thread timer prg_exec_monitor)
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

find_package(GooglePerfTools)
if(GOOGLE_PERFTOOLS_FOUND)
  include_directories(${GOOGLE_PERFTOOLS_INCLUDE_DIR})
  link_libraries(${TCMALLOC_LIBRARIES} ${STACKTRACE_LIBRARIES} ${PROFILER_LIBRARIES})
  #link_libraries(profiler)
endif(GOOGLE_PERFTOOLS_FOUND)

include_directories(src)
link_directories()
link_libraries()

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_exceutable(main main.cpp)
target_link_libraries(main qarrow)
enable_testing()
add_subdirectory(src)
add_subdirectory(tests)

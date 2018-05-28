include_directories(../src)


#link_libraries(${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} qarrow ${CMAKE_THREAD_LIBS_INIT})
add_executable(arrowTest test.cpp)

target_link_libraries(arrowTest ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} qarrow)

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options( arrowTest PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options( arrowTest PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( arrowTest PRIVATE /W4 /w44265 /w44061 /w44062 )
endif()

enable_testing()
add_test(arrowTest arrowTest)

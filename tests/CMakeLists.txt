include_directories(../src)

link_libraries(boost_unit_test_framework qarrow)
add_executable(arrowTest test.cpp)

enable_testing()
add_test(arrowTest arrowTest)

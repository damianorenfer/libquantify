find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS}
                    ${CMAKE_SOURCE_DIR}/include)

file(GLOB TESTS_SRCS *.cpp)
file(GLOB TESTS_HEADERS *.h)

add_executable(allTests ${TESTS_SRCS} ${TESTS_HEADERS})
target_link_libraries(allTests
                      quantify
                      ${GTEST_BOTH_LIBRARIES})

add_test(AllTests allTests)

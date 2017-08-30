project (quantify)
cmake_minimum_required (VERSION 2.8)

option(WITH_TESTING "Build test programs" OFF)

set (QUANTIFY_SOVERSION "0")
set (QUANTIFY_VERSION "0.1.1")

set (WARNINGS "-Werror -W -Wall -Wextra -Wundef -Wunused -Wuninitialized -Wcast-align -Wpointer-arith -Woverloaded-virtual -Wnon-virtual-dtor -fno-common")
set (VISIBILITY "-fvisibility=hidden -fvisibility-inlines-hidden")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${WARNINGS}")

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory (src)

if(WITH_TESTING)
	enable_testing()
	add_subdirectory (test)
endif(WITH_TESTING)

if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
        set (CMAKE_INSTALL_LIBDIR lib)
endif (NOT DEFINED CMAKE_INSTALL_LIBDIR)

set (prefix ${CMAKE_INSTALL_PREFIX})
set (exec_prefix ${CMAKE_INSTALL_PREFIX})
set (libdir ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})
set (includedir ${CMAKE_INSTALL_PREFIX}/include)

configure_file (
        ${CMAKE_CURRENT_SOURCE_DIR}/libquantify.pc.in
        ${CMAKE_CURRENT_BINARY_DIR}/libquantify.pc
        @ONLY
)

install (DIRECTORY
        include/quantify DESTINATION include
)

install (FILES
        ${CMAKE_CURRENT_BINARY_DIR}/libquantify.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

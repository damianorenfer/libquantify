file(GLOB QUANTIFY_SRCS *.cpp)
file(GLOB QUANTIFY_HEADERS ${CMAKE_SOURCE_DIR}/include/quantify/*.h)

add_library (
    quantify
    SHARED
    ${QUANTIFY_SRCS}
    ${QUANTIFY_HEADERS}
)

set_target_properties (quantify PROPERTIES
                       SOVERSION "${QUANTIFY_SOVERSION}"
                       VERSION "${QUANTIFY_VERSION}"
)

if (NOT WIN32)
        include (GNUInstallDirs)
endif ()

install (TARGETS
         quantify
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

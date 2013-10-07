find_package(Doxygen)

if(DOXYGEN_FOUND)
    configure_file(${PROJECT_SOURCE_DIR}/docs/Doxyfile.in ${PROJECT_BINARY_DIR}/docs/Doxyfile @ONLY)
    add_custom_target(docs ALL ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/docs/Doxyfile  COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)

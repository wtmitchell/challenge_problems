add_library(util
  Timer.cpp
  )

#if (GMP_FOUND)
#  include_directories(${GMP_INCLUDE_DIR})
#  set_source_files_properties(ByteVector.cpp COMPILE_FLAGS "-DUSE_GMP")
#  target_link_libraries(util ${GMP_LIBRARY})
#endif()

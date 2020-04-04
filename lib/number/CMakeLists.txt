add_library(number
  Miscellaneous.cpp
  Root.cpp
  )
target_link_libraries(number GMP::GMPXX GMP::GMP)
target_include_directories(number PUBLIC ${PROJECT_SOURCE_DIR}/include)
enable_warnings_for(number)

add_library(number
  Miscellaneous.cpp
  Root.cpp
  )
target_link_libraries(number GMP::GMPXX GMP::GMP)

add_library(util
  Timer.cpp
  )
target_include_directories(util PUBLIC ${PROJECT_SOURCE_DIR}/include)
enable_warnings_for(util)

add_executable(pe main.cpp)
target_link_libraries(pe
  project_euler
  util
  )
enable_warnings_for(pe)

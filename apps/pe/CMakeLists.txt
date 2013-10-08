include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(pe main.cpp)
target_link_libraries(pe
  problems
  util
  )


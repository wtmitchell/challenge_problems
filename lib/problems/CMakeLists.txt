set(problem_files
  0001-0050/Problem1.cpp
  )

include_directories(${PROJECT_SOURCE_DIR}/include/problems/0001-0050)

# Make the generated source files
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Factory.cpp
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_Factory.py ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/generate_Factory.py ${problem_files}
  )

include_directories(${EULER_BINARY_DIR})
include_directories(${EULER_SOURCE_DIR})
set(gen_files Factory.cpp)

add_library(problems
  Invalid.cpp
  ${problem_files}
  ${gen_files}
  )

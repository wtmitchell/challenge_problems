set(project_euler_files
  0001-0050/Problem1.cpp
  0001-0050/Problem2.cpp
  0001-0050/Problem3.cpp
  0001-0050/Problem4.cpp
  0001-0050/Problem5.cpp
  0001-0050/Problem6.cpp
  0001-0050/Problem7.cpp
  0001-0050/Problem8.cpp
  0001-0050/Problem9.cpp
  0001-0050/Problem10.cpp
  0001-0050/Problem11.cpp
  0001-0050/Problem12.cpp
  0001-0050/Problem13.cpp
  0001-0050/Problem14.cpp
  0001-0050/Problem15.cpp
  0001-0050/Problem16.cpp
  0001-0050/Problem17.cpp
  )

include_directories(${PROJECT_SOURCE_DIR}/include/project_euler/0001-0050)

# Make the generated source files
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Factory.cpp
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_Factory.py ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/include/project_euler/
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/generate_Factory.py ${problem_files}
  )

include_directories(${EULER_BINARY_DIR})
include_directories(${EULER_SOURCE_DIR})
set(gen_files Factory.cpp)

add_library(project_euler
  Invalid.cpp
  Problem.cpp
  ${project_euler_files}
  ${gen_files}
  )

target_link_libraries(project_euler GMP::GMPXX GMP::GMP)
enable_warnings_for(project_euler)

set(TEST_LINK_COMPONENTS
  project_euler
  )

set(project_euler_sources
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

add_unittest(project_euler_tests
  ${project_euler_sources}
  )

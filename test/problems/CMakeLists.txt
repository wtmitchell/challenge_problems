set(TEST_LINK_COMPONENTS
  problems
  )

set(problemSources
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
  )

add_unittest(problemsTests
  ${problemSources}
  )

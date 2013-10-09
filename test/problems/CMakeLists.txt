set(TEST_LINK_COMPONENTS
  problems
  )

set(problemSources
  0001-0050/Problem1.cpp
  0001-0050/Problem2.cpp
  0001-0050/Problem3.cpp
  )

add_unittest(problemsTests
  ${problemSources}
  )

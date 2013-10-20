set(TEST_LINK_COMPONENTS
  )

set(numberSources
  Divisor.cpp
  Palindrome.cpp
  Prime.cpp
  Root.cpp
  )

add_unittest(numberTests
  ${numberSources}
  )

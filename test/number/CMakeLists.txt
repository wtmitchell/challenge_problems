set(TEST_LINK_COMPONENTS
  )

set(numberSources
  Palindrome.cpp
  Prime.cpp
  )

add_unittest(numberTests
  ${numberSources}
  )

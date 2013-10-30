set(TEST_LINK_COMPONENTS
  gmpxx gmp
  number
  )

set(numberSources
  Divisor.cpp
  Figurate.cpp
  Limits.cpp
  Miscellaneous.cpp
  Palindrome.cpp
  Prime.cpp
  Root.cpp
  )

add_unittest(numberTests
  ${numberSources}
  )

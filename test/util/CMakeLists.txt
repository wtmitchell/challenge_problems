set(TEST_LINK_COMPONENTS
  util
  )

set(utilSources
  Bits.cpp
  )

add_unittest(utilTests
  ${utilSources}
  )

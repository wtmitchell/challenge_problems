set(TEST_LINK_COMPONENTS
  util
  )

set(utilSources
  PlaceHolder.cpp
  )

add_unittest(utilTests
  ${utilSources}
  )

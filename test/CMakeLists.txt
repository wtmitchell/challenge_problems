include(GetGoogletest)
include(GoogleTest)
find_package(Threads)

function(add_unittest test_name)
  add_executable(${test_name} ${ARGN})
  target_link_libraries(${test_name}
    gtest
    gtest_main
    ${CMAKE_THREAD_LIBS_INIT}
    ${TEST_LINK_COMPONENTS}
    )

  # Can either tell CTest about every single unit test, or only
  # tell it about the test executable
  #add_test(${test_name} ${CMAKE_BINARY_DIR}/${test_name})
  gtest_discover_tests(${test_name})
  if (USE_VALGRIND_MEMCHECK)
    set(memcheck_command "${CTEST_MEMORYCHECK_COMMAND} ${CTEST_MEMORYCHECK_COMMAND_OPTIONS}")
    separate_arguments(memcheck_command)
    add_test(memcheck_${test_name} ${memcheck_command} ${CMAKE_BINARY_DIR}/${test_name})
  endif()
endfunction()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(number)
add_subdirectory(project_euler)
add_subdirectory(util)

# -*- cmake -*-

#[=======================================================================[.rst:
FindGMP
-------

Finds the GMP (The GNU Multiple Precision Arithmetic Library) library.

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``GMP::GMP``
  The GMP library
``GMP::GMPXX``
  The C++ bindings for GMP

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``GMP_FOUND``
  True if the system has the GMP library.
``GMPXX_FOUND``
  True if the system has the C++ bindings for the GMP library.
``GMP_VERSION``
  The version of the GMP library which was found.
``GMPXX_VERSION``
  The version of the GMPXX library which was found.
``GMP_INCLUDE_DIRS``
  Include directories needed to use GMP.
``GMPXX_INCLUDE_DIRS``
  Include directories needed to use GMPXX.
``GMP_LIBRARIES``
  Libraries needed to link to GMP.
``GMPXX_LIBRARIES``
  Libraries needed to link to GMPXX.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``GMP_INCLUDE_DIR``
  The directory containing ``gmp.h``.
``GMPXX_INCLUDE_DIR``
  The directory containing ``gmpxx.h``.
``GMP_LIBRARY``
  The path to the GMP library.
``GMPXX_LIBRARY``
  The path to the GMP library.

#]=======================================================================]


# Try to use pkg-config, if available
find_package(PkgConfig)
pkg_check_modules(PC_GMP QUIET gmp)
pkg_check_modules(PC_GMPXX QUIET gmpxx)


find_path(GMP_INCLUDE_DIR
  NAMES gmp.h
  PATHS ${PC_GMP_INCLUDE_DIRS}
  PATH_SUFFIXES gmp
)
find_path(GMPXX_INCLUDE_DIR
  NAMES gmpxx.h
  PATHS ${PC_GMPXX_INCLUDE_DIRS}
  PATH_SUFFIXES gmpxx
)

find_library(GMP_LIBRARY
  NAMES gmp
  PATHS ${PC_GMP_LIBRARY_DIRS}
)

find_library(GMPXX_LIBRARY
  NAMES gmpxx
  PATHS ${PC_GMPXX_LIBRARY_DIRS}
)

# TODO Make this more intelligent
set(GMP_VERSION ${PC_GMP_VERSION})
set(GMPXX_VERSION ${PC_GMPXX_VERSION})


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP
  FOUND_VAR GMP_FOUND
  REQUIRED_VARS
    GMP_LIBRARY
    GMP_INCLUDE_DIR
  VERSION_VAR GMP_VERSION
)
find_package_handle_standard_args(GMPXX
  FOUND_VAR GMPXX_FOUND
  REQUIRED_VARS
    GMPXX_LIBRARY
    GMPXX_INCLUDE_DIR
  VERSION_VAR GMPXX_VERSION
)


if(GMP_FOUND)
  set(GMP_LIBRARIES ${GMP_LIBRARY})
  set(GMP_INCLUDE_DIRS ${GMP_INCLUDE_DIR})
  set(GMP_DEFINITIONS ${PC_GMP_CFLAGS_OTHER})
endif()

if(GMPXX_FOUND)
  set(GMPXX_LIBRARIES ${GMPXX_LIBRARY})
  set(GMPXX_INCLUDE_DIRS ${GMPXX_INCLUDE_DIR})
  set(GMPXX_DEFINITIONS ${PC_GMPXX_CFLAGS_OTHER})
endif()


if(GMP_FOUND AND NOT TARGET GMP::GMP)
  add_library(GMP::GMP UNKNOWN IMPORTED)
  set_target_properties(GMP::GMP PROPERTIES
    IMPORTED_LOCATION "${GMP_LIBRARY}"
    INTERFACE_COMPILE_OPTIONS "${PC_GMP_CFLAGS_OTHER}"
    INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
  )
endif()

if(GMPXX_FOUND AND NOT TARGET GMP::GMPXX)
  add_library(GMP::GMPXX UNKNOWN IMPORTED)
  set_target_properties(GMP::GMPXX PROPERTIES
    IMPORTED_LOCATION "${GMPXX_LIBRARY}"
    INTERFACE_COMPILE_OPTIONS "${PC_GMPXX_CFLAGS_OTHER}"
    INTERFACE_INCLUDE_DIRECTORIES "${GMPXX_INCLUDE_DIR}"
  )
endif()

mark_as_advanced(
  GMP_INCLUDE_DIR
  GMPXX_INCLUDE_DIR
  GMP_LIBRARY
  GMPXX_LIBRARY
)

# compatibility variables
set(GMP_VERSION_STRING ${GMP_VERSION})
set(GMPXX_VERSION_STRING ${GMPXX_VERSION})

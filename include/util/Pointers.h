//===-- util/Pointers.h ---------------------------------------*- C++ -*---===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file contains convenience functions for working with pointers
///
//===----------------------------------------------------------------------===//
#ifndef UTIL_POINTERS_H_INCLUDED
#define UTIL_POINTERS_H_INCLUDED

#include <memory>

// This is because of the oversight in the C++11 standard. Implementation by
// Herb Sutter http://herbsutter.com/gotw/_102/
/// Analog of make_shared in \<memory\> - Expected to be superseded in C++14
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif

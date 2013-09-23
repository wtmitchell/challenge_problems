//===-- util/Pointers.cpp - Pointer conveniences --------------*- C++ -*---===//
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
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif

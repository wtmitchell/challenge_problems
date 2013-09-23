//===-- util/Vector.h - Miscellaneous vector functions -------*- C++ -*----===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file contains miscellaneous functions useful when working with
/// std::vector
///
//===----------------------------------------------------------------------===//
#ifndef UTIL_VECTOR_H_INCLUDED
#define UTIL_VECTOR_H_INCLUDED

#include <vector>

namespace util {
template <typename T>
typename std::vector<T>::size_type binary_search(const std::vector<T> &vect,
                                                 const T &target);
}

template <typename T>
typename std::vector<T>::size_type
util::binary_search(const std::vector<T> &vect, const T &target) {
  typename std::vector<T>::size_type low = 0;
  typename std::vector<T>::size_type high = vect.size();
  typename std::vector<T>::size_type mid = (high - low) / 2 + low;

  while (low < high) {
    if (vect[mid] == target)
      return mid;
    if (vect[mid] < target)
      low = mid;
    else
      high = mid;
    mid = (high - low) / 2 + low;
  }

  return vect.size();
}

#endif

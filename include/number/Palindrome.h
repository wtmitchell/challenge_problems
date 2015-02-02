//===-- number/Palindrome.h -------------------------------------*- C++ -*-===//
//
// Challenge Problem solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Contains functions relating to palindromic numbers
///
//===----------------------------------------------------------------------===//
#ifndef NUMBER_PALINDROME_H_INCLUDED
#define NUMBER_PALINDROME_H_INCLUDED

#include <algorithm>
#include <vector>

namespace number {
/// Determines whether the number is a palindrome
template <class T>
bool isPalindrome(const T candidate, const T radix = static_cast<T>(10));
}

template <class T> bool number::isPalindrome(const T candidate, const T radix) {
  T reversed = static_cast<T>(0);
  T partial = candidate;

  while (partial > static_cast<T>(0)) {
    reversed *= radix;
    reversed += partial % radix;
    partial /= radix;
  }

  return candidate == reversed;
}

#endif

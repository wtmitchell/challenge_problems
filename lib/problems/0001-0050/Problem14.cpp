//===-- problems/Problem14.cpp ----------------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class problems::Problem14
/// \brief Longest Collatz sequence
///
/// Question
/// --------
/// The following iterative sequence is defined for the set of positive
/// integers:
///
/// \f{eqnarray}{
/// n_{i+1} &=& n_i/2 \qquad \text{($n_i$ is even)}\\
/// n_{i+1} &=& 3n_i + 1 \qquad \text{($n_i$ is odd)}
/// \f}
///
/// Using the rule above and starting with 13, we generate the following
/// sequence:
/// \f[13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1\f]
///
/// It can be seen that this sequence (starting at 13 and finishing at 1)
/// contains 10 terms. Although it has not been proved yet (Collatz Problem), it
/// is thought that all starting numbers finish at 1.
///
/// Which starting number, under one million, produces the longest chain?
///
/// NOTE: Once the chain starts the terms are allowed to go above one million.
//===----------------------------------------------------------------------===//
#include "Problem14.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;
#include <vector>
using std::vector;

string problems::Problem14::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The longest Collatz sequence starting at under one million starts at "
     << start << " and has length " << length;

  return ss.str();
}

std::string problems::Problem14::description() const {
  return "Problem 14: Longest Collatz sequence";
}

void problems::Problem14::solve() {
  start = faster(1000000ull, 500000);
  solved = true;
}

unsigned long long
problems::Problem14::bruteForce(const unsigned long long limit) const {
  auto maxLength = 0ull;
  auto maxStart = 0ull;

  for (auto i = 1ull; i < limit; ++i) {
    auto j = i;
    auto jLength = 1ull;
    while (j != 1) {
      if (j % 2 == 0) {
        j /= 2;
        jLength += 1;
        continue;
      }
      // We can skip over one term since next term will definitely not be 1
      j = (3 * j + 1) / 2;
      jLength += 2;
    }
    if (jLength > maxLength) {
      maxLength = jLength;
      maxStart = i;
    }
  }

  length = maxLength;
  return maxStart;
}

unsigned long long problems::Problem14::faster(
    const unsigned long long limit,
    const vector<unsigned long long>::size_type cacheSize) const {
  auto maxLength = 0ull;
  auto maxStart = 0ull;

  vector<unsigned long long> cache(cacheSize, 0ull);

  for (auto n = 1ull; n < limit; ++n) {
    auto len = 1ull;
    for (auto i = n; i != 1;) {
      // Attempt cache lookup
      if (i < cacheSize && cache[i - 1] != 0) {
        len += cache[i - 1] - 1;
        break;
      }

      // Not in cache
      if (i % 2 == 0) {
        i /= 2;
        len += 1;
        continue;
      }

      // Skip a step since we know length must go at least 2 steps more
      i = (3 * i + 1) / 2;
      len += 2;
    }
    // See if better than best known
    if (len > maxLength) {
      maxLength = len;
      maxStart = n;
    }
    // Cache results that are now easily known if possible
    if (n >= cacheSize)
      continue;
    cache[n - 1] = len;
    if (2 * n >= cacheSize)
      continue;
    cache[2 * n - 1] = len + 1;
  }

  length = maxLength;
  return maxStart;
}

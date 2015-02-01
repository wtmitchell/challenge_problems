//===-- project_euler/Problem15.cpp -----------------------------*- C++ -*-===//
//
// ProjectEuler.net solutions by Will Mitchell
//
// This file is distributed under the MIT License. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
///
/// \class project_euler::Problem15
/// \brief Lattice paths
///
/// Question
/// --------
/// Starting in the top left corner of a 2x2 grid, and only being able to move
/// to the right and down, there are exactly 6 routes to the bottom right
/// corner.
///
/// How many such routes are there through a 20x20 grid?
///
/// Analysis
/// --------
/// To go through a axb grid, it is just a+b choose b
//===----------------------------------------------------------------------===//
#include "Problem15.h"

#include <sstream>
using std::stringstream;
#include <string>
using std::string;

string project_euler::Problem15::answer() {
  if (!solved)
    solve();

  stringstream ss;

  ss << "The number of paths through a 20x20 grid is " << value;

  return ss.str();
}

std::string project_euler::Problem15::description() const {
  return "Problem 15: Lattice paths";
}

void project_euler::Problem15::solve() {
  mpz_bin_uiui(value.get_mpz_t(), 40, 20);
  solved = true;
}

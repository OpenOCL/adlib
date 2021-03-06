/*
 *
 *    Copyright (C) 2019 Jonas Koenemann
 *
 *    This program is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public
 *    License along with this program;
 *    if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#ifndef ADLIB_ASSIGNMENT_H_
#define ADLIB_ASSIGNMENT_H_

#include <string>
#include <map>

#include "typedefs.h"

namespace adlib {

class Symbolic;

// Assigns values to a symbolic primitive.
class Assignment
{
 public:

   Assignment() { }

  // Constructs and Assignment from symbolic primitives and values.
  // Args:
  //  p_l: List of symbolic primitives
  //  d_l: List of values
  Assignment(const SymbolicList& p_l, const DoubleList& d_l);

  // Finds and returns the assigned value for a primitive.
  // Args:
  //  id: the id of the primitive
  double get(const Symbolic& sym) const;

  // Initializes the map of assignments
  static std::map<const Symbolic*,double> defineAssignmentMap(const SymbolicList& p_l, const DoubleList& d_l);

 private:
  // stores assigned values
  const std::map<const Symbolic*,double> assignmentMap;
};

} // namespace adlib

#endif // ADLIB_ASSIGNMENT_H_

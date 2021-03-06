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
#include "assignment.h"

#include "utils.h"
#include "exceptions.h"
#include "atomic.h"

namespace adlib {

Assignment::Assignment(const SymbolicList& p_l, const DoubleList& d_l)
    : assignmentMap(Assignment::defineAssignmentMap(p_l,d_l))
{
}

double Assignment::get(const Symbolic& sym) const
{
  auto el = assignmentMap.find(&sym);
  if (el == assignmentMap.end())
  {
    throw AdlibException("Assignment element does not exist");
  }
  return el->second;
}

std::map<const Symbolic*,double> Assignment::defineAssignmentMap(
    const SymbolicList& p_l, const DoubleList& d_l)
{
  std::map<const Symbolic*,double> m;
  assertEqual(p_l.size(), d_l.size());
  for (unsigned int i=0; i < p_l.size(); i++) {
    m[p_l[i]] = d_l[i];
  }
  return m;
}

} // namespace adlib

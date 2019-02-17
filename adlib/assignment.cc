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

namespace adlib {

Assignment::Assignment(const SymPrimitiveList& p_l, const DoubleList& d_l)
{
  assertEqual(p_l.size(), d_l.size());
  for (int i=0; i < p_l.size(); i++) {
    const SymPrimitive& p = p_l[i];
    assignmentMap[p.id] = d_l[i];
  }
}

double Assignment::get(const std::string& id)
{
  const std::map<std::string,double>::iterator el = assignmentMap.find(id);
  if (el == assignmentMap.end())
  {
    throw AdlibException("Assignment element does not exist");
  }
  return *el;
}

} // namespace adlib

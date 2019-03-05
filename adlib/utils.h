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
#ifndef ADLIB_UTILS_H
#define ADLIB_UTILS_H

#include <cassert>

namespace adlib
{


  static inline void assertEqual(double a, double b)
  {
    assert(a==b);
  }

  static inline void assertAlmostEqual(double a, double b, double eps=1e-4)
  {
    assert(abs(a-b)<eps);
  }

}

#endif // ADLIB_UTILS_H

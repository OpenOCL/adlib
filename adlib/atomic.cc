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
#include "atomic.h"


namespace adlib
{

DoubleExpression::DoubleExpression(double v) : v(v)
{
}
const DoubleExpression& DoubleExpression::eval_fcn()
{
  return this;
}

// Operation with single input and a single output
UnaryOperation::UnaryOperation(const Expression& x) : input(x)
{
}
const Expression& UnaryOperation::eval_fcn(const Assignment& a)
{
  Expression in = input.eval_fcn(a);
  return this->fcn(in);
}

// Operation with two inputs and a asingle output
BinaryOperation::BinaryOperation(const Expression& x, const Expression& y) :
    input1(x), input2(y)
{
}
const Expression& BinaryOperation::eval_fcn(const Assignment& a)
{
  Expression in1 = input1.eval_fcn(a);
  Expression in2 = input2.eval_fcn(a);
  return this->fcn(in1, in2);
}

} // namespace adlib

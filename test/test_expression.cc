
#include <vector>
#include <iostream>

#include "atomic.h"
#include "assignment.h"
#include "utils.h"
#include "typedefs.h"

int main()
{
  {
    // with numeric
    auto a = adlib::Numeric(4);
    auto b = adlib::Numeric(2);

    auto c = adlib::mul(a,b);
    auto d = adlib::add(c,a);

    adlib::assertAlmostEqual( d.eval_fcn(), 12 );
  }

  {
    // with symbolics
    auto a = adlib::Symbolic();
    auto b = adlib::Symbolic();

    auto c = adlib::mul(a,b);
    auto d = adlib::add(c,a);

    // a=4, b=2 -> c=8 -> d=12
    adlib::assertAlmostEqual( d.eval_fcn({&a,&b},{4,2}), 12 );
  }

  {
    // with numeric and symbolic
    auto a = adlib::Numeric(4);
    auto b = adlib::Symbolic();

    auto c = adlib::mul(a,b);
    auto d = adlib::add(c,a);

    adlib::assertAlmostEqual( d.eval_fcn({&b}, {2}), 12 );
  }

  // // scalar unary operations
  // a = adlib::Numeric(4);
  //
  // r = adlib::uplus(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 4 );
  //
  // r = adlib::negate(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), -4 );
  //
  // r = adlib::exp(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 54.5981500331 );
  //
  // r = adlib::log(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.60205999132 );
  //
  // r = adlib::sqrt(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 2 );
  //
  // r = adlib::sq(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 4 );
  //
  // r = adlib::sin(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), -0.7568024953 );
  //
  // r = adlib::cos(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), -0.65364362086 );
  //
  // r = adlib::tan(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 1.15782128235 );
  //
  // a = adlib::Numeric(0.44);
  //
  // r = adlib::asin(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.4555986733958234 );
  //
  // r = adlib::acos(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 1.1151976533990733 );
  //
  // r = adlib::atan(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.41450687458478597 );
  //
  // r = adlib::abs(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.44 );
  //
  // r = adlib::inv(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 2.272727272727273 );
  //
  // r = adlib::sinh(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.45433539871409734 );
  //
  // r = adlib::cosh(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 1.0983718197972387 );
  //
  // r = adlib::tanh(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.4136444421871352 );
  //
  // r = adlib::asinh(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.42691345412611653 );
  //
  // a = adlib::Numeric(2.2);
  //
  // r = adlib::acosh(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 1.4254169430706127 );
  //
  // a = adlib::Numeric(0.22);
  //
  // r = adlib::atanh(a);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.22365610902183242 );
  //
  // // binary operations
  // a = adlib::Numeric(0.33);
  // b = adlib::Numeric(4.1);
  //
  // r = adlib::plus(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 4.43 );
  //
  // r = adlib::minus(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), -3.7699999999999996 );
  //
  // r = adlib::times(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 1.353 );
  //
  // r = adlib::divide(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.0804878048780488 );
  //
  // r = adlib::pow(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.010614686047848296 );
  //
  // r = adlib::min(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.33 );
  //
  // r = adlib::max(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 4,1 );
  //
  // r = adlib::atan2(a,b);
  // adlib::assertAlmostEqual( r.eval_fcn(), 0.08031466966032468 );

}

#include "adlib/atomic.h"

int main()
{
  auto a = adlib::SymPrimitive("a");
  auto b = adlib::SymPrimitive("a");

  auto c = adlib::mul(a,b);
  auto d = adlib::add(c,a);

  d.eval_fcn(adlib::Assignment({a,b},{4,2}));

  // F = Function({a,b},{d});
  // F(4,2);

}

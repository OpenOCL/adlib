#include "atomic.h"
#include "assignment.h"
#include "utils.h"

int main()
{
  auto a = adlib::SymPrimitive();
  auto b = adlib::SymPrimitive();

  auto c = adlib::mul(a,b);
  auto d = adlib::add(c,a);

  // adlib::Assignment holds std::map to assign values to a,b
  auto assignment = adlib::Assignment({a,b},{4,2});
  // a=4, b=2 -> c=8 -> d=12
  adlib::assertEqual(d.eval_fcn(assignment).v, 12.0);

}

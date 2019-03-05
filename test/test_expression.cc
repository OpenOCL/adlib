
#include <vector>
#include <iostream>

#include "atomic.h"
#include "assignment.h"
#include "utils.h"

int main()
{
  auto a = adlib::Symbolic();
  auto b = adlib::Symbolic();

  auto c = adlib::mul(a,b);
  auto d = adlib::add(c,a);

  // adlib::Assignment holds std::map to assign values to a,b
  auto assignment = adlib::Assignment({&a,&b},{4,2});
  // a=4, b=2 -> c=8 -> d=12
  adlib::assertEqual(d.eval_fcn(assignment), 12.0);
  std::cout << d.eval_fcn(assignment) << std::endl;

  //std::vector<adlib::SymPrimitive> syms{a,b};
  //auto ass2 = adlib::Assignment({&syms[0],&syms[1]},{4,2}); // not allowed

}

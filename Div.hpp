#ifndef DIV_HPP
#define DIV_HPP
#include "base.hpp"
#include <string>
using namespace std;
class Div: public Op
{
  private:
	Base* L1;
	Base* L2;
  public:
	Div(Base*, Base*);
	double evaluate();
	string stringify();
};
#endif

#ifndef ADD_HPP
#define ADD_HPP
#include "base.hpp"
#include <string>
using namespace std;
class Add: public Op
{
  private:
	Base* L1;
	Base* L2;
  public:
	Add(Base*, Base*);
	double evaluate();
	string stringify();
};
#endif

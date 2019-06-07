#ifndef POW_HPP
#define POW_HPP
#include "base.hpp"
#include <string>
using namespace std;
class Pow: public Op
{
 private:
	Base* L1;
	Base* L2;   
public:
            Pow(Base*, Base*);
	double evaluate();
	string stringify();
       };
 #endif

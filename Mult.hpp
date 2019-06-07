#ifndef MULT_HPP
#define MULT_HPP
#include "base.hpp"
using namespace std;
class Mult : public Op
{
 private:
	Base* L1;
	Base* L2;      
public:
            Mult(Base*, Base*);
	double evaluate();
	string stringify();
       };
 #endif

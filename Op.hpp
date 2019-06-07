#ifndef OP_HPP
#define OP_HPP
#include "base.hpp"
#include <string>
using namespace std;

class Op : public Base
{

    protected:
        double num;
    public:
	Op();
        Op(double n);
        double evaluate();
        string stringify(); 
	Base* get_left();
        Base* get_right();
	Iterator* create_iterator();
};

#endif


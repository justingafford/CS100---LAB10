#ifndef RAND_HPP
#define RAND_HPP
#include "base.hpp"
#include <string>
using namespace std;

class Rand : public Base
{
    private:
        double num;
    public:
        Rand();
        double evaluate();
        string stringify();
};

#endif


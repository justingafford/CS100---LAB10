#ifndef COMPOSITE_HEADER
#define COMPOSITE_HEADER

#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h> 
#include <string>
#include "iterator.h"
#include "visitor.hpp"
using namespace std;

class Iterator;
class NullIterator;
class UnaryIterator;
class CountVisitor;
//Abstract Base Class
class Base {
    public:
        Base(){};

        //virtual
        virtual string stringify() = 0;
        virtual double evaluate() = 0;
        virtual void accept(CountVisitor* a) = 0;
        virtual Iterator* create_iterator() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
};

//Leaf Class
class Op: public Base {
    private:
        double value;

    public:
        Op();
        Op(double val);
        void accept(CountVisitor* a);
        Base* get_left();
        Base* get_right();
        double evaluate(); 
        string stringify();
        Iterator* create_iterator();
};

class Rand : public Base
{
    private:
        double num;
    public:
        Rand();
        void accept(CountVisitor* a);
        Base* get_left();
        Base* get_right();
        double evaluate();
        string stringify();
        Iterator* create_iterator();
};

//Composite Base Classes
class Operator: public Base {
    protected:
        Base* left, *right;
    public:
        Operator();
        Operator(Base* l, Base* r);

        Base* get_left();
        Base* get_right();
        virtual void accept(CountVisitor* a) = 0;
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator();
};

class UnaryOperator: public Base {
    protected:
        Base* child;
    public:
        UnaryOperator();
        UnaryOperator(Base* c);
 	virtual void accept(CountVisitor* a) = 0;
        Base* get_left();
        Base* get_right();
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator();
};

//Composite Classes
class Add: public Operator {
    public:
        Add();
        Add(Base* left, Base* right);
        void accept(CountVisitor* a);
        string stringify();
        double evaluate();
};

class Sub: public Operator {
    public:
        Sub();
        Sub(Base* left, Base* right);
        void accept(CountVisitor* a);
        string stringify();
        double evaluate();
};

class Mult: public Operator {
    public:
        Mult();
        Mult(Base* left, Base* right);
        void accept(CountVisitor* a);
        string stringify();
        double evaluate();
};

class Div: public Operator {
     public:
        Div();
        Div(Base* left, Base* right);
        void accept(CountVisitor* a);
        string stringify();
        double evaluate();
};
class Pow: public Operator {
    public:
        Pow();
        Pow(Base* left, Base* right);
        void accept(CountVisitor* a);
        string stringify();
        double evaluate();
};

class Root: public UnaryOperator {
    public:
        Root() : UnaryOperator() { }
	Root(Base* child) : UnaryOperator(child) { }
        void accept(CountVisitor* a);
	string stringify();
        double evaluate();
};

class Ceil : public UnaryOperator
{
    public: 
        Ceil() : UnaryOperator() {};
        Ceil(Base* cory) : UnaryOperator(cory){};
        void accept(CountVisitor* a);
        double evaluate();
        string stringify() {};
};

class Floor : public UnaryOperator
{
    public: 
        Floor() : UnaryOperator() {};
        Floor(Base* cory) : UnaryOperator(cory){};
        void accept(CountVisitor* a);
        double evaluate();
        string stringify() {};
};

class Abs : public UnaryOperator
{
    public: 
        Abs() : UnaryOperator() {};
        Abs(Base* cory) : UnaryOperator(cory){};
        void accept(CountVisitor* a);
        double evaluate();
        string stringify() {};
};

class Trunc : public UnaryOperator
{
    public: 
        Trunc() : UnaryOperator() {};
        Trunc(Base* cory) : UnaryOperator(cory){};
        void accept(CountVisitor* a);
        string stringify();
        double evaluate() {return child->evaluate();};
};

class Paren : public UnaryOperator
{
    public: 
        Paren(Base* cory) : UnaryOperator(cory){};
        void accept(CountVisitor* a);
        string stringify();
        double evaluate() {return child->evaluate();};
};

#endif

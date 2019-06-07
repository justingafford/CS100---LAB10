#include "iterator.h"
#include "compositepattern.h"
#include <string>
#include <cmath>
//**Op Class**
Op::Op() : Base(), value(0){}

Op::Op(double val) : Base(), value(val){}

Base* Op::get_left() { return NULL; }

Base* Op::get_right() { return NULL; }

string Op::stringify() {
	return to_string(value);
}

double Op::evaluate() { return this->value; }

Iterator* Op::create_iterator() { return new NullIterator(this); }

void Op::accept(CountVisitor* a) { a->visit_op(); };

Base* Rand::get_left() { return NULL; }

Base* Rand::get_right() { return NULL; }

Rand::Rand() {num = rand() % 100;};
 
double Rand::evaluate() {return num;}

void Rand::accept(CountVisitor* a) { a->visit_rand(); };

 
string Rand::stringify() {return to_string(num);}

Iterator* Rand::create_iterator() { return new NullIterator(this); }

//**Operator Base Class**
Operator::Operator() : Base(){ }

Operator::Operator(Base* l, Base* r) : left(l), right(r){  }

Base* Operator::get_left() { return left; }

Base* Operator::get_right() { return right; }

Iterator* Operator::create_iterator() { return new BinaryIterator(this); }

//**Unary Base Class**
UnaryOperator::UnaryOperator() : Base(){}

UnaryOperator::UnaryOperator(Base* c) : child(c) { }

Base* UnaryOperator::get_left() { return child; }

Base* UnaryOperator::get_right() { return NULL; }

Iterator* UnaryOperator::create_iterator() { return new UnaryIterator(this); }

//**Add Class**
Add::Add() : Operator() { }

Add::Add(Base* left, Base* right) : Operator(left,right) { }

string Add::stringify() {
	string temp = left ->stringify() + " + " + right ->stringify();
	return temp;
}
void Add::accept(CountVisitor* a) { a->visit_add(); };

double Add::evaluate() { return this->left->evaluate() + this->right->evaluate(); }

//**Sub Class**
Sub::Sub() : Operator() { }

Sub::Sub(Base* left, Base* right) : Operator(left,right) { }
void Sub::accept(CountVisitor* a) { a->visit_sub(); };

string Sub::stringify() {
	string temp = left ->stringify() + " - " + right ->stringify();
	return temp;
}

double Sub::evaluate() { return this->left->evaluate() - this->right->evaluate(); }

//**Mult Class**

Mult::Mult() : Operator() { }

Mult::Mult(Base* left, Base* right) : Operator(left,right) { }
void Mult::accept(CountVisitor* a) { a->visit_mult(); };

string Mult::stringify() {
	string temp = left ->stringify() + " + " + right ->stringify();
	return temp;
}

double Mult::evaluate() { return this->left->evaluate() * this->right->evaluate(); }


//**Div Class**
Div::Div() : Operator() { }

Div::Div(Base* left, Base* right) : Operator(left,right) { }

string Div::stringify() {
	string temp = left ->stringify() + " / " + right ->stringify();
	return temp;
}
void Div::accept(CountVisitor* a) { a->visit_div(); };

double Div::evaluate() { return this->left->evaluate() / this->right->evaluate(); }

//**Pow Class**
Pow::Pow() : Operator() { }

Pow::Pow(Base* left,Base* right) : Operator(left,right) { }

string Pow::stringify() {
	string temp = left ->stringify() + " ** " + right ->stringify();
	return temp;
}

double Pow::evaluate() { return pow(this-> left  -> evaluate() , this-> right  -> evaluate()); }
void Pow::accept(CountVisitor* a) { a->visit_pow(); };

//**Root Class**

string Root::stringify() { cout << "ROOT"; }

double Root::evaluate() { return this->child->evaluate(); }

double Ceil::evaluate()
{
    return ceil(child->evaluate());
}
void Ceil::accept(CountVisitor* a) { a->visit_ceil(); };

double Floor::evaluate()
{
    return floor(child->evaluate());
}

void Floor::accept(CountVisitor* a) { a->visit_floor(); };

double Abs::evaluate()
{
    return abs(child->evaluate());
}

void Abs::accept(CountVisitor* a) { a->visit_abs(); };

string Trunc::stringify()
{
    return to_string(child->evaluate());
}

void Trunc::accept(CountVisitor* a) { a->visit_trunc(); };

string Paren::stringify()
{
    string temp = "(" + child->stringify() + ")";
    return temp;
}

void Paren::accept(CountVisitor* a) { a->visit_paren(); };


#include "Add.hpp"
#include <string>
using namespace std;

Add::Add(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Add::evaluate() {
	return L1 ->evaluate() + L2 ->evaluate();
}

string Add::stringify() {
	string temp = L1 ->stringify() + " + " + L2 ->stringify();
	return temp;
}

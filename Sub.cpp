#include "Sub.hpp"
#include <string>
using namespace std;
Sub::Sub(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Sub::evaluate() {
	return L1 ->evaluate() - L2 ->evaluate();
}

string Sub::stringify() {
	string temp = L1 ->stringify() + " - " + L2 ->stringify();
	return temp;
}

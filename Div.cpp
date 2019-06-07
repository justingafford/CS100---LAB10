#include "Div.hpp"
#include <string>
using namespace std;

Div::Div(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Div::evaluate() {
	return L1 ->evaluate() / L2 ->evaluate();
}

string Div::stringify() {
	string temp = L1 ->stringify() + " / " + L2 ->stringify();
	return temp;
}

#include "Pow.hpp"
#include <string>
#include <cmath>
using namespace std;
	Pow::Pow(Base* l1, Base* l2): L1(l1), L2(l2) {}
	double Pow::evaluate() {
		return pow(L1 -> evaluate() , L2 -> evaluate());
	}
	string Pow::stringify() {
		string temp = L1 ->stringify() + " ** " + L2 ->stringify();
		return temp;
	}

#include <iostream>
#include <vector>
#include "compositepattern.h"

using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Pow* pow  = new Pow(add,op2);
	Sub* sub = new Sub(pow, op3);
	Root* root = new Root(sub);

	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
	int i = 1;
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		cout << "Opertaion at iteration " << i << " : ";
		cout << pre_itr->current()->stringify();
		cout << endl;
		i++;
	}
	Op* op1 = new Op(5);
	Op* op0 = new Op(10);
	Op* op5 = new Op(2);
	Op* op6 = new Op(1);
	Mult* multiply = new Mult(op1, op5);
	Sub* Subtract = new Sub(multiply, op0);
	Add* addition = new Add(Subtract, op6);
	Div* div = new Div(addition,op5);
	Root* r = new Root(div);
	cout << "Second test" << endl;
	PreOrderIterator* temp = new PreOrderIterator(r);
	int j = 1;
        for(temp->first(); !temp->is_done(); temp->next())
	{
		cout << "Operation at iteration "  << j << " : ";
		cout << temp->current()->stringify();
		cout << endl;
		j++;
	}
};


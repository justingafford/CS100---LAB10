#include "Rand.hpp"
#include <string>
#include <ctime>
using namespace std;


        Rand::Rand() {num = rand() % 100;};
        double Rand::evaluate() {return num;}
        string Rand::stringify() {return to_string(num);}


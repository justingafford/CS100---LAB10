#ifndef BASE_HPP
#define BASE_HPP
#include <string>
#include "iterator.hpp"
#include "iterator.h"
class Base {
    public:
	Base* left;
	Base* right;
        /* Constructors */
        Base() {
	    left = 0;
	    right = 0;
        };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
	virtual Iterator* create_iterator() = 0;
	virtual Base* get_left() = 0;
	virtual Base* get_right() = 0;
	virtual Iterator* create_iterator() = 0;
};

#endif

#include "base.hpp"
#include "base_factory.hpp"
#include "scifactory.hpp"
#include "doublefactory.hpp"
#include "precisionfactory.hpp"
#include "scirand.hpp"
#include "precisionrand.hpp"
#include "doublerand.hpp"
#include "sciop.hpp"
#include "precisionop.hpp"
#include "doubleop.hpp"
#include "Op.hpp"
#include "Rand.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "menu.hpp"
#include "command.hpp"
#include <iostream>
#include "gtest/gtest.h"
#include "visitor.hpp"
#include "visitor.cpp"

TEST(Tests, Test)  
{
    Base* op1 = new Op(13);
    Base* op2 = new Op(75);
    Base* add1 = new Add(op1,op2);
    CountVisitor *a = new CountVisitor();
    PreorderIterator *b = new PreorderIterator(add1);
   
    b->first();
    while(b->is_done() == false)
    {
	    b->next();
	  }
   
    EXPECT_EQ(a->op_count(),2);
    EXPECT_EQ(a->add_count(), 1);
}

#include"compositepattern.h"
#include "visitor.hpp"
#include "iterator.h"
#include <iostream>
#include "gtest/gtest.h"


TEST(IteratorTests, BinaryIter) {
  Op* op2 = new Op(69);
  Op* op1 = new Op(23);
  Div* div = new Div(op2,op1);
  Root* root = new Root(div);
  BinaryIterator* null_itr = new BinaryIterator(root);
  EXPECT_EQ(null_itr->is_done(),0);
  null_itr->first();
  EXPECT_EQ(null_itr->current()->evaluate(),3.0000000);
  EXPECT_EQ(null_itr->is_done(),0);
  null_itr->next();
  EXPECT_EQ(null_itr->is_done(),1);

}

TEST(IteratorTests, UnaryIter) {
  Op* testOp = new Op(69);
  Root* root = new Root(testOp);
  UnaryIterator* null_itr = new UnaryIterator(root);
  EXPECT_EQ(null_itr->is_done(),1);
  null_itr->first();
  EXPECT_EQ(null_itr->current()->stringify(),"69.000000");
  EXPECT_EQ(null_itr->is_done(),0);
  null_itr->next();
  EXPECT_EQ(null_itr->is_done(),1);

}

TEST(IteratorTests, NullIter) {
  Op* testOp = new Op(69);
  Root* root = new Root(testOp);
  NullIterator* null_itr = new NullIterator(root);
  EXPECT_EQ(null_itr->is_done(),1);
  null_itr->first();
  EXPECT_EQ(null_itr->is_done(),1);
  null_itr->next();
  EXPECT_EQ(null_itr->is_done(),1);	
}

TEST(IteratorTests, PreOrderIter) {
  Op* op3 = new Op(3);
  Op* op4 = new Op(4);
  Op* op2 = new Op(2);
  Add* add = new Add(op3, op4); //7
  Pow* pow  = new Pow(add,op2); //49
  Root* root = new Root(pow);
  CountVisitor* counter = new CountVisitor();
  PreOrderIterator* pre_itr = new PreOrderIterator(root);
  pre_itr->first();
  EXPECT_EQ(pre_itr->current()->stringify(),"3.000000 + 4.000000 ** 2.000000");
  pre_itr->current()->accept(counter);
  pre_itr->next();
  EXPECT_EQ(pre_itr->current()->stringify(),"3.000000 + 4.000000");
  pre_itr->current()->accept(counter);
  pre_itr->next();
  EXPECT_EQ(pre_itr->current()->stringify(),"3.000000");
  pre_itr->current()->accept(counter);
  pre_itr->next();
  EXPECT_EQ(pre_itr->current()->stringify(),"4.000000");
  pre_itr->current()->accept(counter);
  pre_itr->next();
  EXPECT_EQ(pre_itr->current()->stringify(),"2.000000");
  pre_itr->current()->accept(counter);
  pre_itr->next();
  EXPECT_EQ(pre_itr->is_done(),1);
  EXPECT_EQ(counter->add_count(),1);
  EXPECT_EQ(counter->pow_count(),1);
  EXPECT_EQ(counter->op_count(),3);
}
/*
=======

TEST(OpTests, Test1)
{
    Base* op1 = new Op(13);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(op1);

    b->first();
    b->current()->accept(a);

    EXPECT_EQ(a->op_count(),1);
    
}

TEST(RandTests, Test1)
{
    Base* op1 = new Rand(13);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(op1);

    b->first();
    b->current()->accept(a);

    EXPECT_EQ(a->rand_count(),1);
    
}

>>>>>>> 7072436139e38ffd612bb04160b92235abb10820
TEST(AddTests, Test1)  
{
    Base* op1 = new Op(13);
    Base* op2 = new Op(75);
    Base* add1 = new Add(op1,op2);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(add1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->op_count(),2);
    EXPECT_EQ(a->add_count(), 1);
}

TEST(SubTests, Test1)  
{
    Base* op1 = new Op(87);
    Base* op2 = new Op(75);
    Base* sub1 = new Sub(op1,op2);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->op_count(),2);
    EXPECT_EQ(a->sub_count(), 1);
}


TEST(DivTests, Test1)  
{
    Base* op1 = new Op(87);
    Base* op2 = new Op(75);
    Base* sub1 = new Div(op1,op2);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->op_count(),2);
    EXPECT_EQ(a->div_count(), 1);
}


TEST(PowTests, Test1)  
{
    Base* op1 = new Op(4);
    Base* op2 = new Op(2);
    Base* sub1 = new Pow(op1,op2);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->op_count(),2);
    EXPECT_EQ(a->pow_count(), 1);
}

TEST(CeilTests, Test1)  
{
    Base* op1 = new Op(87);
    Base* sub1 = new Ceil(op1);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->ceil_count(), 1);
}


TEST(FloorTests, Test1)  
{
    Base* op1 = new Op(87);
   
    Base* sub1 = new Floor(op1);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->floor_count(), 1);
}

TEST(AbsTests, Test1)  
{
    Base* op1 = new Op(87);
    Base* sub1 = new Abs(op1);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }
    EXPECT_EQ(a->abs_count(), 1);
}

TEST(TruncTests, Test1)  
{
    Base* op1 = new Op(87);
    Base* sub1 = new Trunc(op1);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->trunc_count(), 1);
}

TEST(ParenTests, Test1)  
{
    Base* op1 = new Op(87);
    Base* sub1 = new Paren(op1);
    CountVisitor *a = new CountVisitor();
    PreOrderIterator *b = new PreOrderIterator(sub1);

    b->first();
    while(b->is_done() == false)
    {
	  b->current()->accept(a);
	  b->next();
    }

    EXPECT_EQ(a->paren_count(), 1);
}
*/
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

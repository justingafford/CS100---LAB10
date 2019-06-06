#include "visitor.hpp"
CountVisitor(){}

void CountVisitor::visit_op()
{
    ops++;
}
int op_count()
{
    return ops;
}

void CountVisitor::visit_rand()
{
    rands++;
}
int CountVisitor::rand_count()
{
    return rands;
}

void CountVisitor::visit_mult()
{
    mults++;
}
int CountVisitor::mult_count()
{
    return mults;
}
void CountVisitor::visit_div()
{
    divs++;
}
int CountVisitor::div_count()
{
    return divs;
}
void CountVisitor::visit_add()
{
    add++;
}
int CountVisitor::add_count()
{
    return add;
}
void CountVisitor::visit_sub()
{
    sub++;
}
int CountVisitor::sub_count()
{
    return sub;
}
void CountVisitor::visit_pow()
{
    pow++;
}
int CountVisitor::pow_count()
{
    return pow;
}

void CountVisitor::visit_ceil()
{
    ceil++;
}
int CountVisitor::ceil_count()
{
    return ceil;
}

void CountVisitor::visit_floor()
{
    floor++;
}
int CountVisitor::floor_count()
{
    return floor;
}

void CountVisitor::visit_abs()
{
    abs++;
}
int CountVisitor::abs_count()
{
    return abs;
}

void CountVisitor::visit_trunc()
{
    trunc++;
}
int CountVisitor::trunc_count()
{
    return trunc;
}

void CountVisitor::visit_paren()
{
    paren++;
}
int CountVisitor::paren_count()
{
    return paren;
}

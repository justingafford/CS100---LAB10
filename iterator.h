#ifndef ITERATOR_CLASSES
#define ITERATOR_CLASSES
#include "compositepattern.h"
#include <string>
#include <stack>

using namespace std;
class Base;

class Iterator
{
	protected:
		Base* self_ptr;
		Base* current_ptr;
	public:
		Iterator(Base* ptr);
		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool is_done() = 0;
		virtual Base* current() = 0;
};
class BinaryIterator : public Iterator
{
	public:
		BinaryIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};

class UnaryIterator : public Iterator
{
	public:
		UnaryIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};
class NullIterator : public Iterator
{
	public:
		NullIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};
class PreOrderIterator : public Iterator
{
	protected:
		stack<Iterator*> iterators;
	public:
		PreOrderIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};
#endif

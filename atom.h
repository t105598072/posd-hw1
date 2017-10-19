#ifndef ATOM_H
#define ATOM_H
#include <iostream>
#include <string>
#include "term.h"
using namespace std;

class Term;
class Number;
class Variable;
class Atom : public Term{
public:
	Atom (string s);
 	Term *t;
	string value() const;
	string symbol()const;	

	void keySwitch();

	bool match(Term &);
	//bool match(Number n);
	//bool match(Variable *v);

	bool checkmatch(Variable *v);

private:
	int key = 0;
	string _symbol;
	string _value;
};

#endif



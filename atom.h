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
	string value() const;
	string symbol() const;

	bool match(Number n);
	bool match(Variable *v);

	bool checkmatch(Variable *v);

private:
	string _symbol;
	string _value;
};

#endif




#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
using std::string;

class Number;
class atom;

class Variable: public Term{
public:
 	Variable(string s);

	string value() const;
	string symbol() const;

	void getvalue(string symbol);
	
	bool match(Number* n);
	bool match(Atom* a);
	bool checkmatch(Number *n);
	bool checkmatch(Atom *a);

private:
	string _symbol;
	string _value;
};

#endif

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "term.h"
using std::string;

class Number;
class atom;

class Variable: public Term{
public:
 	Variable(string s);
	string _symbol;
	string value() const;
	string symbol() const;

	void getvalue(string symbol);

	int keySwitch();
	
	bool match(Term &) const;
	bool match(Number*);
	bool match(Atom);	
	bool match(Atom*);
	bool checkmatch(Number*);
	bool checkmatch(Atom*);

private:
	string _value;
	int key = 0;
};

#endif

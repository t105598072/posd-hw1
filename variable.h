#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
using std::string;

class Number;
class atom;

class Variable{
public:
  	string value();
	string const _symbol;

  	Variable(string s);
	void getvalue(string symbol);
	string match(Number* n);
	string match(Atom* a);
	string checkmatch(Number *n);
	string checkmatch(Atom *a);
private:
	string _value;
};

#endif

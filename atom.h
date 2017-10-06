#ifndef ATOM_H
#define ATOM_H
#include <iostream>
#include <string>

using namespace std;

class Number;
class Variable;

class Atom {
public:
	Atom (string s);
	string match(Number n);
	string match(Variable *v);
	string value();
	string symbol();
	string checkmatch(Variable *v);
private:
	string _symbol;
	string _value;
};

#endif

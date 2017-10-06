#ifndef NUNBER_H
#define NUMBER_H
#include <iostream>
#include <string>
#include <sstream>
#include "atom.h"
#include "variable.h"

using namespace std;

class Number{
public:
	string _symbolValue;

	Number(int n);
	//bool operator == (Number a) {return _symbol == a._symbol;}
	string match(Number a);
	string match(Atom a);
	string match(Variable v);

	string value(Variable v);
	string value();
	string symbol();
private:
	int _symbol;
};
#endif

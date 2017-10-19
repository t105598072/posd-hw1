#ifndef NUNBER_H
#define NUMBER_H
#include <iostream>
#include <string>
#include <sstream>
#include "atom.h"
#include "term.h"
#include "variable.h"

using namespace std;

class Number: public Term{
public:
	Number(double n);
	string _symbolValue; 

	bool match(Term &);
	bool match(Number a);
	bool match(Atom a);
	bool match(Variable v);

	string value(Variable v);
	string value()const;
	string symbol()const;

private:
	double n;
	string _symbol;
};
#endif

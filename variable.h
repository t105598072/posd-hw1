#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <typeinfo>
#include "atom.h"
#include "term.h"
using std::string;
using std::vector;
class Number;
class Atom;

class Variable: public Term{
public:
 	Variable(string s);
 	Term *t;
 	Term *t1;
	string _symbol;
	string value() const;
	string valueTerm();	
	string symbol() const;
//	string typeCheck(Term &);

	void getvalue(string symbol);
	void keySwitch();

	
	bool match(Term &);
	//bool match(Number*);
	//bool match(Atom);	
	//bool match(Atom*);
	bool checkmatch(Term &);
	bool checkmatch(Number*);
	bool checkmatch(Atom*);

private:
	string _value;
	string _valueTerm;
	int key = 0;
	vector<Term*> v;

};

#endif

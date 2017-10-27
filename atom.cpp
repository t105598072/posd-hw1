#include "atom.h"
#include "variable.h"
#include <typeinfo>
#include "term.h"
Atom::Atom(string s):_symbol(s){}

string Atom::symbol() const{ return _symbol;}
string Atom::value() const { return symbol();}

bool Atom::match(Term &term){
	return term.symbol() == _symbol;
}




#include "atom.h"
#include "number.h"
#include "variable.h"

Atom::Atom (string s):_symbol(s) {}
string Atom::value()const {return symbol();}
string Atom::symbol()const {return _symbol;}

bool Atom::match(Number n){return false;}
bool Atom::match(Variable* v){
	v->getvalue(_symbol);
	return true;
}
bool Atom::checkmatch(Variable *v){
	if(v->value() == _symbol)
		return true;
	else
		return false;
}

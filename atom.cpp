#include "atom.h"
#include "number.h"
#include "variable.h"

Atom::Atom (string s):_symbol(s) {}
// if Atom match Number must return false
string Atom::match(Number n){return "false";}
string Atom::match(Variable* v){
	v->getvalue(_symbol);
	return "true";
}
// 
string Atom::checkmatch(Variable *v){
	if(v->value() == _symbol)
		return "true";
	else
		return "false";
}

string Atom::value(){return symbol();}
string Atom::symbol(){return _symbol;}

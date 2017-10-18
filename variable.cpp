
#include "atom.h"
#include "number.h"
#include "variable.h"

Variable::Variable(string s):_symbol(s){}
string Variable::symbol() const{ return _symbol;}
string Variable::value() const { return _value;}
void Variable::getvalue(string symbol){ _value = symbol;}

bool Variable::match(Number* n){
	_value = n->value();
	return true;	
}
bool Variable::match(Atom* a){
	_value = a->value();
	return true;
}

bool Variable::checkmatch(Number *n){
	if(_value == n->value())
		return true;
	else
		return false;
}
bool Variable::checkmatch(Atom *a){
	if(_value == a->value())
		return true;
	else
		return false;
}
/*
bool match(Atom atom){
	bool ret = _assignable;
	if(_assignable){
		_value = atom._symbol ;
		_assignable = false;
	}

    return ret;
}
*/

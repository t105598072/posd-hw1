#include "atom.h"
#include "number.h"
#include "variable.h"

Variable::Variable(string s):_symbol(s){}
string Variable::symbol() const{ return _valueterm;}
string Variable::value() const { return symbol();}
string Variable::valueTerm(){ return _valueterm;}
void Variable::getvalue(string symbol){ _value = symbol;}

void Variable::keySwitch(){
	if(key==0)	key=1;
	else		key=0;
}

bool Variable::match(Term & term) {

	if(key == 0){
		t = &term;
		_valueterm = t->value();
		keySwitch();
		return true;
	}
	else {
		_valueterm = t->value();
		return t->value() == term.value();
	}

}
bool Variable::match(Variable & var){
	if(var.symbol() == _symbol)
		return true;

}

/*
bool Variable::match(Number* n){
	_value = n->value();
	return true;	
}
bool Variable::match(Atom a){
	_value = a.value();
	return true;
}
bool Variable::match(Atom* a){
	_value = a->value();
	return true;
}
*/
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

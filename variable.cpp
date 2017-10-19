#include "atom.h"
#include "number.h"
#include "variable.h"

Variable::Variable(string s):_symbol(s){
	_value = symbol();
}
string Variable::symbol() const{ return _value;}
string Variable::value() const { return symbol();}
string Variable::valueTerm(){ return _valueTerm;}
void Variable::getvalue(string symbol){ _value = symbol;}

void Variable::keySwitch(){
	if(key==0)
		key=1;
	else
		key=0;
}

bool Variable::match(Term & term) {
	if(&term !=NULL){
		// first
		if(key == 0){
			t = &term;
			_valueTerm = t->value();
			v.push_back(t);
			keySwitch();
			return true;
		}
		//
		else if(key==1 && t!=&term)  {
			_valueTerm = t->value();
			v.push_back(t);
			return t->value() == term.value();
		}
		else
			return t->value() == term.value();
	}
	else
		return t->value() == term.value();
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

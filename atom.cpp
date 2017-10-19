#include "atom.h"
#include "number.h"
#include "variable.h"

Atom::Atom (string s):_symbol(s) {}
string Atom::value()const {return symbol();}
string Atom::symbol()const {return _symbol;}

void Atom::keySwitch(){
	if(key==0)
		key=1;
	else
		key=0;
}
bool Atom::match(Term & term){
	if(&term !=NULL){
		if(key!=1){
			t = &term;
			this->keySwitch();
			return true; 
		}
		else{
			t->match(term);
			return false;
		}
	}
	else{
		return false;
	}
}

/*
bool Atom::match(Number n){return false;}
bool Atom::match(Variable* v){
	v->getvalue(_symbol);
	return true;
}
*/
bool Atom::checkmatch(Variable *v){
	if(v->value() == _symbol)
		return true;
	else
		return false;
}


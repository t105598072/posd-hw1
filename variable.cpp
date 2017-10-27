#include "atom.h"
#include "number.h"
#include "variable.h"
#include "list.h"

Variable::Variable(string s):_symbol(s){}
string Variable::symbol() const{ return _symbol;}
string Variable::value() const { return symbol();}

bool Variable::match(Term &term) {
	if(key == 0){
		t = &term;
		_valueterm = t->value();
		return true;
	}
	else {
		_valueterm = t->value();
		return t->value() == term.value();
	}
}
bool Variable::match(Variable &var){
	if(var.symbol() == _symbol)
		return true;
}
/*
bool Variable::match(List &list){
	if(_l != NULL){
		if(_l->symbol() == list.symbol())
			return true;
	}
	if(elements.find(_symbol) != string::nops){
		return false;
	}
_l = &list;
return _1->value() == lise.value();
}
*/
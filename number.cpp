#include "number.h"
#include "atom.h"
#include "variable.h"


Number::Number(int n):n(n){
	stringstream ss;
	ss << n;
	string s = ss.str();
	_symbol =  s;
}

string Number::symbol() const{ return _symbol;}
string Number::value() const { return symbol();}
string Number::value(Variable v){ return v.value();}

bool Number::match(Number a){
	if(symbol()==a.symbol()){
		_symbolValue = a.symbol();
		return true;
	}
	else
		return false;
}
bool Number::match(Atom a){return false;}
bool Number::match(Variable v){
	_symbolValue = value(value(v));	
	return true;
}

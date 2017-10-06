#include "number.h"
#include "atom.h"
#include "variable.h"


Number::Number(int n):_symbol(n){}

string Number::symbol(){
	stringstream ss;
	ss << _symbol;
	string s = ss.str();
	return s;
}

string Number::match(Number a){
	if(symbol()==a.symbol()){
		_symbolValue = a.symbol();
		return "true";
	}
	else
		return "false";
}
// if Number match Atom must return false
string Number::match(Atom a){return "false";}
// if Number match Variable must return true and get the value
string Number::match(Variable v){
	_symbolValue = value(value(v));	
	return "true";
}
string Number::value(){return symbol();}
string Number::value(Variable v){return v._symbol;}

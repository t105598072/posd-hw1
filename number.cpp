#include "number.h"


Number::Number(double n1){
	stringstream ss;
	ss << n1;
	string s = ss.str();
	_symbol =  s;
}

string Number::symbol() const{ return _symbol;}
string Number::value() const { return symbol();}

bool Number::match(Term &term){
	return term.symbol() == _symbol;
}
bool Number::match(List &list){
	return false;
}
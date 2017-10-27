#include "struct.h"

Struct::Struct(Atom name, std::vector<Term *> args):_name(name), _args(args){}

Term * Struct::args(int index) {return _args[index];}
Atom & Struct::name() {return _name;}
string Struct::symbol() const {
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->symbol()+", ";
    ret  += (*it)->symbol()+")";
    return ret;
}

string Struct::value() const {
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->value()+", ";
    ret  += (*it)->value()+")";
    return ret;
}

bool Struct::match(Term &term){
	Struct* ps = dynamic_cast<Struct*>(&term);
	if (ps){
		if(!_name.match(ps->_name))
			return false;
		if(_args.size()!=ps->_args.size())
			return false;
		for(int i=0;i<_args.size();i++){
			if(_args[i]->symbol()!=ps->_args[i]->symbol())
				return false;
		}
		return true;
	}
	return false;
}
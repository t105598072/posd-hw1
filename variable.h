#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <typeinfo>
#include "atom.h"
#include "term.h"
#include "list.h"
using std::string;
using std::vector;
class Number;
class Atom;

class Variable: public Term{
public:
  Variable(string s);
  Term *t;
  Term *t1;
  string value() const;
  string valueTerm(); 
  string symbol() const;
//  string typeCheck(Term &);
  bool match(Term &);
  bool match(Variable &);

private:
  string _symbol; 
  string _value;
  string _valueterm;
  int key = 0;
};

#endif
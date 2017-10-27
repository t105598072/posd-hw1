#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include <string>
#include <sstream>
using std::string;

class Atom : public Term{
public:
  Atom(string s);

  string value() const;
  string symbol() const;

  bool match(Term &term);

private:
  string _value;
  string _symbol;
};

#endif

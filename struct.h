#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include "list.h"
#include <vector>
#include <string>

using std::string;

class Struct: public Term {
public:
  Struct(Atom name, std::vector<Term *> args);

  Term * args(int index);

  Atom & name();
  string symbol() const;
  string value() const;
  bool match(Term &term);
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif

#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
using std::vector;
using namespace std;

class List : public Term {
public:
  string symbol() const;
  string value() const;
  bool match(Term & term);

public:  
  List ();
  List (vector<Term *> const & elements);
  Term * head() const;
  List * tail() const;
  bool match(List &);
private:
  vector<Term *> _elements;
  string _symbol;
};
#endif

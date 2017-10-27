#ifndef TERM_H
#define TERM_H

#include <string>
using namespace std;
class Struct;

class Term {
public:
	virtual string symbol() const = 0;
	virtual string value() const = 0;
	virtual bool match(Term &term) = 0;
};

#endif
#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <vector>
#include <sstream>
#include "term.h"
#include "variable.h"
using namespace std;

class Number : public Term{
public:
	Number(double n1);
	bool match(Term &term);
	bool match(List &list);

	string value() const;
	string symbol() const;
private:
	string _value;
	string _symbol; 	
	double n1;
};
#endif
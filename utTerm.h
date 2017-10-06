#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"

//test Number.value()
TEST (Number,ctor) {
	Number one(1);
	ASSERT_EQ("1", one.value());
}

//test Number.symbol()
TEST (Number, symbol) {
	Number one(1);
	ASSERT_EQ("1", one.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number n1(25);
	Number n2(25);
	ASSERT_EQ("true", n1.match(n2));	
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number n1(25);
	Number n2(0);
	ASSERT_EQ("false", n1.match(n2));	
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Number n1(25);
	Atom tom("tom");
	ASSERT_EQ("false", n1.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Number n1(25);
	Variable X("X");
	ASSERT_EQ("true", n1.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Atom tom("tom");
	Number n1(25);
	ASSERT_EQ("false", tom.match(n1));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	tom.match(&X);
	ASSERT_EQ("tom",X.value());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Variable X("X");
	tom.match(&X);
	ASSERT_EQ("true", tom.checkmatch(&X));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Atom jerry("jerry");
	Variable X("X");
	jerry.match(&X);
	ASSERT_EQ("false", tom.checkmatch(&X));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
 	Variable X("X");
	Number n1(5);
	X.match(&n1);
	ASSERT_EQ("5", X.value());
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
	Variable X("X");
	Number n1(25);
	Number n2(100);
	X.match(&n1);
	ASSERT_EQ("false", X.checkmatch(&n2));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
	Variable X("X");
	Atom tom("tom");
	Number n1(25);	
	X.match(&tom);
	ASSERT_EQ("false", X.checkmatch(&n1));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
	Variable X("X");
	Atom tom("tom");
	Number n1(25);	
	tom.match(&X);
	ASSERT_EQ("false", X.checkmatch(&n1));		
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
	Variable X("X");
	Atom tom1("tom");
	Atom tom2("tom");	
	X.match(&tom1);
	ASSERT_EQ("true", X.checkmatch(&tom2));
}
#endif

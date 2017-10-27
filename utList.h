#ifndef UTLIST_H
#define UTLIST_H

#include <vector>
#include <string>
using std::string;
#include "struct.h"
#include "list.h"
#include "variable.h"
#include "atom.h"
#include "number.h"


// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List l1;
  EXPECT_EQ("[]",l1.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number n1(496);
  Number n2(8128);
  vector<Term *> v1 = {&n1, &n2};
  List l1(v1);
  EXPECT_EQ("[496, 8128]",l1.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom a1("terence_tao");
  Atom a2("alan_mathison_turing");
  vector<Term *> v1 = {&a1, &a2};
  List l1(v1);
  EXPECT_EQ("[terence_tao, alan_mathison_turing]",l1.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable var1("X"); 
  Variable var2("Y");
  vector<Term *> v1 = {&var1, &var2};
  List l1(v1);
  EXPECT_EQ("[X, Y]",l1.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Atom a1("tom");
  Number n1(496);
  Variable var1("X");
  Atom a2("terence_tao");
  vector<Term *> v1 = {&n1, &var1, &a2};
  List l1(v1);
  EXPECT_FALSE(a1.match(l1));  
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Number n1(8128);
  Number n2(496);
  Variable var1("X");
  Atom a1("terence_tao");
  vector<Term *> v1 = {&n2, &var1, &a1};
  List l1(v1);
  EXPECT_FALSE(n1.match(l1));  
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Atom a1("s");
  Number n1(496);
  Variable var1("X");
  Atom a2("terence_tao");
  vector<Term *> v1 = {&n1, &var1, &a1};
  List l1(v1);
  Struct s1(a1,v1);
  EXPECT_FALSE(s1.match(l1));  
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Variable var1("Y");
  Number n1(496);
  Variable var2("X");
  Atom a1("terence_tao");
  vector<Term *> v1 = {&n1, &var2, &a1};
  List l1(v1);
  EXPECT_TRUE(var2.match(l1));
  EXPECT_EQ("[496, X, terence_tao]", l1.symbol());

}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Variable var1("X");
  Number n1(496);
  Atom a1("terence_tao");
  vector<Term *> v1 = {&n1, &var1, &a1};
  List l1(v1);
  EXPECT_TRUE(var1.match(l1));  
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Atom a1("terence_tao");
  Number n1(496);
  Variable var1("X");
  vector<Term *> v1 = {&n1, &var1, &a1};
  vector<Term *> v2 = {&n1, &var1, &a1};
  List l1(v1);
  List l2(v2);
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {

}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {

}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {

}

// Example: 
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {

}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {

}
 
// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {

}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {

}




#endif

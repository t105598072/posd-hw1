all: hw4

hw4: mainList.o number.o atom.o variable.o list.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainList.o number.o atom.o variable.o list.o struct.o -lgtest
else
	g++ -o hw4 mainList.o number.o atom.o variable.o list.o struct.o -lgtest -lpthread
endif
	
mainList.o: mainList.cpp utTerm.h utVariable.h utList.h number.h atom.h variable.h list.h struct.o
	g++ -std=gnu++0x -c mainList.cpp 
number.o: number.cpp number.h atom.h variable.h
	g++ -std=gnu++0x -c number.cpp
atom.o: atom.cpp atom.h number.h variable.h
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.cpp variable.h number.h atom.h list.h
	g++ -std=gnu++0x -c variable.cpp
struct.o: struct.cpp struct.h atom.h number.h list.h
	g++ -std=gnu++0x -c struct.cpp
list.o: list.cpp list.h term.h variable.h
	g++ -std=gnu++0x -c list.cpp


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe hw4
else
	rm -f *.o hw4
endif

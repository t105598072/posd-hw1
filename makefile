all: hw2

hw2: mainTerm.o number.o atom.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o number.o atom.o variable.o -lgtest
else
	g++ -o hw2 mainTerm.o number.o atom.o variable.o -lgtest -lpthread
endif
	
mainTerm.o: mainTerm.cpp utTerm.h number.h atom.h
	g++ -std=gnu++0x -c mainTerm.cpp
number.o: number.cpp number.h atom.h variable.h
	g++ -std=gnu++0x -c number.cpp
atom.o: atom.cpp atom.h number.h variable.h
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.cpp variable.h number.h atom.h
	g++ -std=gnu++0x -c variable.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe hw2
else
	rm -f *.o hw2
endif

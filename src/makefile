all: test

calc.tab.cpp calc.tab.hpp:	test.y
	bison -d test.y

lex.yy.cpp: test.l test.tab.h
	flex test.l

test: lex.yy.cpp test.tab.cpp test.tab.hpp
	gcc -o test test.tab.cpp lex.yy.cpp

clean:
	rm test test.tab.cpp lex.yy.cpp test.tab.hpp
CPPFLAGS += -W -Wall -g 

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function

all : test

lexer2.yy.cpp : lexer2.flex
	flex -o lexer2.yy.cpp  lexer2.flex

test : lexer2.yy.o test_main.o
	g++ $(CPPFLAGS) -o test  lexer2.yy.o test_main.o

clean :
	-rm -f test test.exe
	-rm -f *.yy.cpp
	-rm -f *.o

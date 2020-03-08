CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/print_canonical bin/eval_expr

src/cparser.tab.cpp src/cparser.tab.hpp : src/cparser.y
	bison -v -d src/cparser.y -o src/cparser.tab.cpp

src/clexer.yy.cpp : src/clexer.flex src/cparser.tab.hpp
	flex -o src/clexer.yy.cpp  src/clexer.flex

bin/pretty_print : src/pretty_print.o src/cparser.tab.o src/clexer.yy.o src/cparser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/pretty_print $^

bin/eval_expr : src/eval_expr.o src/maths_parser.tab.o src/maths_lexer.yy.o src/maths_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/eval_expr $^


clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp

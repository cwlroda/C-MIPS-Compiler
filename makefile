CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter -Wno-reorder -w
CPPFLAGS += -I include

src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp -Wno-other -Wconflicts-sr

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp src/lexer.flex

bin/c_compiler : src/c_compiler.o src/parser.tab.o src/lexer.yy.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^

clean :
	rm src/*.o
	rm bin/*
	rm src/*.tab.hpp
	rm src/*.tab.cpp
	rm src/*.yy.cpp
	rm src/*.output
	rm tmp/formative/*

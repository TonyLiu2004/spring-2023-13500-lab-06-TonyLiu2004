OBJECTS = caesar.o vigenere.o decrypt.o
main: main.o funcs.o $(OBJECTS)
	g++ -o main main.o funcs.o $(OBJECTS)

tests: tests.o funcs.o $(OBJECTS)
	g++ -o tests tests.o funcs.o $(OBJECTS)

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o


funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

tests.o: tests.cpp doctest.h funcs.h

test-ascii.o: test-ascii.cpp

caesar.o: caesar.cpp caesar.h funcs.h

vigenere.o: vigenere.cpp vigenere.h funcs.h

decrypt.o: decrypt.cpp decrypt.h funcs.h

clean:
	rm -f main.o funcs.o tests.o $(OBJECTS) test-ascii.o

# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors 
GCC = gcc
TARGET1=identifier.out

all: clean test run valgrind

run:
	$(GCC) $(GCCFLAGS) -IIdentifier/src Identifier/src/identifier.c main.c -o identifier.out

cov: identifier.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o gcov identifier.c

clean:
	rm -rf *.o cov* *.dSYM *.gcda *.gcno *.gcov $(TARGET1)

valgrind:
	- valgrind --leak-check=full ./$(TARGET1) -v <<< "aada\n"

test:
	bash teste.sh

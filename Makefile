# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = test
GCC = gcc

all: $(ALL)

identifier:
	$(GCC) $(GCCFLAGS) -o Identifier/identifier.c identifier

cov: identifier.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o gcov identifier.c

clean:
	rm -rf *.o cov* *.dSYM *.gcda *.gcno *.gcov
	cd Identifier/
	rm -fr *.o cov* *.dSYM *.gcda *.gcno *.gcov

test:
	bash teste.sh

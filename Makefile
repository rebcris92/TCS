# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier
GCC = gcc

all: $(ALL)

identifier:
	cd Identifier
	make

cov: identifier.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o gcov identifier.c

clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

test: all
	bash test

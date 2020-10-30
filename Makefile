# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=Unity
IDENTIFIER_ROOT=Identifier

CFLAGS=-std=c99
CFLAGS += -g 
CFLAGS += -Wfatal-errors 
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
sCFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -fprofile-arcs
CFLAGS += -ftest-coverage
#CFLAGS += -fsanitize=address

TARGET_BASE1=all_tests
TARGET_BASE2=identifier
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
TARGET2 = $(TARGET_BASE2)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  $(IDENTIFIER_ROOT)/src/identifier.c \
  $(IDENTIFIER_ROOT)/test/TestIdentifier.c \
  $(IDENTIFIER_ROOT)/test/test_runners/TestIdentifier_Runner.c \
  $(IDENTIFIER_ROOT)/test/test_runners/all_tests.c
INC_DIRS=-I$(IDENTIFIER_ROOT)/src -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=

all: clean cppcheck valgrind cov santizer identifier

compile:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

run:
	- ./$(TARGET1) -v

santizer: 
	$(C_COMPILER) $(CFLAGS) -fsanitize=address $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1) -v

clean:
	rm -fr *.o cov* *.dSYM *.gcda *.gcno *.gcov $(TARGET1) $(TARGET2)

cov: 
	- gcov -b identifier.c

cppcheck:
	- cppcheck --error-exitcode=1 $(IDENTIFIER_ROOT)/src/identifier.c

valgrind:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- valgrind --leak-check=full --error-exitcode=1 ./$(TARGET1) -q

identifier:
	$(C_COMPILER) $(CFLAGS) -I$(IDENTIFIER_ROOT)/src $(IDENTIFIER_ROOT)/src/identifier.c main.c -o $(TARGET2)

ci: CFLAGS += -Werror
ci: compile

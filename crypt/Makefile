# Author: Rafael Garibotti

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

##### Compiler options #####

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=..

CFLAGS=-c
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

SRC_FILES1=$(UNITY_ROOT)/src/*
SYMBOLS=

CC = gcc
#CFLAGS = -c -Wall -fprofile-arcs -ftest-coverage -fsanitize=address -static-libasan

##### Project specific libraries #####
SRC_FILES =  $(SRC_FILES1)
SRC_FILES += $(wildcard src/*.c)
TEST_FILES += $(wildcard test/*.c)


##### General commands #####
all: $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $^
	$(CC) *.o -o app
	rm -rf *.o

#all: app

#app: main.o aes.o camellia.o seed.o
#	$(CC) main.o aes.o camellia.o seed.o -o app
#	rm -rf *.o

#main.o: test/main.c
#	$(CC) $(CFLAGS) $^

#aes.o: src/aes.c
#	$(CC) $(CFLAGS) $^
#camellia.o: src/camellia.c
#	$(CC) $(CFLAGS) $^

#seed.o: src/seed.c
#	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o app

cov:

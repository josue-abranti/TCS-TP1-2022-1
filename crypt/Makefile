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

CFLAGS = -Wall
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
CFLAGS += -fprofile-arcs
CFLAGS += -ftest-coverage

TARGET_BASE=tests
TARGET = $(TARGET_BASE)$(TARGET_EXTENSION)
SRC_FILES=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/aes.c \
  src/camellia.c \
  src/crypt.c \
  src/seed.c \
  test/TestCrypt.c \
  test/test_runners/TestCrypt_Runner.c \
  test/test_runners/all_tests.c
DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src

compile:
	$(C_COMPILER) $(CFLAGS) $(DIRS) $(SRC_FILES) -o $(TARGET)

sanitizer:
	$(C_COMPILER) -g -Wall -Wfatal-errors -fsanitize=address $(DIRS) $(SRC_FILES) -o $(TARGET)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./all_tests.out 

gcov:
gcc --version
find  /usr/lib/gcc -name libgcov.a
#gcov -b aes.c
#gcov -b camellia.c
#gcov -b crypt.c
#gcov -b seed.c

run:
	- ./$(TARGET) -v

clean:
	rm -rf *.o app

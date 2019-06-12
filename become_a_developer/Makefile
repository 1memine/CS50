#
# Makefile
#
# Become a developer test
#
# Taken from cs50 2015 pset5 dictribution code
# http://cdn.cs50.net/2015/fall/psets/5/pset5/pset5/
# Makefile
#


# Compiler
CC = clang

# Flags for compiler
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror

# Executable
EXE = main

# Header files
HDRS = functions.h

LIBS =

# Sources
SRCS = main.c functions.c

OBJS = $(SRCS:.c=.o)

# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# Dependencies
$(OBJS): $(HDRS) Makefile

clean:
	rm -f core $(EXE) *.o

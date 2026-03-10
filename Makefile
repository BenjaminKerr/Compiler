##**************************************
## Makefile
##
## Build routine for lang compiler
##
## Author: Phil Howard
## phil.howard@oit.edu
##
## Modified by: Benjamin Kerr
##
## Date: Jan. 18, 2015
##

# Compiler flags:
#   -Wall   enable all warnings
#   -g      include debug symbols
#   -c      compile only (no linking)
#   -O0     disable optimization (for easier debugging)
#   -std=c++11  use C++11 standard
COPTS=-Wall -g -c -O0 -std=c++11

# Object files required to link the final compiler binary
OBJS=main.o \
     emit.o \
     langlex.o \
     langparse.o \
     cSymbolTable.o \
     cVisitor.o \
     cSemantics.o \
     cComputeSize.o

all: lang

# Remove all generated files and build artifacts
clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f langparse.c
	rm -f langparse.h
	rm -f lang
	rm -f out.xml
	rm -f out2.xml

# Default rule: compile any .cpp to .o
.cpp.o:
	g++ $(COPTS) $< -o $@

# Default rule: compile any .c to .o
.c.o:
	g++ $(COPTS) $< -o $@

# main.cpp depends on the bison-generated header for token definitions
main.o: main.cpp langparse.c
	g++ $(COPTS) main.cpp -o $@

# Suppress sign-compare warnings from flex-generated code
langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare $< -o $@

# Generate lexer source from flex specification
langlex.c: lang.l langparse.c
	flex -o langlex.c lang.l

# Generate parser source and token header from bison grammar
langparse.c: lang.y
	bison --defines=langparse.h lang.y -o langparse.c

# Link all object files into the final compiler binary
lang: $(OBJS)
	g++ $(OBJS) -o lang

.PHONY: all clean
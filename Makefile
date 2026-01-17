##############################################
# Makefile for CST320 labs
#
# Nov. 24, 2015
#

COPTS=-Wall -g -c  -O0
OBJS=main.o \
	 langlex.o \
	 cSymbolTable.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f *.o
	rm -f langlex.c
	rm -f lang
	rm -f out.xml
	rm -f out2.xml

.c.o:
	g++ $(COPTS) $? -o $@

.cpp.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langlex.c 
	g++ $(COPTS) main.cpp -o main.o

cSymbolTable.o: cSymbolTable.cpp
	g++ $(COPTS) cSymbolTable.cpp -o cSymbolTable.o

langlex.c: lang.l
	flex -o langlex.c lang.l

langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare $? -o $@
lang: $(OBJS)
	g++ $(OBJS) -o lang


# Makefile for CST 320 Lab 3
# Author: Benjamin Kerr

CXX = g++
CXXFLAGS = -g -Wall -std=c++11
LEX = flex

OBJS = main.o parse.o utils.o lex.yy.o

calc: $(OBJS)
	$(CXX) $(CXXFLAGS) -o calc $(OBJS)

main.o: main.cpp lex.h parse.h
	$(CXX) $(CXXFLAGS) -c main.cpp

parse.o: parse.cpp parse.h lex.h utils.h
	$(CXX) $(CXXFLAGS) -c parse.cpp

utils.o: utils.cpp utils.h lex.h
	$(CXX) $(CXXFLAGS) -c utils.cpp

lex.yy.o: lex.yy.c lex.h
	$(CXX) $(CXXFLAGS) -c lex.yy.c

lex.yy.c: calc.l
	$(LEX) -o lex.yy.c calc.l

clean:
	rm -f calc $(OBJS) lex.yy.c

.PHONY: clean
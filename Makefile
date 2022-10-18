CC=g++
CFLAGS=-Wall
JC=javac
JFLAGS=
JAR=jar
JARFLAGS=cf

all: mysort mysort.jar

mysort: MySort.cpp
	$(CC) $(CFLAGS) -o $@ $<

mysort.jar: MySort.class
	$(JAR) $(JARFLAGS) $@ $<

MySort.class: MySort.java
	$(JC) $(JFLAGS) $<

clean:
	rm -rf mysort mysort.jar MySort.class

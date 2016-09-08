SharkMainSwift: Shark.o SharkWrapper.h SharkWrapper.o
	swiftc -import-objc-header SharkWrapper.h SharkMain.swift SharkWrapper.o Shark.o -o bin/SharkMainSwift

SharkMain: Shark.o SharkWrapper.o SharkMain.o
	g++ SharkMain.o SharkWrapper.o Shark.o -o bin/SharkMain

Shark.o: Shark.h Shark.cc
	g++ -c Shark.cc -o Shark.o

SharkWrapper.o: SharkWrapper.h SharkWrapper.cc
	g++ -c SharkWrapper.cc -o SharkWrapper.o

SharkMain.o: SharkMain.c
	gcc -c SharkMain.c -o SharkMain.o

clean:
	rm *.o bin/*

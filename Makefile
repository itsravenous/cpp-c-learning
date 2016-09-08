SharkMainSwift: Shark.o SharkWrapper.h SharkWrapper.o
	swiftc -import-objc-header SharkWrapper.h SharkMain.swift SharkWrapper.o Shark.o -o bin/SharkMainSwift

SharkMain: Shark.o SharkWrapper.o SharkMain.o
	g++ SharkMain.o SharkWrapper.o Shark.o -o bin/SharkMain

Shark.o: Shark.h Shark.cc
	g++ -c -fPIC Shark.cc -o Shark.o

SharkWrapper.o: SharkWrapper.h SharkWrapper.cc
	g++ -c -fPIC SharkWrapper.cc -o SharkWrapper.o

SharkMain.o: SharkMain.c
	gcc -c -fPIC SharkMain.c -o SharkMain.o

SharkWrapper.so: Shark.o SharkWrapper.o
	gcc -shared -Wl,-soname,libSharkWrapper.so -o libSharkWrapper.so SharkWrapper.o Shark.o

SharkMainShared: SharkWrapper.so
	gcc -L`pwd` -Wall -o bin/SharkMainShared SharkMain.c -lSharkWrapper -lstdc++
	@echo "tip: remember to set LD_LIBRARY_PATH to the current folder when running executable (e.g. LD_LIBRARY_PATH=`pwd` bin/SharkMainShared)"

clean:
	rm *.o *.so bin/*

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SHAREDLIBPATH = /usr/lib
endif
ifeq ($(UNAME_S),Darwin)
	SHAREDLIBPATH = /usr/local/lib
endif

all: bin/main bin/maincc

affine.o: incl/affine.h src/affine.cpp
	g++ -c -fPIC incl/affine.h src/affine.cpp

compare.o: incl/compare.hpp src/compare.cpp
	g++ -c -fPIC incl/compare.hpp src/compare.cpp

element.o: incl/element.hpp src/element.cpp
	g++ -c -fPIC incl/element.hpp src/element.cpp

fingerprint.o: incl/fingerprint.hpp src/fingerprint.cpp
	g++ -c -fPIC incl/fingerprint.hpp src/fingerprint.cpp

i3s.o: i3s.h i3s.cpp
	g++ -c -fPIC i3s.cpp -o i3s.o

lib/libi3s.so: affine.o compare.o element.o fingerprint.o i3s.o
	mkdir -p lib
	gcc -shared -Wl,-soname,libi3s.so -o lib/libi3s.so i3s.o fingerprint.o element.o compare.o affine.o

bin/main: main.c lib/libi3s.so
	mkdir -p bin
	gcc -L`pwd`/lib -Wall -o bin/main main.c -li3s -lstdc++

bin/maincc: main.cpp lib/libi3s.so
	mkdir -p bin
	gcc -L`pwd`/lib -Wall -o bin/maincc main.cpp -li3s -lstdc++

install: lib/libi3s.so
	cp lib/libi3s.so $(SHAREDLIBPATH)

clean:
	rm *.o lib/*.so bin/*

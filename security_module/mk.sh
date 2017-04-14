#!/bin/bash
g++ -Wall -g -fPIC -c cat.cpp
g++ -shared -Wl,-soname,libcat.so.1 -o libcat.so.1 cat.o
g++ -Wall -g -c main.cpp
g++ -Wall -Wl,-rpath,. -o main main.o libcat.so.1
./main

#!/bin/bash
g++ -Wall -g -fPIC -c ssapi.cpp
g++ -shared -Wl,-soname,libssapi.so -o libssapi.so ssapi.o
g++ -Wall -g -c main.cpp
g++ -Wall -Wl,-rpath,. -o main main.o libssapi.so
./main

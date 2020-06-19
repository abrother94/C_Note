#!/bin/bash
rm *.o *.so
g++  -fPIC -c f1.c
g++  -fPIC -c f2.c
g++  -shared f1.o -o libab.so
sudo cp ./libab.so /lib/x86_64-linux-gnu/
g++ -std=c++11 -shared f2.o -o libmyc.so
sudo cp ./libmyc.so /lib/x86_64-linux-gnu/
g++ -o m m.c  -lmyc -L/lib/x86_64-linux-gnu/


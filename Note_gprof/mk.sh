#!/bin/bash

# https://github.com/jrfonseca/gprof2dot
# sudo apt-get install python3 graphviz
# sudo apt-get install python-pip 
# sudo pip install gprof2dot

rm_list=("test" "G" "output.png" "G.png" "gmon.out" "report.txt")
rm_list_c=${#rm_list[@]}
#echo "${rm_list_c}"

if [ "$1" = "C" ];then
    for i in "${rm_list[@]}"
    do
	`rm "$i"`
    done
else
    gcc -g -pg -o test test.c  
    g++ -g -pg -o G G.cpp 
    ./test
    ./G
    #    gprof test gmon.out > report.txt
    gprof test | gprof2dot | dot -Tpng -o output.png
    gprof G | gprof2dot | dot -Tpng -o G.png
fi

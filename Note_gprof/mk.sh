# https://github.com/jrfonseca/gprof2dot
# apt-get install python3 graphviz
# 
# pip install gprof2dot

gcc -g -pg -o test tset.c  
./test
gprof test gmon.out > report.txt

#//or 

gprof test | gprof2dot | dot -Tpng -o output.png


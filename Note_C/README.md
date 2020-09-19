# C_Note

fun_p_a.c          
: Example of function pointer array using MACRO to define. 

mutex_wait.c       
: Example of using mutex to protect critical section between two pthread.

sem_wait.c         
: Example of using semaphore to protect critical section between two pthread.  

sem_wait_process.c         
: Example of using semaphore to protect critical section between two Process.   

Seldom use mutex to protect C.S between process.

* create expand macro source
gcc -std=gnu++11 -E me_c.cpp  -o me_c.i -I../include -I../open_source/json-cxx/include -I../open_source/jsoncpp-1.7.2.no-abi/include

* pointer to poinetr
![Screenshot](pointer_to_pointer.png) 

* array concept
https://blog.danielchen.cc/2020/05/30/C-Array-Function-Parameter/?fbclid=IwAR14ouFITGf4lA4rmKlBi5RvMDwCvmdauyiyHS_PlbNcvyQ9c-VQ3BJsg4w

* Pass function pointer as paramenters

#include <stdio.h>

    int (* fB)(int (*f)(int aa,int bb), int c);

    int A(int a, int b)
    {
        return a + b;
    }

    int fBB(int (* fA)(int a, int b), int cc)
    {
        return 1 + cc + fA(3,4);
    }

    int  main()
    {
        printf("[%d]",fBB(A,1));
        return 1;
    }

    #gcc -o a a.c

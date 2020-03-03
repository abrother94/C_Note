#include <stdio.h>

void fun_acc_5812()
{
    printf("fun1\r\n");
}

void fun_acc_7712()
{
    printf("fun2\r\n");
}

void fun_acc_5916()
{
    printf("fun3\r\n");
}


#define ACC_DLIST_ENTRY(acc_dtype) extern void fun_acc ## _ ## acc_dtype();

#include "fun_p_a.h"

#define ACC_DLIST_ENTRY(acc_dtype) fun_acc ## _ ## acc_dtype,

static void (*funcNum_ptr[])() = 
{
    #include "fun_p_a.h"
};

void main()
{
    funcNum_ptr[0]();
    funcNum_ptr[1]();
    funcNum_ptr[2]();
    return ;
}

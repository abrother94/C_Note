#include <stdio.h>
extern char __executable_start[];
extern char etext[], _etext[], __etext[];
extern char edata[], _edata[];
extern char end[], _end[];

static int var = 1;

int main()
{
    static int var2=1;
    printf("__executable_start[0x%X]\r\n", __executable_start);
    printf("etext[0x%X] _etext[0x%X] __etext[0x%X]\r\n", etext, _etext, __etext);
    printf("edata[0x%X] _edata[0x%X] \r\n", edata, _edata);
    printf("end[0x%X] _end[0x%X] \r\n", end, _end);

    while(1)
        usleep(1000);

    return 0;
}

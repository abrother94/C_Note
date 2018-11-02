#include <stdio.h>
static int s_igv = 1;
static int s_igvz = 0;
static int s_ignv;

void test(int b)
{
    int a = 0;
    printf("a[%d]", a);
    printf("b[%d]", b);
    printf("7788");
}

int main()
{
    static int s_ilv = 2;
    static int s_ilvz = 0;
    static int s_ilnv;

    int lv = 3;
    int lvz = 0;
    int lnv;

    test(lv);

    return 1;
}

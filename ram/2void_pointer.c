#include <stdio.h>
void main()
{
    int i;
    i=10;
    int * p = &i;
    void* p2 = &i; /* what exactly is the size of void?? */
    printf("val of i > %d\n", i);
    printf("addr of i > %x\n", &i);
    printf("val of p pointing to > %d\n", *p);
    printf("val of p2 pointing to > %d\n", *(int*)p2);
}

#include <stdio.h>
void main()
{
int i;
i=10;
void* p = &i;
void *p2 = p + 1; /* what exactly is the size of void?? */
printf("val of i > %d\n", i);
printf("addr of i > %d\n", &i);
printf("val of p > %d\n", p);
printf("val of p2 > %d\n", p2);

}

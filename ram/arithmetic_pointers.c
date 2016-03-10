#include <stdio.h>
int main(){

int i = 10;
int p = &i;
/*float j = 200.0;
int q = &j;
*/

printf("val of i is %d\n",i);
printf("addr of i is %d\n",&i);
printf("val of p is %d\n",p);
printf("addr of p is %d\n",&p);
/*printf("indirect printing of a is %d\n", int(*p));*/
/*printf(*p);*/
return 0;
}

#include <stdio.h>
int main(){
	int i, *p;
	i=10;
	p=&i;
	printf("i is %d\n", i);
	printf("i address is %p\n", &i);
	printf("p is %p\n", p);
	printf("p address is %p\n", &p);
	return 0;
}

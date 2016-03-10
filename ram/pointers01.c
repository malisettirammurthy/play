#include <stdio.h>
int main(){
	int i, *p;
	i=10;
	p=&i;
	printf("i is %d\n", i);
	printf("i address is %d\n", &i);
	printf("p is %d\n", p);
	printf("p address is %d\n", &p);
	return 0;
}

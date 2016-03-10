#include <stdio.h>

struct node{
    int x;
    struct node *next;
};

int main(){
    struct node *p1;
    p1 = (struct node *) malloc( sizeof(struct node) );
    p1->next = 0;
    p1->x=2;
    printf("p1->x is %d\n", p1->x);
    printf("p1->next is %d\n", p1->next);
    printf("addr is %d\n", p1);
    printf("addr of p is %d\n", &p1);
    return 0;
}


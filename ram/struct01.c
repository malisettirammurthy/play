#include <stdio.h>
struct nnn {
    int a;
    float b;
    char c;
} NODE;

int main(){
    struct  nnn n1;
    printf("size - %d\n", sizeof(n1));
    printf("size - %d\n", malloc(sizeof(n1)));

    return 0;
}

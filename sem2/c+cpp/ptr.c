#include <stdio.h>
int main(){
    int x=10;
    int *p;
    //p=&x;
    //printf("%d",x);
    //printf("\n");
    printf("%p", (void*)&x);

    return 0;
}
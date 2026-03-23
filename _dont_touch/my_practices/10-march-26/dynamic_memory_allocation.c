#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 5;
    int *arr = malloc(n * sizeof(int));

    printf("%d", sizeof(arr));

    return 0;
}
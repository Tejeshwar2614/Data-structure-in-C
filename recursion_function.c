#include<stdio.h>
#include<stdlib.h>


int fun(int n){
    if(n==1){
        return 1;
    }
    return fun(n);
}
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d,&n");
    int t1 = fun(n);
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //int c=0;
    for(int i=m;i>=n;i--){
        int f=i;
        int r = i;
        while(f!=1){
            int t=0;
            while(f>0){
                t = t+((f%10)*(f%10));
                f/=10;
            }
            if(r==t){
                break;
            }
            f = t;
        }
        if(f==1){
            printf("%d ",r);
        }
    }
}
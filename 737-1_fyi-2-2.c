#include<stdio.h>

int main()
{
    int x,n, sum=0; 
    scanf("%d", &n);
     for (int i=1;i<=n;++i)
     {
        scanf("%d", &x);
        sum +=(i%2)*x*x;
     }
        printf("%d\n", sum);
        return 0;
} 


#include <stdio.h>

int fact(int n )
{
    if (n == 0) 
    return 1 ;
    // int factorial  ;
    return n * fact(n-1);
}
int main()
{
    int n , f ;
    printf("\nKiska factorial nikalna hai : ");
    scanf("%d",&n);

    f = fact(n);

    printf("Factorial of %d is %d", n, f);
    return 0 ;
}
#include <stdio.h>
int main()
{
    int i , j , c ;
    int a[5];

    printf("Enter elememts in array\n");
    for(i=0 ; i<5 ; i++) {
        scanf("%d",&a[i]);
    }
    for(i=0 ; i<4 ; i++){
        for(j=0 ; j<(5-i)-1 ; j++){
            if(a[j] > a[j+1]) {
                c = a[j];
                a[j] = a[j+1];
                a[j+1] = c ;
            }
        }
    }
    for (i=0 ; i<5 ; i++) {
        printf("%d ",a[i]);
    }
    return 0 ;
}
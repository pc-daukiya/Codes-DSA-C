#include <stdio.h>
int main()
{
    int arr[12] , i , j ;
    int l=0 , h=11 , m ;
    int data ;

    printf("Enter 12 numbers in array : ");
    for(i=0 ; i<12 ; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter data : ");
    scanf("%d",&data);

    while(l<=h) {
        m=(l+h)/2;
        if(arr[m]==data) {
            printf("\n%d found at %d index " , data , m );
            break ;
        }
        else if(data>arr[m]) {
            l=m+1 ;
        }
        else {
            h=m-1 ; 
        }
    }
    if(l>h) {
        printf("\n%d not found in array " , data);
    }
    return 0 ;
}
// WAP to found data in array and print data with index number 
#include <stdio.h>
int main()
{
    int arr[8] , data , i , j , flag=0 ;

    printf("Enter 8 numbers in array : ");
    for(i=0 ; i<8 ; i++) {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter Value to be searched : ");
    scanf ("%d",&data);

    for(i=0 ; i<8 ; i++) {
        if(arr[i]==data) {
            printf("\n%d found at %d index ", data , i);
            flag=1 ;
        }
    }
    // if(flag==0) 
    if(!flag) {
        printf("\n%d not found", data) ;
    }
    return 0 ;
}
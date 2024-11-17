#include<stdio.h>
int main()
{
    int arr[6]={10,20,30,40,50,60};
    int i , pos , data ;

    printf("Enter position(0:5) : ");
    scanf("%d",&pos);

    pos = pos%5 ;

    printf("Enter data : ");
    scanf ("%d",&data);

    for(i=5 ; i>pos ; i-- ) {
        arr[i] = arr[i-1];
    }
    arr[pos] = data ;
    printf("\nAfter inserting %d at %d index array is " , data , pos);

    for(i=0; i<6 ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("\nDeletion in array");

    for (i=pos ; i<6 ; i++) {
        arr[i] = arr[i+1] ;
    }
    arr[i] = 0 ;

    printf("\nAfter deleting value from %d index array is ", pos);

    for(i=0 ; i<5 ; i++) {
        printf("%d " , arr[i]);
    }

    return 0 ;
}
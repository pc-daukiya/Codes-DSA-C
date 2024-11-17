#include <stdio.h>
int main()
{
    int i , j ;
    int A[4][4] , B[4][4] , C[4][4] ;

    //Initialization
    printf("Enter value in first matrix of 4x4\n");
    for(i=0 ; i<4 ; i++) {
        for(j=0 ; j<4 ; j++) {
            scanf ("%d",&A[i][j]);
        }
        // printf("\n");
    }
    //Traverse
    printf("\nMatrix of 4x4 is \n");
    for(i=0 ; i<4 ; i++) {
        for(j=0 ; j<4 ; j++) {
            printf ("%d ",A[i][j]);
        }
        printf("\n");
    }
    //Initialization second Matrix 
    printf("\nEnter value second matrix of 4x4\n");
    for(i=0 ; i<4 ; i++) {
        for(j=0 ; j<4 ; j++) {
            scanf ("%d",&B[i][j]);
        }
        // printf("\n");
    }
    //Traverse 
    printf("\nMatrix of 4x4 is \n");
    for(i=0 ; i<4 ; i++) {
        for(j=0 ; j<4 ; j++) {
            printf ("%d ",B[i][j]);
        }
        printf("\n");
    }
    // printf("\nSum of two Matrix is\n");
    // for(i=0 ; i<4 ; i++) {
    //     for(j=0 ; j<4 ; j++) {
    //         C[i][j] = A[i][j] + B[i][j]; 
    //     }
    // }
    // printf("\nThird Matrix is\n");
    // for(i=0 ; i<4 ; i++) {
    //     for(j=0 ; j<4 ; j++) {
    //         printf ("%d ",C[i][j]);
    //     }
    // }
    for(i=0 ; i<4 ; i++) {
        for(j=0 ; j<4 ; j++) {
            for ( int k=0 ; k<4 ; k++) {
                C[i][j] += A[i][k]*B[k][i] ;
            }
        }
        printf("\n");
    }
    printf ("\nMultiplication of two matrix is \n");
    for(i=0 ; i<4 ; i++) {
        for (j=0 ; j<4 ; j++) {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    return 0 ;
}
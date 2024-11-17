#include <stdio.h>
int main()
{
    // 1st matrix order

    int m ;
    printf ("Enter num of rows of 1st matrix : ");
    scanf ("%d",&m);
    int n ;
    printf ("Enter num of columns of 1st matrix : ");
    scanf ("%d",&n);

    int a[m][n];
    // input the first matrix
    printf ("\nEnter the elements of first matrix");
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            scanf ("%d",&a[i][j]);
        }
    }
   
    //2nd matrix order 
    int p ;
    printf ("Enter num of rows of 2nd matrix : ");
    scanf ("%d",&p);
    int q ;
    printf ("Enter num of rows of 2nd matrix : ");
    scanf ("%d",&q);

    int b[p][q];
    // input the second matrix
    printf ("\nEnter the elements of second matrix");
    for (int i=0 ; i<p ; i++) {
        for (int j=0 ; j<q ; j++) {
            scanf ("%d",&b[i][j]);
        }
    }

    //Check 
    if (n!=p) {
        printf ("The multiplication is cannot exist");
    }
    else {
        // multiplication 
        int res[m][q] ;
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<q ; j++) {
                res[i][j] = 0 ;
                // i row of a[][] and j column of b[][] :

            for (int k=0 ; k<n ; k++) {                     // n , p = 2 gape :
                res[i][j] += a[i][k] * b[k][j] ;
            }
        }
    }
    printf ("The resultent matrix is\n") ;
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<q ; j++) {
            printf ("%d ",res[i][j]);
        }
        printf ("\n");
    }
    }
    return 0 ;

}
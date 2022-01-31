/*Test whether a given set X is a subset of the set A or not.*/
#include <stdio.h>
#include <conio.h>

int isSubset(int a[], int x[], int m, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (x[i] == a[j])
                break;
        }
        /*If the above inner loop was not broken at all then x[i] is not present in a[] */
        if (j == m)
            return 0;
    }
    return 1; /*If we reach here then all elements of x[] are present in a[] */
}
int main()
{
    int a[10], x[10], m, n, i;
    printf("\n Enter how many elements you required to in set A:-");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        printf("Enter the elements of set A[%d]:", i);
        scanf("%d", &a[i]);
    }
    printf("\n Enter how many elements you required to in set X:-:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the elements of set X[%d]:", i);
        scanf("%d", &x[i]);
    }
    if (isSubset(a, x, m, n))
        printf("X is a subset of A");
    else
        printf("X is not a subset of A");
}

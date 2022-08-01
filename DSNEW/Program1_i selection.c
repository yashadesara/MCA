//Selection Sort
#include <stdio.h>
struct sort
{
    int n;
    int a[100];
};
void printFile(int arr[100], int n)
{
    FILE *fp;
    int i;
    fp = fopen("test1.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%d", arr[i]);
    printf("\n File Printed successfully!!! \n");   
    fclose(fp);
}
int main()
{
    struct sort s;
    int i, j, min, swap;

    printf("Enter number of elements to be sorted:");
    scanf("%d", &s.n);

    printf("Enter %d Numbers in array:", s.n);
    for (i = 0; i < s.n; i++)
        scanf("%d", &s.a[i]);

    for (i = 0; i < s.n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < s.n; j++)
        {
            if (s.a[min] > s.a[j])
                min = j;
        }
        if (min != i)
        {
            swap = s.a[i];
            s.a[i] = s.a[min];
            s.a[min] = swap;
        }
    }
    printf("Array elements sorted by selection sort: ");
    for (i = 0; i < s.n; i++)
        printf("%d", s.a[i]);

    printFile(s.a, s.n);
    return 0;
}
//Bubble Sort
#include <stdio.h>
struct sort{
   int n;
   int a [100];
};
void printFile(int arr[100], int n)
{
    FILE *fp;
    int i;
    fp = fopen("test2.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%d", arr[i]);
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
int main()
{
    struct sort s;
    int i, j, max, temp;

    printf("Enter number of elements to be sorted:");
    scanf("%d", &s.n);

    printf("Enter %d Numbers in array:", s.n);
    for (i = 0; i < s.n; i++)
        scanf("%d", &s.a[i]);

    for (i = 0; i < s.n-1; i++)     
    {
       // Last i elements are already in place  
       for (j = 0; j < s.n-i-1; j++)
       {
           if (s.a[j] > s.a[j+1])
              {
                temp = s.a[j];
                s.a[j] = s.a[j+1];
                s.a[j+1] = temp;
              }
       }
    }
    printf("Array elements sorted by bubble sort: \n");
    for (i = 0; i < s.n; i++)
        printf("%d \n", s.a[i]);
    printFile(s.a, s.n);
    return 0;
}
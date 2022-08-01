//Linear (Sequential) Search
#include <stdio.h>
struct search_l
{
    int n;
    int array[100];
};
void printFile(int s, int n)
{
    FILE *fp;
    int i;
    fp = fopen("test_p1.txt", "w");
    fprintf(fp, "%d is present at location %d.\n", s, n);
    printf("\n File Printed successfully!!! \n");   
    fclose(fp);
}
int main()
{
    struct search_l s;
    int search, c;

    printf("Enter number of elements in array\n");
    scanf("%d", &s.n);

    printf("Enter %d integer(s)\n", s.n);

    for (c = 0; c < s.n; c++)
        scanf("%d", &s.array[c]);

    printf("Enter a number to search\n");
    scanf("%d", &search);

    for (c = 0; c < s.n; c++)
    {
        if (s.array[c] == search) /* If required element is found */
        {
            printf("%d is present at location %d.\n", search, c + 1);
            printFile(search, c + 1);
            break;
        }
    }
    if (c == s.n)
        printf("%d isn't present in the array.\n", search);

    return 0;
}
#include <stdio.h>
#define max 10
void binary_search(int [], int, int, int);
struct binSearch
{
    int list[max];
    int size;
}s;
void printFile(int mid)
{
    FILE *fp;
    int i;
    fp = fopen("binarySearch_Rec.txt", "w");
    fprintf(fp,"\n Key found at position: %d",mid);
	printf("\n File Printed successfully!!! \n");
    fclose(fp);
} 
int main()
{
    int key, i;

    printf("Enter size of a list: ");
    scanf("%d", &s.size);
    printf("Enter elements\n");
    for(i = 0; i < s.size; i++)
    {
        scanf("%d",&s.list[i]);
    }
   
    printf("Enter key to search\n");
    scanf("%d", &key);
    binary_search(s.list, 0, s.size, key);
 
}
  
void binary_search(int list[], int lo, int hi, int key)
{
    int mid;
 
    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("\n Key found at position: %d",mid+1);
        printFile(mid+1);
    }
    else if (list[mid] > key)
    {
        binary_search(list, lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, hi, key);
    }
}
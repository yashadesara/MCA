//Heap Sort
#include <stdio.h>
int temp;
struct sort
{
    int count;
    int arr[25];
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
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (i = size - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void main()
{
    struct sort s;

    int i;
    printf("How many elements are u going to enter?: ");
    scanf("%d", &s.count);

    printf("Enter %d elements: ", s.count);
    for (i = 0; i < s.count; i++)
        scanf("%d", &s.arr[i]);

    heapSort(s.arr, s.count);

    printf("printing sorted elements\n");
    for (i = 0; i < s.count; ++i)
        printf("%d\n", s.arr[i]);
    printFile(s.arr, s.count);
}
// C program to implement recursive Binary Search
#include <stdio.h>
struct search_b
{
    int n;
    int array[100];
};
void printFile(int s, int n)
{
    FILE *fp;
    int i;
    fp = fopen("test_p2.txt", "w");
    fprintf(fp, "%d is present at location %d.\n", s, n);
    printf("\n File Printed successfully!!! \n");   
    fclose(fp);
}
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void)
{
	struct search_b s;
    int search, c;

    printf("Enter number of elements in array\n");
    scanf("%d", &s.n);

    printf("Enter %d integer(s)\n", s.n);

    for (c = 0; c < s.n; c++)
        scanf("%d", &s.array[c]);

    printf("Enter a number to search\n");
    scanf("%d", &search);

	int result = binarySearch(s.array, 0, s.n - 1, search);
	(result == -1) ? printf("Element is not present in array")
				: printf("Element is present at index %d",
							result+1);
    printFile(search, result+1);
	return 0;
}

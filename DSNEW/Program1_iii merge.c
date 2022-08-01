/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>

struct sort{
   int n;
   int arr[6];
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
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver code */
int main()
{
    struct sort s;
    int i;
	printf("Enter number of elements to be sorted:");
    scanf("%d", &s.n);

    printf("Enter %d Numbers in array:", s.n);
    for (i = 0; i < s.n; i++)
        scanf("%d", &s.arr[i]);

	printf("Given array is \n");
	printArray(s.arr, s.n);

	mergeSort(s.arr, 0, s.n - 1);

	printf("\nSorted array is \n");
	printArray(s.arr, s.n);
	printFile(s.arr, s.n);
	return 0;
}

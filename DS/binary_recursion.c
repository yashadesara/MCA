#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}

struct bin
{
	int arr[10];
	int n;
};

int main(void)
{
	struct bin b;
	int i,x;
	printf("enter length: ");
	scanf("%d",&b.n);
	
	printf("enter elements: ");
	for(i=0;i<b.n;i++)
		scanf("%d",&b.arr[i]);

	printf("enter elements to search: ");
	scanf("%d",&x);

	int result = binarySearch(b.arr, 0, b.n - 1, x);
	(result == -1)
		? printf("not present in array")
		: printf("Present at index %d", result);
	return 0;
}


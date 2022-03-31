#include <stdio.h>

void heapify();
void heapSort();
void printArray();
void printfile();

struct heap
{
	int arr[10];
	int n;
};

int main()
{
	struct heap h;
	int i;
	printf("enter length: ");
	scanf("%d",&h.n);
	printf("enter elements: ");
	for(i=0; i<h.n; i++)
		scanf("%d",&h.arr[i]);

	heapSort(h.arr, h.n);
	printf("sorted array is: ");
	printArray(h.arr, h.n);
	
}

void heapify(int arr[], int n, int i)
{
//	int i;
	int temp;
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr, n, largest);
	}
}


void heapSort(struct heap h)
{
	int i,temp;
	
	for (i = h.n / 2 - 1; i >= 0; i--)
		heapify(h.arr, h.n, i);

	for (i = h.n - 1; i > 0; i--) {
		temp=h.arr[0];
		h.arr[0]=h.arr[i];
		h.arr[i]=temp;
		heapify(h.arr, i, 0);
	}
}

void printArray(struct heap h)
{
	int i;
	for (i = 0; i < h.n; ++i)
		printf("%d ",h.arr[i]);
	printf("\n");
}

void printfile(struct heap h)
{
	FILE *fp;
	int i;
	fp = fopen("demo.txt","w");
	for(i=0; i<h.n; i++)
		fprintf(fp,"%d ",h.arr[i]);
	printf("\nprinted");
	fclose(fp);
}





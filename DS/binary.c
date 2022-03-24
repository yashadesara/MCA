#include <stdio.h>

struct binary
{
   int array[10],n;
};

void printfile(int a[10],int n)
{
	FILE *fp;
	int i;
	fp = fopen("demo.txt","w");
	for(i=0; i<n; i++)
		fprintf(fp,"%d ",a[i]);
	printf("\nprinted");
	fclose(fp);
}

int main()
{
  struct binary b;
  int c, first, last, middle, search;

  printf("Enter number of elements\n");
  scanf("%d", &b.n);

  printf("Enter %d integers\n", b.n);

  for (c = 0; c < b.n; c++)
    scanf("%d", &b.array[c]);

  printf("Enter value to find\n");
  scanf("%d", &search);

  first = 0;
  last = b.n - 1;
  middle = (first + last) / 2;

  while (first <= last)
  {
    if (b.array[middle] < search)
      first = middle + 1;
    else if (b.array[middle] == search)
    {
      printf("%d found at location %d.\n", search, middle + 1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last) / 2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);

  printfile(b.array,b.n);
  return 0;
  
}

//Quick Sort
#include<stdio.h>
struct sort{
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
void quicksort(int arr[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);

   }
}

int main()
{
   struct sort s;
   int i;

   printf("How many elements are u going to enter?: ");
   scanf("%d",&s.count);

   printf("Enter %d elements: ", s.count);
   for(i=0;i<s.count;i++)
      scanf("%d",&s.arr[i]);

   quicksort(s.arr,0,s.count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<s.count;i++)
      printf(" %d",s.arr[i]);
    printFile(s.arr, s.count);
   return 0;
}
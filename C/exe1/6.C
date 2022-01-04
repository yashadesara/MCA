#include <stdio.h>

void main()
{
    int i, n, sum = 0, avg, count = 0, length;
    int a[10];
    
    printf("enter length of array: \n");
    scanf("%d", &length);
    
    printf("enter values");

    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
        count++;
    }
    
    avg = sum / count;

    for (n = 0; n < i; n++)
    {
        printf("values is: %d \n", a[n]);
    }
    
    printf("sum is: %d \n", sum);
    printf("avg is: %d \n", avg);

}
#include <stdio.h>

void main()
{
    int i,sum=0,avg;
    for (i=1; i<=10; i++)
    {
        sum = sum+i;
    }
    avg = sum/10;
    printf("sum is %d \n",sum);
    printf("avg is %d \n",avg);
}
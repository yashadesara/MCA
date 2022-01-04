#include <stdio.h>

void main()
{

    int i, j, ele1, ele2, ele3, avg, sum = 0;
    

    printf("enter 1st element : ");
    scanf("%d", &ele1);
    
    printf("enter 2nd element : ");
    scanf("%d", &ele2);
    
    printf("enter 3rd element : ");
    scanf("%d", &ele3);
    
    sum = ele1+ele2+ele3;
    avg = sum/3;
   
    printf("sum is: %d \n", sum);
    printf("avg is: %d \n", avg);
    printf("ele 1 is: %d\nele 2 is: %d\nele 3 is: %d\n",ele1,ele2,ele3);

}
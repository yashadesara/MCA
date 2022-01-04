#include <stdio.h>

void main()
{

    int a=20, b=10;
    printf("before swap a is: %d\n",a);
    printf("before swap b is: %d\n\n",b);
    
    a = a + b; // a now becomes 30
    b = a - b; // b becomes 20
    a = a - b; // a becomes 10
    
    printf("after swap a is: %d\n",a);
    printf("after swap b is: %d\n",b);
    
}
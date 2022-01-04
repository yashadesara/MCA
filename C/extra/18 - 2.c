#include <stdio.h>

int main()
{
    int i,j,n;
    char letter;
    printf("enter n");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {                                  
        for(j=1; j<=i; j++)
        {
            letter = j+64;
            printf("%c",letter);
        }    
    printf("\n");
    }
}

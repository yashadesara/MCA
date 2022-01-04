#include<stdio.h>
#include<conio.h>
int smallestDivisor(int n)
{
    int i;
    if (n % 2 == 0)
	return 2;
    for (i = 3; i * i <= n; i += 2) {
	if (n % i == 0)
	    return i;
    }
    return n;
}

int main()
{
    int n,res;
    printf("Enter the the value of n: ");
    scanf("%d",&n);
    res = smallestDivisor(n);
    printf("Smallest divisor is: %d",res);
    getch();
    return 0;
}

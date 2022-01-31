#include <stdio.h>  
#include <conio.h>  
int main()  
{
	long n1,n2,bin_sum;
	int i=0,rem=0,sum[20];
	
	printf (" Enter any two binary numbers: \n ");  
    scanf ("%ld", &n1); 

	printf (" Enter any two binary numbers: \n ");  
    scanf ("%ld", &n2);     
    
    while(n1!=0 || n2!=0)
	{
		sum[i++] = (n1%10+n2%10+rem)%2;
		rem=(n1%10+n2%10+rem)/2;
		n1 = n1/10;
		n2 = n2/10;
	}
	if(rem!=0)
		sum[i++]=rem;
	--i;
	printf("sum of binary no: ");
	while(i>=0)
		printf("%d",sum[i--]);
}

 //1010
 //1111
//________
//11001

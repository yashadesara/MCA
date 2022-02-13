#include <stdio.h>  
#include <conio.h>  
int main()  
{  
    int n1, n2, i, gcd,lcm;  
    printf (" Enter any two numbers: \n ");  
    scanf ("%d %d", &n1, &n2);   
      
    for(i=1; i<=n1 && i<=n2; i++)  
    {  
        if (n1%i==0 && n2%i==0)  
        {
            gcd=i;
            lcm=n1*n2/gcd;
    	}
    }  
    
    printf("GCD(greatest common divisor) of %d and %d is %d\n",n1,n2,gcd);  
    printf("LCD(lowest common multiplier) of %d and %d is %d",n1,n2,lcm);  
    return 0;  
}  

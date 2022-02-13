#include<stdio.h>    
#include<stdlib.h>  
int conversion(int num,int base)
{  
	int rem=num%base;
	if(num==0)
		return;
	conversion(num/base,base);
	if(rem<10)
		printf("%d",rem);    
	else
		printf("%c",rem-10+'A');    	
}  

int main()
{
	int num,choice;    
	printf("Enter the number in Decimal: ");    
	scanf("%d",&num);   
	while(1)
	{
		printf("\n 1. Decimal to Binary");
		printf("\n 2. Decimal to Octal");
		printf("\n 3. Decimal to HexaDecimal");
		printf("\n 4. Quit");
		printf("\n Enter Option\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Binary value: ");
					conversion(num,2);
					break;
			case 2: printf("Octal value: ");
					conversion(num,8);
					break;
			case 3: printf("HexaDecimal value: ");
					conversion(num,16);
					break;
			case 4: exit(0);
					default:  printf("enter choice: \n");
		}
	}
	printf("\n");
}

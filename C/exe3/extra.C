#include<stdio.h>
#include<conio.h>

void main()
{
	float cel[10],freh[10],num,i,j;
	clrscr();

       printf("\n enter n:");
       scanf("%f",&num);
	for(i=0;i<num;i++)
	{
		printf("\n enter Temp in frehenhit :");
		scanf("%f",&freh[i]);


		cel[i] =  (freh[i]-32)/1.8;
		printf("\n temprature in celsius : %2f \n", cel[i]);

	}
	printf("Table is \n");
	printf("celsius \t ferehenhit \t \n");
	for(i=0;i<num;i++)
	{
		printf("%f \t\t %f\n",cel[i],freh[i]);
	}
	getch();
}

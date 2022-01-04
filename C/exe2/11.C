#include<stdio.h>
#include<conio.h>

void main()
{
	int i,n,j;
	char s1[20],s[20];
	printf("enter data for revrse: ");
	gets(s);

	for(i=0; s[i] != '\0'; i++);
		n=i-1;

	for(j=0; j<i; j++)
	{
		  s1[j] = s[n];
		  n--;
	}
	s1[j] = '\0';
	printf("%s",s1);
}
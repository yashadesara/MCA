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


// #include<stdio.h>
// #include<string.h>

// int main()
// {
// 	int i,j,n=0;
// 	char str[10],str2[10];
	
// 	printf("Enter s string: ");
// 	gets(str);
		
// 	for(i=0; str[i]!='\0'; i++)
// 		n++;
		
// 	for(j=n-1; j>=0; j--)
// 	{
// 		printf("%c",str[j]);	
// 	}
// }

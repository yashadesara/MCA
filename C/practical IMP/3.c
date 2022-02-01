#include<stdio.h>
#include<string.h>

int main()
{
	int i,count=0;
	char str[10],*p;
	
	printf("enter a string: ");
	gets(str);
	p = str;
	
	while(*p)  
    {
    	if(*p++==32)
        	count++;
    } 
    
    if(strlen(str)>0)
    	count++;
    	
    printf("words count is = %d\n", count);
}

//int main()
//{
//	int i,count=0;
//	char str[10],*p;
//	
//	printf("enter a string: ");
//	gets(str);
//	
//	for(i=0; str[i]!='\0'; i++)
//	{
//		if(str[i]==' ' && str[i+1] != ' ')
//			count++;
//	}
//	
//	printf("%d\n",count+1);
//	printf("%s",str);
//	
//}




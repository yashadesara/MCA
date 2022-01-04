#include <string.h>
#include <conio.h>
int main()
{
    char s[100],*p;  
    int words=0;
    printf("Enter  the string : ");
    gets(s); 
   
    p = s; 
    while(*p)  
    {
    	if(*p++==32)
        	words++;
    } 

    if(strlen(s)>0)
    			words++;

    printf("no of words in string = %d\n", words);
    return 0;  
}

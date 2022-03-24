#include<stdio.h>
#include<stdlib.h>
#define Size 4 
  
int Push();
int Pop();
void show();
void pip();
  
//int Top=-1,inp_array[Size];

struct stack
{
	int Top;
	int inp_array[Size];
};  

int main()
{
	struct stack s;
	s.Top=-1;
    int choice;    
    while(1)    
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Pip\n5.End");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
         
        switch(choice)
        {
            case 1: s.Top=Push(s.Top,s.inp_array);
                    break;
            case 2: s.Top=Pop(s.Top,s.inp_array);
                    break;
            case 3: show(s.Top,s.inp_array);
                    break;
            case 4: pip(s.Top,s.inp_array);
                    break;
            case 5: exit(0);
             
            default: printf("\nInvalid choice!!");
        }
    }
}
  
int Push(int Top,int inp_array[Size])
{
    int x;
     
    if(Top==Size-1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter element to be inserted to the stack:");
        scanf("%d",&x);
        Top=Top+1;
        inp_array[Top]=x;
    }
    return Top;
}
  
int Pop(int Top,int inp_array[Size])
{
    if(Top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element:  %d",inp_array[Top]);
        Top=Top-1;
    }
    return Top;
}
  
void show(int Top,int inp_array[Size])
{
     
    int i;
    if(Top==-1)
    {
        printf("\nUnderflow!!");
    }
    printf("\nElements present in the stack: \n");
    for(i=Top;i>=0;--i)
        printf("%d\n",inp_array[i]);
    
}

void pip(int Top,int inp_array[Size])
{
	int i;
    if(Top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("%d",inp_array[Top]);
    }
}

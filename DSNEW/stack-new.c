#include<stdio.h>
#include<conio.h>

int stack[5],key,insert;
int top = -1;
int SIZE = 5;

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(top==SIZE)
		return 1;
	else
		return 0;
}


void push()
{
	int data;
	printf("enter insert element: ");
	scanf("%d",&data);
	if(!isFull())
	{
		top += 1;
		stack[top] = data;
		printf("inserted");
	}
	else
		printf("not inserted,stack is full");
}

void pop()
{
	int data;
	if(!isEmpty())
	{
		data = stack[top];
		top -= 1;
		printf("deleted");
	}
	else
		printf("not deleted,stack is empty");
}

void show()
{
	int i;
	if(isEmpty())
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for(i=top;i>=0;--i)
            printf("%d\n",stack[i]);
    }
}

int peek()
{
	printf("%d",stack[top]);
}


void main()
{
	int choice;
     
    while(1)    
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Peek\n5.exit");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
         
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: show();
                    break;
            case 4: peek();
                    break;
            case 5: break;
         
            default: printf("\nInvalid choice!!");
        }
    }
	
}

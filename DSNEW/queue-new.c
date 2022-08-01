#include<stdio.h>
#include<conio.h>

#define MAX 50

int queue[MAX],key,insert;
int rear = -1;
int front = -1;
int SIZE = 5;

int isEmpty()
{
	if (front == - 1 || front > rear)
		return 1;
	else
		return 0;
}

int isFull()
{
	if (rear == MAX - 1)
		return 1;
	else
		return 0;
}


void enqueue()
{
	int data;
	
	if(rear == MAX - 1)
		printf("Queue Overflow n");
	else
		{
			if(front== - 1)
				front = 0;
			printf("Insert the element in queue : ");
			scanf("%d", &data);
			rear = rear + 1;
			queue[rear] = data;
		}
}

void dequeue()
{
	int data;
	if(!isEmpty())
	{
		printf("Element deleted from queue");
        front = front + 1;
	}
	else
		printf("not deleted,queue is empty");
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
        printf("\nElements present in the queue: \n");
        for(i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
}


void main()
{
	int choice;
     
    while(1)    
    {
        printf("\nOperations performed by Queue");
        printf("\n1.enqueue the element\n2.dequeue the element\n3.Show\n4.exit");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
         
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: show();
                    break;
            case 4: break;
         
            default: printf("\nInvalid choice!!");
        }
    }
	
}

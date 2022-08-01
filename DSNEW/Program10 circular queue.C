#include <stdio.h>
#define MAX 5
int front = -1;
int rear = -1;
struct cir_queue_op
{
    int n;
    int cqueue_arr[MAX];
};
int  isFull(int n) {
   if ((front == 0 && rear == n - 1) || (front == rear + 1))
	return 1;
	else
	{
		return 0;
	}
	
}
void insert(int cqueue_arr[], int n)
{
	int item;
	if (isFull(n)==1)
	{
		printf("Queue is Overflow!! Try other operations.\n");
		return;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if (rear == MAX - 1)
			rear = 0;
		else
			rear = rear + 1;
	}
	printf("\nInput the element for insertion in queue : ");
			scanf("%d", &item);
	cqueue_arr[rear] = item;
}
int underflow()
{
	if (front == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
void deletion(int cqueue_arr[])
{
	if (underflow()==1)
	{
		printf("Queue is Underflow!! Please try other operations.\n");
		return;
	}
	printf("Element deleted from queue is : %d\n", cqueue_arr[front]);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if (front == MAX - 1)
			front = 0;
		else
			front = front + 1;
	}
}
void display(int cqueue_arr[], int n)
{
	int front_pos = front, rear_pos = rear;
	if (underflow()==1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	if (front_pos <= rear_pos)
		while (front_pos <= rear_pos)
		{
			printf("%d\n", cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while (front_pos <= n - 1)
		{
			printf("%d\n", cqueue_arr[front_pos]);
			front_pos = front_pos+1;
		}
		front_pos = 0;
		while (front_pos <= rear_pos)
		{
			printf("%d\n", cqueue_arr[front_pos]);
			front_pos++;
		}
	}
}
void printFile(int cqueue_arr[], int n)
{
    FILE *fp;
    int i;
	int front_pos = front, rear_pos = rear;
    fp = fopen("Circular_queue.txt", "w");
	if (front_pos <= rear_pos)
		while (front_pos <= rear_pos)
		{
			fprintf(fp,"%d\n", cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while (front_pos <= n - 1)
		{
			fprintf(fp,"%d\n", cqueue_arr[front_pos]);
			front_pos = front_pos+1;
		}
		front_pos = 0;
		while (front_pos <= rear_pos)
		{
			fprintf(fp,"%d\n", cqueue_arr[front_pos]);
			front_pos++;
		}
	}
    
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
int main()
{
	struct cir_queue_op c;
	int choice;
	printf("Input the size of queue : ");
			scanf("%d", &c.n);
	do
	{
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Print file and Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insert(c.cqueue_arr,c.n);
			break;
		case 2:
			deletion(c.cqueue_arr);
			break;
		case 3:
			display(c.cqueue_arr,c.n);
			break;
		case 4:
			printFile(c.cqueue_arr, c.n);
			break;
		default:
			printf("Wrong choicen");
		}
	} while (choice != 4);
	return 0;
}
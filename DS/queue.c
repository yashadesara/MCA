#include <stdio.h>
#include <stdlib.h>

# define SIZE 100

void enqueue();
void dequeue();
void show();
int isEmpty();
int isFull();
void printfile();

int Rear = - 1;
int Front = - 1;

struct queue
{
	int inp_arr[SIZE];
};

int main()    
{
	struct queue q;
    int ch;
    while (1)
    {
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display \n");
        printf("4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            	enqueue(q.inp_arr);
            	break;
            case 2:
            	dequeue(q.inp_arr);
            	break;
            case 3:
            	show(q.inp_arr);
            	break;
            case 4:
				exit(0);
            default:
            	printf("invalid choice \n");
        } 
    } 
} 
  
int isEmpty()
{
	return Front == - 1;
}  

int isFull()
{
	return Rear == SIZE - 1;
}  

void enqueue(struct queue q)
{
    int insert_item;
    if (isFull())
       printf("Overflow \n");
    else
    {
        if (isEmpty())       
        Front = 0;

        printf("Element to insert in Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        q.inp_arr[Rear] = insert_item;
    }
} 
  
void dequeue(struct queue q)
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted: %d\n", q.inp_arr[Front]);
        Front = Front + 1;
    }
} 
  

void show(struct queue q)
{
	int i;
    if (isEmpty())
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (i = Front; i <= Rear; i++)
            printf("%d ", q.inp_arr[i]);
        printf("\n");
    }
    printfile(q.inp_arr);
} 

void printfile(struct queue q)
{
	FILE *fp;
	int i;
	fp = fopen("demo.txt","w");
	for (i = Front; i <= Rear; i++)
            fprintf(fp, "%d ", q.inp_arr[i]);
    printf("\nprinted");        
	fclose(fp);
}




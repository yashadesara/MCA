#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void insert();
void delete ();
void display();
int isEmpty();
int  isFull();

int rear = -1;
int front = -1;

struct queue_op
{
    int n;
    int queue_array[MAX];
};

void printFile(int queue_array[], int n)
{
    FILE *fp;
    int i;
    fp = fopen("queue.txt", "w");
    for (i = front; i <= rear; i++)
        fprintf(fp, "%d", queue_array[i]);
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}

void main()
{
    struct queue_op s;
    int choice;
    printf("Enter the size of queue: \n");
    scanf("%d", &s.n);
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.print the file and quit. \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(s.queue_array,s.n);
            break;
        case 2:
            delete (s.queue_array,s.n);
            break;
        case 3:
            display(s.queue_array,s.n);
            break;
        case 4:
            printFile(s.queue_array, s.n);
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}
int isEmpty() {
    return(front == -1 || front > rear);
}

int  isFull(int n) {
   return rear == n-1;
}
void insert(int queue_array[], int n)
{
    int add_item;
    if (isFull(n))
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
            /*If queue is initially empty */
            front = 0;
        printf("\nInsert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        printf("\n Inserted element is: %d \n",add_item);
        queue_array[rear] = add_item;
    }
} 

void delete (int queue_array[], int n)
{
    if (isEmpty())
    {
        printf("Queue Underflow \n");
        return;
    }
    
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}
void display(int queue_array[], int n)
{
    int i;
    if (isEmpty())
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
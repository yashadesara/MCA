#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
int underflow()
{
    if ((f == NULL) && (r == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(int size, int count)
{
    if (size == count)
        return 1;
    else
    {
        return 0;
    }
}
void enqueue() //Insert elements in Queue
{
    struct node *n;
    int item;
    n = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter your data: ");
    scanf("%d", &item);
    n->data = item;
    n->next = NULL;
    if ((r == NULL) && (f == NULL))
    {
        f = r = n;
        r->next = f;
    }
    else
    {
        r->next = n;
        r = n;
        n->next = f;
    }
    printf("\nElement %d inserted!! ",item);
}
void dequeue() // Delete an element from Queue
{
    struct node *t;
    t = f;
    if (underflow() == 1)
        printf("\nQueue is Empty");
    else if (f == r)
    {
        f = r = NULL;
        printf("\nElement %d deleted!! ",t->data);
        free(t);
    }
    else
    {
        f = f->next;
        r->next = f;
        printf("\nElement %d deleted!! ",t->data);
        free(t);
    }
    
}
void display()
{ // Print the elements of Queue
    struct node *t;
    t = f;
    if (underflow() == 1)
        printf("\nQueue is Empty");
    else
    {
        do
        {
            printf("\n%d", t->data);
            t = t->next;
        } while (t != f);
    }
}
void printFile()
{
    FILE *fp;
    struct node *t;
    t = f;
    fp = fopen("Cir_queue2.txt", "w");
    do
        {
            fprintf(fp,"\n%d", t->data);
            t = t->next;
        } while (t != f);
    
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
int main()
{
    int opt, i, size, count = 0;
    printf("\nEnter the size of circular queue: ");
    scanf("%d", &size);
    printf("Enter Your Choice:-");
    do
    {
        printf("\n\nPress 1 for Insert the Data in Queue\n Press 2 for show the Data in Queue \n Press 3 for Delete the data from the Queue\n Press 0 for Print file & Exit: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            
            if (isFull(size,count) == 1)
            {
                printf("\nQueue is Full!!");
            }
            else
            {
                enqueue(size, count);
                count++;
            }
            break;
        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 0:
            printFile();
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (opt != 0);
    return 0;
}
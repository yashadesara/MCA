#define true 1
#define false 0

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3

struct q_point
{
    int ele;
    struct q_point *next;
};

struct q_point *head = NULL;
int count = 0;
int underflow();
void add_ele(int);
int rem_ele();
void show_ele();
int overflow();

void printFile()
{
    FILE *fp;
    int i;
    struct q_point *ptr = NULL;
    ptr = head;
    fp = fopen("queueLink.txt", "w");
    while (ptr != NULL)
        {
            fprintf(fp,"%d \t", ptr->ele);
            ptr = ptr->next;
        }
        
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}

/*main function*/
void main()
{
    int ele, choice, j;
    while (choice != 4)
    {

        printf("\n\n * ***IMPLEMENTATION OF newNode USING POINTERS * ***\n");
        printf("== == == == == == == == == == == == == == == == == == == == == == ==");
        printf("\n\t\t MENU\n");
        printf("== == == == == == == == == == == == == == == == == == == == == == ==");
        printf("\n\t[1] To insert an element");
        printf("\n\t[2] To remove an element");
        printf("\n\t[3] To display all the elements");
        printf("\n\t[4] Print and Exit");
        printf("\n\n\tEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (!overflow())
            {
                printf("\n\tElement to be inserted:");
                scanf("%d", &ele);
                add_ele(ele);
            }
            else
            {
                printf("\n\t Cannot insert more. Queue is full. Max size is %d", MAXSIZE);
            }
            break;
        case 2:

            j = rem_ele();
            printf("\n\t %d is removed from the newNode", j);

            break;

        case 3:
            show_ele();
            break;

        case 4:
            printFile();
            exit(1);
            break;

        default:
            printf("\n\tInvalid choice.");

            break;
        }
    }
}

/* Function to check if the queue is empty*/
int underflow()
{
    if (head == NULL)
        return true;
    return false;
}
/* Function to check if the queue is full*/
int overflow()
{
    if (count == MAXSIZE)
        return true;
    return false;
}

/* Function to add an element to the newNode*/
void add_ele(int ele)
{
    struct q_point *newNode = (struct q_point *)malloc(sizeof(struct q_point));
    newNode->ele = ele;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        struct q_point *ptr;
        for (ptr = head; ptr->next != NULL; ptr = ptr->next);
        ptr->next = newNode;
    }
    printf("\n\telement inserted %d", ele);
    count++;
}

/* Function to remove an element from the queue*/
int rem_ele()
{
    struct q_point *newNode = NULL;
    if (underflow() == false)
    {
        int j = head->ele;
        newNode = head;
        head = head->next;
        free(newNode);
        return j;
    }
    else
    {
        printf("\n\t queue is empty.");
        return 0;
    }
}

/* Function to display the newNode*/
void show_ele()
{
    struct q_point *ptr = NULL;
    ptr = head;
    if (underflow())
    {
        printf("\n\tnewNode is Empty.");
        return;
    }
    else
    {
        printf("\n\tElements present in newNode are:\n\t");
        while (ptr != NULL)
        {
            printf("% d\t", ptr->ele);
            ptr = ptr->next;
        }
    }
}
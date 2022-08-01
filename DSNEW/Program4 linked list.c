#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert();
void lastinsert();
void insertion_inorder_sort();
void random_delete();
void copyList();
void display();
void printFile();

void main()
{
    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at location preserving order\n4.delete at specifed location\n5.Create duplicate linked list\n6.Show\n7.Print File\n8.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            insertion_inorder_sort();
            break;
        case 4:
            random_delete();
            break;
        case 5:
            copyList();
            break;
        case 6:
            display();
            break;
        case 7:
            printFile();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted");
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}
void insertion_inorder_sort()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value?\n");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    //If linked list is empty
    if (head == NULL)
    {
        ptr->next = head;
        head = ptr;
        return;
    }

    //Locate the node before insertion
    struct node *current = head;
    while (current->next != NULL && current->next->data < ptr->data)
        current = current->next;

    ptr->next = current->next;
    current->next = ptr;
}
void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {

        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    if (ptr == head)
    {
        head = head->next;
    }

    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d ", loc);
}
void copyList()
{
    struct node *ptr, *ptr1;
    ptr = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    ptr1 = newNode;
    while (ptr != NULL)
    {
        newNode->data = ptr->data;
        if (ptr->next == NULL)
        {
            newNode->next = NULL;
        }
        else
        {
            newNode->next = (struct node *)malloc(sizeof(struct node));
            newNode = newNode->next;
        }
        ptr = ptr->next;
    }
    printf("\nDuplicate Linked list created.... Printing values of duplicate list . . . . .\n");
    while (ptr1 != NULL)
    {
        printf("\n%d", ptr1->data);
        ptr1 = ptr1->next;
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}
void printFile()
{
    FILE *fp;
    int i;
    struct node *ptr;
    ptr = head;
    fp = fopen("LinkedListFile.txt", "w");
    while (ptr != NULL)
        {
            fprintf(fp,"\n%d", ptr->data);
            ptr = ptr->next;
        }
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
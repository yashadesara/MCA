#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *List1 = NULL;

void createList();
void deleteFirst();
void deleteLastNode();
void beginsert();
void lastinsert();
void insertBefore();
void insertAt();
void random_delete();
void countList();
void copyList();
void mergeList();
void createTwoList();
void display();
void printFile();
void reverse_list();
void searchInList();
void sortlist();
void swap();
void main()
{
    int choice;
    do
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Create a list");
        printf("\n2.Traverse the whole list or display the list");
        printf("\n3.Delete first node");
        printf("\n4.Delete last node");
        printf("\n5.Delete a node before specified data");
        printf("\n6.Insert at first position");
        printf("\n7.Insert at last position");
        printf("\n8.Insert a node before specified data");
        printf("\n9.Insert a node at specified position");
        printf("\n10.Count the number of node in list");
        printf("\n11.Copy the list");
        printf("\n12.Merge the two lists");
        printf("\n13.Reverse");
        printf("\n14.Search");
        printf("\n15.Sort");
        printf("\n0. Print file and Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            createList(&List1);
            break;
        case 2:
            display();
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLastNode();
            break;
        case 5:
            random_delete();
            break;
        case 6:
            beginsert();
            break;
        case 7:
            lastinsert();
            break;
        case 8:
            insertBefore();
            break;
        case 9:
            insertAt();
            break;
        case 10:
            countList();
            break;
        case 11:
            copyList();
            break;
        case 12:
            createTwoList();

            break;
        case 13:
            reverse_list();
            break;
        case 14:
            searchInList();
            break;
        case 15:
            sortlist();
            break;
        case 0:
            printFile();
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    } while (choice != 0);
}
void createList(struct node *List)
{
    struct node *newNode, *temp;
    int data, i, n;

    temp = List;
    printf("Enter number of nodes in list: ");
    scanf("%d", &n);

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }

    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    // Create n - 1 nodes and add to list
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if (newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
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
void insertBefore()
{
    struct node *ptr;
    int item, pos;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value before which node you want to insert? \n");
    scanf("%d", &pos);
    printf("\nEnter value? \n");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    //If linked list is empty
    if (head == NULL)
    {
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted");
        return;
    }

    //Locate the node before insertion
    struct node *current = head;
    while (current->next->data != pos)
        current = current->next;

    ptr->next = current->next;
    current->next = ptr;
}

void insertAt()
{
    struct node *ptr;
    int position;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value at which node you want to insert??\n");
    scanf("%d", &position);
    printf("\nEnter value before which node you want to insert? \n");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    //If linked list is empty
    if (head == NULL)
    {
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted");
        return;
    }

    //Locate the node before insertion
    struct node *current = head;

    for (int i = 1; i < position - 1; i++) //moving to the (n-1)th position node in the linked list
    {
        current = current->next;
    }

    ptr->next = current->next; //Make the newly created node point to next node of ptr temp
    current->next = ptr;
}

void deleteFirst()
{
    struct node *ptr, *ptr1;
    int i;
    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        ptr = head;
        head = head->next;
        printf("\nDeleted : %d ", ptr->data);
        free(ptr);
    }
}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        /* Traverse to the last node of the list */
        while (toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if (toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
void random_delete()
{

    // Store head node
    struct node *temp, *prev, *ptr;
    temp = head;
    ptr = head;
    int key;

    printf("\n Enter the data present in linked list to delete a node placed before it: \n");
    scanf("%d", &key);

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        printf("\n Linked list conatins only 1 data. Cannot proceed the operation.\n");
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    while (ptr->next != prev)
    {
        ptr = ptr->next;
    }

    // Unlink the node from linked list
    ptr->next = prev->next;
    printf("\n Deleting data: %d \n", prev->data);
    free(prev); // Free memory
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

    struct node *ptr = head;
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
void countList()
{
    struct node *ptr;
    ptr = head;
    int count = 0;
    if (ptr == NULL)
    {
        printf("Nothing to count");
    }
    else
    {
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        printf("\nNumber of nodes in list are: %d", count);
    }
}
void createTwoList()
{
    struct node *prev, *a, *b, *p, *prev1;
    int n, i;
    printf("Enter number of elements in list 1: ");
    scanf("%d", &n);
    printf("\n Start entering %d elements for list 1: \n", n);
    a = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (a == NULL)
            a = p;
        else
            prev->next = p;
        prev = p;
    }
    printf("Enter number of elements in list 2: ");
    scanf("%d", &n);
    printf("\n Start entering %d elements for list 2: \n", n);
    b = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (b == NULL)
            b = p;
        else
            prev1->next = p;
        prev1 = p;
    }

    mergeList(a, b);

    printf("\nMerged Elements are: \n");
    struct node *ptr = a;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}
void mergeList(struct node *a, struct node *b)
{
    if (a->next == NULL)
        a->next = b;
    else
        mergeList(a->next, b);
}

void reverse_list()
{
    // Initialize current, previous and next pointers
    struct node *current = head;
    struct node *p = NULL, *q = NULL;
    while (current != NULL)
    {
        // /* Before changing next pointer of current node
        q = current->next;

        /*  Change next pointer of current node */
        /* Actual reversing */
        current->next = p;

        // Move pointers *p & *current one position ahead
        p = current;
        current = q;
    }
    head = p;
}
void searchInList()
{
    int x,flag=0;
    int count =0;
    struct node* current = head;  // Initialize current
    printf("Enter number to be searched in list1: ");
    scanf("%d", &x);
    while (current != NULL)
    {
        count++;
        if (current->data == x)
            {
                printf("Number %d found at position %d: ",x,count);
                flag=1;
            }
        current = current->next;
    }
    if(flag==0)
    {
        printf("Number not found!!");
    }
}

void sortlist()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (head == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
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
        fprintf(fp, "\n%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
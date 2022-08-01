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

void main()
{
    int choice;
    do
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Create a Circular list");
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
    int val, i, n;

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
    scanf("%d", &val);

    head->data = val; // Link data field with data
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
        scanf("%d", &val);

        newNode->data = val; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
    temp->next = head;
    printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
}
void beginsert()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int item;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nNode Inserted\n");
    }
}
void lastinsert()
{
    int item;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
    }
}
void insertBefore()
{
    struct node *temp;
    int c = 1, val, count = 1;
    struct node *ptr, *ptr1;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("\n Enter the data :");
    scanf("%d", &ptr->data);
    printf("\n Enter the value to insert a node before that specified data:");
    scanf("%d", &val);
    ptr1 = head;
    temp = head;
    if (temp->data == val)
    {
        while (temp->next != head)
            temp = temp->next;
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
    else
    {
        while (temp->data != val)
        {
            ptr1 = temp;
            temp = temp->next;
        }

        ptr->next = temp;
        ptr1->next = ptr;
    }
}

void insertAt()
{
    struct node *temp;
    int c = 1, pos, count = 1;
    struct node *ptr, *ptr1, *ptr2;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("\n Enter the data for particular position:");
    scanf("%d", &ptr->data);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    ptr1 = head;
    temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++;
    if (pos > count)
    {
        printf("OUT OF BOUND");
        return;
    }
    while (c < pos)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        c++;
    }
    ptr->next = ptr1;
    ptr2->next = ptr;
}

void deleteFirst()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nnode deleted\n");
    }
}
void deleteLastNode()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void random_delete()
{
    int i, count;
    struct node *prev, *cur;
    int key;

    printf("\n Enter the data present in linked list to be deleted : \n");
    scanf("%d", &key);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    count = 0;
    cur = head;
    prev = cur;

    // Find node before head node
    while (prev->next != head)
    {
        prev = prev->next;
        count++;
    }

    // Iterate till first node
    i = 0;
    while (i <= count)
    {
        if (cur->data != key)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            // Link prev node with next node of current
            if (cur->next != cur)
                prev->next = cur->next;
            else
                prev->next = NULL;

            // Adjust head node if needed
            if (cur == head)
                head = prev->next;

            // Delete current node
            free(cur);

            // Move current node ahead
            if (prev != NULL)
                cur = prev->next;
            else
                cur = NULL;
        }

        i++;
    }
}
void copyList()
{
    struct node *ptr, *ptr1;
    ptr = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    ptr1 = newNode;
    do
    {
        newNode->data = ptr->data;
        if (ptr->next == head)
        {
            newNode->next = head;
        }
        else
        {
            newNode->next = (struct node *)malloc(sizeof(struct node));
            newNode = newNode->next;
        }
        ptr = ptr->next;
    } while (ptr != head);
    printf("\nDuplicate Linked list created.... Printing values of duplicate list . . . . .\n");
    do
    {
        printf("\n%d", ptr1->data);
        ptr1 = ptr1->next;
    } while (ptr1 != head);
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
        do
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
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
        do
        {
            count++;
            ptr = ptr->next;
        } while (ptr != head);
        printf("\nNumber of nodes in list are: %d", count);
    }
}
void createTwoList()
{
    struct node *prev, *a, *b, *p, *prev1;
    int n, i;
    printf("Enter number of elements in circular list 1: ");
    scanf("%d", &n);
    printf("\n Start entering %d elements for list 1: \n", n);
    a = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);

        if (a == NULL)
        {
            a = p;
            p->next = a;
        }
        else
        {
            prev->next = p;
            p->next = a;
        }
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
        {
            b = p;
            p->next = b;
        }
        else
        {
            prev1->next = p;
            p->next = b;
        }
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
        do
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        } while (ptr != a);
    }
}
void mergeList(struct node *a, struct node *b)
{
    struct node *ptr, *ptr1;
    if (a == NULL)
    {
        a = b;
    }
    ptr = a->next;
    a->next = b->next;
    b->next = ptr;
    a = b;
}

void reverse_list()
{
    struct node *prev, *cur, *next, *last;

    // Cannot reverse empty list
    if (head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }

    // Head is going to be our last node after reversing list
    last = head;

    prev = head;
    cur = (head)->next;
    head = (head)->next;

    // Iterate till you reach the initial node in circular list
    while (head != last)
    {
        head = (head)->next;
        cur->next = prev;

        prev = cur;
        cur = head;
    }

    cur->next = prev;
    head = prev; // Make last node as head
}
void searchInList()
{
    int x, flag = 0;
    int count = 0;
    struct node *current = head; // Initialize current
    printf("Enter number to be searched in list1: ");
    scanf("%d", &x);
    do
    {
        count++;
        if (current->data == x)
        {
            printf("Number %d found at position %d: ", x, count);
            flag = 1;
        }
        current = current->next;
    } while (current != head);
    if (flag == 0)
    {
        printf("Number not found!!");
    }
}

void sortlist()
{
    struct node *current = head, *index = NULL; 
    int temp; 
    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        //Index will point to node next to current
        index = current->next;
        while (index != head)
        {
            //If current node is greater than index data, swaps the data
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current->next != head);
}


void printFile()
{
    FILE *fp;
    int i;
    struct node *ptr;
    ptr = head;
    fp = fopen("CircularLinkedListFile.txt", "w");
    while (ptr != head)
    {
        fprintf(fp, "\n%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
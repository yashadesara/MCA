#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *last;
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
    int choice, data, position;
    do
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Create a Doubly linked list");
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
            printf("Enter data of first node : ");
            scanf("%d", &data);
            beginsert(data);
            break;
        case 7:
            printf("Enter data of last node : ");
            scanf("%d", &data);
            lastinsert(data);
            break;
        case 8:
            printf("Enter the value to insert new node before that specified data : ");
            scanf("%d", &position);
            printf("Enter data to be inserted : ");
            scanf("%d", &data);
            insertBefore(data, position);
            break;
        case 9:
            printf("Enter the position where you want to insert new node: ");
            scanf("%d", &position);
            printf("Enter data of %d node : ", position);
            scanf("%d", &data);
            insertAt(data, position);
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
    int i, data, n;
    struct node *newNode;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    head = (struct node *)malloc(sizeof(struct node));

    if (head != NULL)
    {
        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        /*
             * Create rest of the n-1 nodes
             */
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if (newNode != NULL)
            {
                printf("Enter data of %d node: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->prev = last; // Link new node with the previous node
                newNode->next = NULL;

                last->next = newNode; // Link previous node with the new node
                last = newNode;       // Make new node as last/previous node
            }
            else
            {
                printf("Unable to allocate memory.");
                break;
            }
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void beginsert(int data)
{
    struct node *newNode;

    if (head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head; // Point to next node which is currently head
        newNode->prev = NULL; // Previous node of first node is NULL

        /* Link previous address field of head with newnode */
        head->prev = newNode;

        /* Make the new node as head node */
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}
void lastinsert(int data)
{
    struct node *newNode;
    if (last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}
void insertBefore(int data, int value)
{
    int i = 1;
    struct node *newNode, *temp;

    if (head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;

        while (temp->data != value && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        printf("value of i: %d\n", i);
        if (i == 1)
        {
            beginsert(data);
        }
        else if (temp != NULL)
        {
            insertAt(data, i);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}

void insertAt(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    if (head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i = 1;

        while (i < position - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (position == 1)
        {
            beginsert(data);
        }
        else if (temp == last)
        {
            lastinsert(data);
        }
        else if (temp != NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->prev = temp;       // Connect new node with n-1th node

            if (temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}

void deleteFirst()
{
    struct node *toDelete;

    if (head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node

        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}
void deleteLastNode()
{
    struct node *toDelete;

    if (last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev; // Move last pointer to 2nd last node

        if (last != NULL)
            last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete); // Delete the last node
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}
void random_delete()
{
    struct node *current, *ptr;
    int i, key;

    printf("\n Enter the data present in linked list to be deleted : \n");
    scanf("%d", &key);

    current = head;
    ptr = current;
    for (i = 1; current->data != key && current != NULL; i++)
    {
        ptr = current;
        current = current->next;
    }

    if (i == 1)
    {
        printf("\n Cannot delete the node before head node!!");
    }
    else if (i == 2)
    {
        deleteFirst();
    }
    else if (current != NULL)
    {
        ptr->prev->next = ptr->next;
        current->prev = ptr->prev;

        printf("SUCCESSFULLY DELETED NODE with data %d.\n", ptr->data);
        free(ptr); // Delete the n node
    }
    else
    {
        printf("Invalid position!\n");
    }
}
void copyList()
{
    struct node *ptr, *ptr1, *ptr2;
    ptr = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    ptr1 = newNode;
    ptr2 = newNode;
    while (ptr != NULL)
    {
        newNode->data = ptr->data;
        printf("\ndata: %d", newNode->data);
        if (ptr->next == NULL)
        {
            newNode->next = NULL;
            newNode->prev = ptr1;
        }
        else if (ptr->prev == NULL)
        {
            newNode->prev = NULL;
            newNode->next = (struct node *)malloc(sizeof(struct node));
            newNode = newNode->next;
        }
        else
        {
            newNode->next = (struct node *)malloc(sizeof(struct node));
            ptr1 = ptr;
            newNode = newNode->next;
            newNode->prev = ptr1;
        }
        ptr = ptr->next;
    }
    printf("\nDuplicate Doubly Linked list created.... Printing values of duplicate list . . . . .\n");

    while (ptr2 != NULL)
    {
        printf("\n%d", ptr2->data);
        ptr2 = ptr2->next;
    }
}
void display()
{
    struct node *temp;
    int n = 1;

    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while (temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}
void countList()
{
    struct node *temp;
    int n = 0;

    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;

        while (temp != NULL)
        {

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
        printf("\n\nNumber of nodes in list is: %d\n", n);
    }
}
void createTwoList()
{
    struct node *ptr1, *ptr2, *a, *b, *p, *ptr3, *ptr4;
    int n, i;
    printf("Enter number of elements in doubly list 1: ");
    scanf("%d", &n);
    printf("\n Start entering %d elements for list 1: \n", n);
    a = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (a == NULL)
        {
            a = p;
            p->prev = NULL;
            ptr2 = a;
        }
        else
        {
            ptr1->next = p;
            ptr1->prev = ptr2;
            ptr2 = ptr1;
        }
        ptr1 = p;
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
            p->prev = NULL;
            ptr4 = a;
        }
        else
        {
            ptr3->next = p;
            ptr3->prev = ptr4;
            ptr4 = ptr3;
        }
        ptr3 = p;
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
    {
        a->next = b;
        b->prev = a;
    }
    else
        mergeList(a->next, b);
}

void reverse_list()
{
    struct node *current, *temp;

    current = head;
    while (current != NULL)
    {
        /*
         * Swap the previous and next address fields of current node
         */
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        /* Move the current pointer to next node which is stored in temp */
        current = temp;
    }

    /* 
     * Swap the head and last pointers
     */
    temp = head;
    head = last;
    last = temp;

    printf("LIST REVERSED SUCCESSFULLY.\n");
}
void searchInList()
{
    int x, flag = 0;
    int count = 0;
    struct node *current = head; // Initialize current
    printf("Enter number to be searched in list1: ");
    scanf("%d", &x);
    while (current != NULL)
    {
        count++;
        if (current->data == x)
        {
            printf("Number %d found at position %d: ", x, count);
            flag = 1;
        }
        current = current->next;
    }
    if (flag == 0)
    {
        printf("Number not found!!");
    }
}

void sortlist()
{
    struct node *current = NULL, *index = NULL;
    int temp;
    //Check whether list is empty
    if (head == NULL)
    {
        return;
    }
    else
    {
        //Current will point to head
        for (current = head; current->next != NULL; current = current->next)
        {
            //Index will point to node next to current
            for (index = current->next; index != NULL; index = index->next)
            {
                //If current's data is greater than index's data, swap the data of current and index
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
    printf("\n Sorting complete successfully!!! \n");
}

void printFile()
{
    FILE *fp;
    int i;
    struct node *ptr;
    ptr = head;
    fp = fopen("DoublyLinkedListFile.txt", "w");
    while (ptr != NULL)
    {
        fprintf(fp, "\n%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
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
    int choice, data, position, n;
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
            printf("Enter the number of nodes you want to create: ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
                createList(i);

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
void createList(int i)
{
    struct node *newnode, *temp;
    int num;
    printf("\n Enter a %d value to add at the end of the list: ", i);
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->prev = newnode;
        newnode->data = num;
        newnode->next = newnode;
        head = newnode;
        last = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->data = num;
        newnode->next = head;
        head->prev = newnode;
        temp->next = newnode;
        last = newnode;
    }
}

void beginsert(int data)
{
    struct node *newnode;
    if (head == NULL)
    {
        printf("\n List is empty.");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->prev = last;
        newnode->data = data;
        newnode->next = head;
        head->prev = newnode;
        last->next = newnode;
        head = newnode;
    }
}
void lastinsert(int item)
{
    struct node *newnode, *temp, *endnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->prev = newnode;
        newnode->data = item;
        newnode->next = newnode;
        head = newnode;
        endnode = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->data = item;
        newnode->next = head;
        head->prev = newnode;
        temp->next = newnode;
        endnode = newnode;
    }
}
void insertBefore(int item, int value)
{
    struct node *temp, *ptr;
    if (head == NULL)
    {
        printf("\n List is empty.");
    }
    else
    {
        temp = head;
        while (temp->data != value)
        {
            ptr = temp;
            temp = temp->next;
            if (temp == head)
                return;
        }
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (temp == head)
        {
            beginsert(item);
        }
        else
        {
            newnode->prev = ptr->next;
            newnode->data = item;
            newnode->next = temp;
            ptr->next = newnode;
            temp->prev = newnode;
        }
    }
}

void insertAt(int item, int position)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n List is empty.");
    }
    else
    {

        temp = head;
        for (int i = 2; i <= position; i++)
        {
            temp = temp->next;
        }
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (temp == head)
        {
            newnode->prev = last;
            newnode->data = item;
            newnode->next = head;
            head->prev = newnode;
            last->next = newnode;
            head = newnode;
        }
        else
        {
            newnode->prev = temp->prev;
            newnode->data = item;
            newnode->next = temp;
            temp->prev->next = newnode;
            temp->prev = newnode;
        }
    }
}

void deleteFirst()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
        printf("\nNode Deleted\n");
    }
}
void deleteLastNode()
{
    struct node *temp, *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = head;
        head->prev = ptr;
        free(temp);

        printf("\nNode Deleted\n");
    }
}
void random_delete()
{
    struct node *temp, *ptr;
    int key;
    if (head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if (head->next == head)
    {
        printf("\nCannot Delete\n");
    }
    else
    {
        printf("\n Enter the data present in linked list to be deleted : \n");
        scanf("%d", &key);
        temp = head;
        ptr = temp;
        while (temp->data != key)
        {
            ptr = temp;
            temp = temp->next;
        }

        // if key is first node then delete last node
        if (ptr == temp)
        {
            ptr = temp->prev;
        }

        ptr->prev->next = temp;
        temp->prev = ptr->prev;

        free(ptr);
        printf("\nNode Deleted\n");
    }
}
void copyList()
{
    struct node *ptr, *ptr1, *ptr2;
    ptr = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    ptr1 = newNode;
    ptr2 = newNode;
    do
    {
        newNode->data = ptr->data;
        printf("\ndata: %d", newNode->data);

        if (ptr->next == head)
        {
            newNode->next = head;
            head->prev = ptr;
            newNode->prev = ptr1;
        }
        else
        {
            newNode->next = (struct node *)malloc(sizeof(struct node));
            ptr1 = ptr;
            newNode = newNode->next;
            newNode->prev = ptr1;
        }

        ptr = ptr->next;
    } while (ptr != head);

    printf("\nDuplicate Doubly Linked list created.... Printing values of duplicate list . . . . .\n");

    do
    {
        printf("\n%d", ptr2->data);
        ptr2 = ptr2->next;
    } while (ptr2 != head);
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n List is empty.");
    }
    else
    {
        printf("\n Values in the list are: ");
        temp = head;
        do
        {
            printf("\n %d", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
void countList()
{
    struct node *temp;
    int count = 0;
    if (head == NULL)
    {
        printf("\n List is empty.");
    }
    else
    {

        temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        printf("\n Number of node in list are: %d\n", count);
    }
}
void createTwoList()
{
    struct node *ptr1, *ptr2, *a, *b, *p, *ptr3, *ptr4;
    int n, i;
    printf("Enter number of elements in list 1: ");
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
            p->prev = a;
            ptr2 = a;
        }
        else
        {
            ptr1->next = p;
            p->next = a;
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
        if (b == NULL)
        {
            b = p;
            p->prev = p;
            p->next = p;
            ptr4 = b;
        }
        else
        {
            ptr3->next = p;
            p->next = b;
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
    ptr = a;
    ptr1 = b;

    do
    {
        ptr = ptr->next;
    } while (ptr->next != a);
   
    ptr->next = ptr1;
    ptr1->prev = ptr;

    do
    {
        ptr1 = ptr1->next;
    } while (ptr1->next != b);

    a->prev = ptr1;
    ptr1->next = a;
}

void reverse_list()
{
    struct node *current, *temp;

    current = head;
    do
    {
        /*
         * Swap the previous and next address fields of current node
         */
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        /* Move the current pointer to next node which is stored in temp */
        current = temp;
    } while (current != head);

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
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        if (head->data == item)
        {
            printf("item found at location %d", i + 1);
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    printf("item found at location %d ", i + 1);
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            printf("Item not found\n");
        }
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
        for (current = head; current->next != head; current = current->next)
        {
            //Index will point to node next to current
            for (index = current->next; index != head; index = index->next)
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
    fp = fopen("CircularDoublyLinkedListFile.txt", "w");
    do
    {
        fprintf(fp, "\n%d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
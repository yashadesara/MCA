#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *link;
};
void create(struct node **, int, int);
void display(struct node *);
void poly_add(struct node **, struct node **, struct node **);
void poly_mul(struct node **, struct node **, struct node **);
void printFile();

void main()
{

    struct node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *poly4 = NULL;
    int i, n, c, e;
    printf("Enter first polynomial!\n");
    printf("Enter no of terms:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%d", &c);
        printf("Enter exponent: ");
        scanf("%d", &e);
        create(&poly1, c, e);
    }
    printf("Enter second polynomial!\n");
    printf("Enter no of terms:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%d", &c);
        printf("Enter exponent: ");
        scanf("%d", &e);
        create(&poly2, c, e);
    }
    printf("First polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);

    poly_add(&poly1, &poly2, &poly3);
    printf("Sum of two polynomial:\n");
    display(poly3);

    //poly3 = NULL;
    poly_mul(&poly1, &poly2, &poly4);
    printf("Multiplication of the two polynomial:\n");
    display(poly4);

    printFile(poly3, poly4);
    getch();
}
void create(struct node **start, int c, int e)
{
    struct node *temp, *temp1, *prev;
    if (*start == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
            printf("Node is not created, Term cannot be inserted\n");
        else
        {
            temp->coef = c;
            temp->exp = e;
            temp->link = NULL;
            *start = temp;
        }
    }
    else
    {
        temp1 = *start;
        while (temp1 != NULL && temp1->exp > e)
        {
            prev = temp1;
            temp1 = temp1->link;
        }
        if (temp1 == NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            if (temp == NULL)
                printf("Node is not created\n");
            else
            {
                temp->coef = c;
                temp->exp = e;
                temp->link = NULL;
                prev->link = temp;
            }
        }
        else
        {
            if (temp1->exp == e)
                temp1->coef = temp1->coef + c;
            else
            {
                if (temp1 == *start)
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    if (temp == NULL)
                        printf("Node is not created\n");
                    else
                    {
                        temp->coef = c;
                        temp->exp = e;
                        temp->link = *start;
                        *start = temp;
                    }
                }
                else
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    if (temp == NULL)
                        printf("Node is not created\n");
                    else
                    {
                        temp->coef = c;
                        temp->exp = e;
                        temp->link = temp1;
                        prev->link = temp;
                    }
                }
            }
        }
    }
}
void display(struct node *start)
{
    struct node *temp;
    temp = start;
    if (temp == NULL)
        printf("Empty polynomial\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d x^%d", temp->coef, temp->exp);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
void poly_add(struct node **poly1, struct node **poly2, struct node **poly3)
{
    int c, e;
    struct node *pptr, *qptr;
    *poly3 = NULL;
    pptr = *poly1;
    qptr = *poly2;
    while (pptr != NULL && qptr != NULL)
    {
        if (pptr->exp == qptr->exp)
        {
            c = pptr->coef + qptr->coef;
            e = pptr->exp;
            create(poly3, c, e);
            pptr = pptr->link;
            qptr = qptr->link;
        }
        else
        {
            if (pptr->exp > qptr->exp)
            {
                c = pptr->coef;
                e = pptr->exp;
                create(poly3, c, e);
                pptr = pptr->link;
            }
            else
            {
                c = qptr->coef;
                e = qptr->exp;
                create(poly3, c, e);
                qptr = qptr->link;
            }
        }
    }
    while (pptr != NULL)
    {
        c = pptr->coef;
        e = pptr->exp;
        create(poly3, c, e);
        pptr = pptr->link;
    }
    while (qptr != NULL)
    {
        c = qptr->coef;
        e = qptr->exp;
        create(poly3, c, e);
        qptr = qptr->link;
    }
}
void poly_mul(struct node **poly1, struct node **poly2, struct node **poly3)
{
    int c, e;
    struct node *pptr, *qptr;
    *poly3 = NULL;
    pptr = *poly1;
    qptr = *poly2;
    if (*poly1 == NULL && *poly2 == NULL)
        printf("\nMultiplication of polynomial is not possible!\n");
    else
    {
        while (pptr != NULL)
        {
            qptr = *poly2;
            while (qptr != NULL)
            {
                c = pptr->coef * qptr->coef;
                e = pptr->exp + qptr->exp;
                create(poly3, c, e);
                qptr = qptr->link;
            }
            pptr = pptr->link;
        }
    }
}
void printFile(struct node *start1, struct node *start2)
{
    FILE *fp;
    int i;
    struct node *temp;
    temp = start1;
    fp = fopen("Link_File.txt", "w");
    while (temp != NULL)
    {
        fprintf(fp, "%d x^%d", temp->coef, temp->exp);
        temp = temp->link;
        if (temp != NULL)
            fprintf(fp, " + ");
        else
            fprintf(fp, "\n");
    }
    temp=NULL;
    temp = start2;
    while (temp != NULL)
    {
        fprintf(fp, "%d x^%d", temp->coef, temp->exp);
        temp = temp->link;
        if (temp != NULL)
            fprintf(fp, " + ");
        else
            fprintf(fp, "\n");
    }
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
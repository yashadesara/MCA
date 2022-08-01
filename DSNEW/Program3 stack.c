#include <stdio.h>
#define Size 10

int Push();
int Pop();
void show();
int peek();
struct stack_op
{
    int Top;
    int inp_array[Size];
};
int isFull(int Top)
{
    return Top == Size - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(int Top)
{
    return Top == -1;
}
void printFile(int arr[10], int n)
{
    FILE *fp;
    int i;
    fp = fopen("Stack.txt", "w");
    for (i = 0; i < n+1; i++)
        fprintf(fp, "%d", arr[i]);
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
int main()
{
    struct stack_op s;
    s.Top = -1;
    int choice;
    int element;
    
    while (choice != 5)
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Peek\n5.Print File and End");
        printf("\n\nEnter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            s.Top = Push(s.inp_array, s.Top);
            break;
        case 2:
            s.Top = Pop(s.inp_array, s.Top);
            break;
        case 3:
            show(s.inp_array, s.Top);
            break;
        case 4:
            element = peek(s.inp_array, s.Top);
            printf("\nPeeked element or element at top of stack is: %d", element);
            break;
        case 5:
            printFile(s.inp_array, s.Top);
            printf("\nExiting.....");
            break;
        default:
            printf("\nInvalid choice!!");
        }
    }
}

int Push(int inp_array[10], int Top)
{
    int x;

    if (isFull(Top))
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter element to be inserted to the stack:");
        scanf("%d", &x);
        Top = Top + 1;
        inp_array[Top] = x;
        printf("\nElement inserted. Top=%d", Top);
    }
    return Top;
}

int Pop(int inp_array[10], int Top)
{
    if (isEmpty(Top))
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element:  %d", inp_array[Top]);
        Top = Top - 1;
    }
    return Top;
}

void show(int inp_array[10], int Top)
{

	int i;
    if (isEmpty(Top))
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (i = Top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}
int peek(int inp_array[10], int top)
{
    if (isEmpty(top))
    {
        printf("Underflow");
        return 0;
    }
    else
    {
        return inp_array[top];
    }
}

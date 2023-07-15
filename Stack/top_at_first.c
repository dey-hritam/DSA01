#include <stdio.h>
#include <stdlib.h>
#define max 4
int stack[max];
int first = -1;
void push(int);
int pop();
void print();
int isfull();
int isempty();
int peek();
int main(void)
{
    int data, ch, i, n;
    while (1)
    {
        printf("\n");
        printf("1. push \n ");
        printf("2. pop \n ");
        printf("3. print the top element \n ");
        printf("4. print all the elements of the stack \n ");
        printf("5. Quit \n ");
        printf("please enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no of element you want to push:");
            scanf("%d", &n);
            printf("Enter the element to push:");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                push(data);
            }
            break;
        case 2:
            printf("Enter the no of element you want to pop:");
            scanf("%d", &n);
            printf("deleted elements are:");
            for (i = 0; i < n; i++)
            {
                data = pop();
                printf(" %d \n", data);
            }
            break;
        case 3:
            printf("the topmost element is :%d \n", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice!");
        }
    }
}
void push(int val)
{
    if (isfull())
    {
        printf("Stack is overflowed!");
        return;
    }
    int i;
    first = first + 1;
    for (i = first; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[0] = val;
}
int isfull()
{
    if (first == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    if (isempty())
    {
        printf("Stack is underflowed!");
        exit(1);
    }
    int i, data;
    data = stack[0];
    for (i = 0; i < first; i++)
    {
        stack[i] = stack[i + 1];
    }
    first = first - 1;
    return data;
}
int isempty()
{
    if (first == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek()
{
    if (isempty())
    {
        printf("stack is underflowed!");
        exit(1);
    }
    return stack[0];
}
void print()
{
    int i;
    if (first == -1)
    {
        printf("stack is undreflowed!");
        return;
    }
    for (i = 0; i <= first; i++)
    {
        printf("%d \n", stack[i]);
    }
}

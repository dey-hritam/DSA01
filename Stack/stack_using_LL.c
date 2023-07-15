// stack using linkedlist
#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
    int data;
    struct nodes *link;
} Node;
Node *push(Node *, int);
void print(Node *);
Node *pop(Node *);
int isempty(Node *);
int peek(Node *);
int main(void)
{
    Node *top = NULL;
    Node *temp = NULL;
    int val, ch, i, n;
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
                scanf("%d", &val);
                top = push(top, val);
            }
            break;
        case 2:
            printf("Enter the no of element you want to pop:");
            scanf("%d", &n);
            printf("deleted elements are:");
            for (i = 0; i < n; i++)
            {
                temp = pop(top);
                top = temp->link;
                printf("\n deleted elements are %d:", temp->data);
            }
            break;
        case 3:
            printf("the topmost element is :%d \n", peek(top));
            break;
        case 4:
            print(top);
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice!");
        }
    }
}
Node *push(Node *top, int val)
{
    Node *newnode;
    newnode = malloc(sizeof(newnode));
    if (newnode == NULL)
    {
        printf("stack is overflowed");
        exit(1);
    }
    newnode->data = val;
    newnode->link = NULL;

    newnode->link = top;
    top = newnode;
    return top;
}
void print(Node *top)
{
    Node *temp;
    temp = top;
    printf("Stacks elements are:\n");
    while (temp)
    {
        printf("%d \n", temp->data);
        temp = temp->link;
    }
}
Node *pop(Node *top)
{
    Node *temp;
    if (isempty(top))
    {
        printf("Stack is underflowed");
        exit(1);
    }
    temp = top;
    top = top->link;
    return temp;
}
int isempty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek(Node *top)
{
    int val;
    if (isempty(top))
    {
        printf("stack is underflowed");
        exit(1);
    }
    val = top->data;
    return val;
}
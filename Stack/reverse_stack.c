#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
    int data;
    struct nodes *link;
} Node;
void push(Node **, int);
int pop(Node **);
void print(Node **);
int main(void)
{
    Node *top = NULL, *top1 = NULL, *top2 = NULL;
    int n, val, i, data;
    printf("Enter the no of element you want to push:");
    scanf("%d", &n);
    printf("Enter the element to push:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        push(&top, val);
    }
    print(&top);
    // for create original stack
    for (i = 0; i < n; i++)
    {
        data = pop(&top);
        push(&top1, data);
    } // for push the elements to the stack1 to stack2
    for (i = 0; i < n; i++)
    {
        data = pop(&top1);
        push(&top2, data);
    } // for push the element in stack2
    for (i = 0; i < n; i++)
    {
        data = pop(&top2);
        push(&top, data);
    } // for push the element in original stack
    print(&top);
}
void push(Node **top1, int val)
{
    Node *newnode = NULL;
    newnode = malloc(sizeof(newnode));
    if (newnode == NULL)
    {
        printf("stack is overflowed");
        return;
    }
    newnode->data = val;
    newnode->link = NULL;

    newnode->link = *top1;
    *top1 = newnode;
}
int pop(Node **top)
{
    Node *temp = NULL;
    int val;
    temp = *top;
    val = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return val;
}
void print(Node **top)
{
    Node *temp;
    temp = *top;
    printf("Stacks elements are:\n");
    while (temp)
    {
        printf("%d \n", temp->data);
        temp = temp->link;
    }
}
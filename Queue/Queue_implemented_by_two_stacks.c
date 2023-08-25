// Queue_implemented_by_two_stacks

#include <stdio.h>
#include <stdlib.h>

#define max 100
int top = -1;
int s1[max], s2[max];

void push(int);
int isfull();
int pops1();
int pops2();
int isempty();
void display();

int main()
{
    int n, i, val;
    printf("Enter the number of elements you want to insert:");
    scanf("%d", &n);
    printf("Enter data:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        push(val);
    }
    for (i = 0; i < n; i++)
    {
        s2[i] = pops1();
    }
    printf("Enter the no of element you want to delete:");
    scanf("%d", &n);
    printf("deleted elements are:\n");
    for (i = 0; i < n; i++)
    {
        val = pops2();
        printf(" %d \n", val);
    }
    display();
    return 0;
}

void push(int val)
{
    if (isfull())
    {
        printf("Queue is overflowed!");
        return;
    }
    top = top + 1;
    s1[top] = val;
}

int isfull()
{
    if (top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pops1()
{
    int data;
    if (isempty())
    {
        printf("Queue is underflowed!");
        exit(1);
    }
    data = s1[top];
    top = top - 1;
    return data;
}

int pops2()
{
    int data;
    if (isempty())
    {
        printf("Queue is underflowed!");
        exit(1);
    }
    data = s2[top];
    top = top - 1;
    return data;
    push(s2[top]);
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    if (isempty())
    {
        printf("Queue is underflowed!");
        exit(1);
    }
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("\n %d", s1[i]);
    }
}
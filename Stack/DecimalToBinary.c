#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack[max];
int top = -1;
void push(int);
int pop();
void print();
int isfull();
int isempty();
int dec2bin(int);
int main(void)
{
    int n;
    printf("Enter the number:");
    scanf("%d", &n);
    dec2bin(n);
    return 0;
}
int dec2bin(int n)
{
    while (n != 0)
    {
        push(n % 2);
        n = n / 2;
    }
    printf("Binary number is:\n");
    while (top != -1)
    {
        printf("%d", pop());
    }
}
void push(int n)
{
    if (isfull())
    {
        printf("stack is overflowed");
        return;
    }
    top = top + 1;
    stack[top] = n;
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
int pop()
{
    int data;
    if (isempty())
    {
        printf("stack is underflow!");
        exit(1);
    }
    data = stack[top];
    top = top - 1;
    return data;
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
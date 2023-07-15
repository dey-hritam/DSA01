#include <stdio.h>
#include <stdlib.h>
void ispalindrome();
void push(int);
int pop();
int isempty();
int isfull();
int top = -1;
#define max 10
char s[max];
int main(void)
{
    printf("Enter the string:");
    scanf("%s", s);
    ispalindrome();
    return 0;
}
void ispalindrome()
{
    int i = 0;
    while (s[i] != 'X')
    {
        push(s[i]);
        i++;
    }
    i++;
    while (s[i])
    {
        while (isempty() || s[i] != pop())
        {
            printf("string is non palindrome");
            return;
        }
        i++;
    }
    printf("number is palindrome");
}
void push(int n)
{
    if (isfull())
    {
        printf("stack is overflowed");
        return;
    }
    top = top + 1;
    s[top] = n;
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
    data = s[top];
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
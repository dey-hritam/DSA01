#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

int top = -1;
char stack[max];
void push(char);
int isfull();
int pop();
int isempty();

int check_balance(char *);
int match_char(char, char);
int main()
{
    int balance;
    char exp[max];
    printf("Enter the expression:");
    gets(exp);
    balance = check_balance(exp);
    if (balance == 1)
    {
        printf("The expression is valid");
    }
    else
    {
        printf("expression is not valid");
    }
    return 0;
}
void push(char a)
{
    if (isfull())
    {
        printf("stack is overflowed");
        return;
    }
    top = top + 1;
    stack[top] = a;
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
int check_balance(char *s)
{
    int i;
    char temp;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            push(s[i]);
        }
        if (s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if (isempty())
            {
                printf("right brackets are more than left brackets so the expression is invalid!\n");
                return 0;
            }
            else
            {
                temp = pop();
                if (!match_char(temp, s[i]))
                {
                    printf("expression is invalid!\n");
                    return 0;
                }
            }
        }
    }
    if (isempty())
    {
        printf("brackets are well arranged\n");
        return 1;
    }
    else
    {
        printf("left brackets are more than right brackets so the expression is inavalid!\n");
        return 0;
    }
}
int match_char(char a, char b)
{
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}
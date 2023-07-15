#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
char stack[max], infix[max], postfix[max];
int top = -1;

void push(char);
int isfull();
int pop();
int isempty();
void print();

void inTopos(char *);
int precedence(char);
int space(char);

int main(void)
{
    printf("Enter the infix expression:");
    gets(infix);
    inTopos(infix);
    print();
}

void inTopos(char *s)
{
    int i;
    char symbol, next, j = 0;
    for (i = 0; i < strlen(s); i++)
    {
        symbol = s[i];
        // if symbol is whitespace.
        if (!space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while (next == pop() != '(')
                {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isempty() && precedence(stack[top]) > precedence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
}

int space(char symbol)
{
    if (symbol == ' ' || symbol == '\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    char data;
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
void print()
{
    int i = 0;
    while (postfix != '\0')
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

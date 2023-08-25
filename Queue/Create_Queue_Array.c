#include <stdio.h>
#include <stdlib.h>

#define max 100
int Q[max];
int rear = -1;

void insert(int);
int delete ();
void display();
int isfull();
int isempty();
int peek();

int main(void)
{
    int data, ch, i, n;
    while (1)
    {
        printf("\n");
        printf("1.Insert \n ");
        printf("2.Delete \n ");
        printf("3.print the top element \n ");
        printf("4.print all the elements in the queue \n ");
        printf("5.Quit \n ");
        printf("please enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no of element you want to insert:");
            scanf("%d", &n);
            printf("Enter the element to insert:");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                insert(data);
            }
            break;
        case 2:
            printf("Enter the no of element you want to delete:");
            scanf("%d", &n);
            printf("deleted elements are:");
            for (i = 0; i < n; i++)
            {
                data = delete ();
                printf(" %d \n", data);
            }
            break;
        case 3:
            printf("the topmost element is :%d \n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice!");
        }
    }
}
void insert(int n)
{
    if (isfull())
    {
        printf("Queue is overflowed");
        return;
    }
    rear = rear + 1;
    Q[rear] = n;
}
int isfull()
{
    if (rear == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int delete ()
{
    int data, i;
    if (isempty())
    {
        printf("Queue is underflow!");
        exit(1);
    }
    data = Q[0];
    for (i = 0; i < rear; i++)
    {
        Q[i] = Q[i + 1];
    }
    rear = rear - 1;
    return data;
}
int isempty()
{
    if (rear == -1)
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
        printf("Queue is underflowed!");
        exit(1);
    }
    return Q[0];
}
void display()
{
    int i;
    if (rear == -1)
    {
        printf("Queue is overflowed");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        printf("\n %d", Q[i]);
    }
}

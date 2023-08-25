#include <stdio.h>
#include <stdlib.h>

#define max 5
int Q[max];
int front = -1, rear = -1;

void enqueue_front(int, int);
void enqueue_rear(int, int);
int dequeue_front(int);
int dequeue_rear(int);
int peek();
void display();
int isfull(int);
int isempty();

int main(void)
{
    int ch, data, i, n;
    while (1)
    {
        printf(" 1.enqueue_front\n ");
        printf("2.enqueue_rear\n ");
        printf("3.dequeue_front\n ");
        printf("4.dequeue_rear\n ");
        printf("5.peek\n");
        printf(" 6.display\n");
        printf(" 7.Quit\n ");
        printf("please enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no of element you want to insert at front:");
            scanf("%d", &n);
            printf("Enter the element to insert:");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                enqueue_front(data, n);
            }
            break;
        case 2:
            printf("Enter the no of element you want to insert at rear:");
            scanf("%d", &n);
            printf("Enter the element to insert:");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                enqueue_rear(data, n);
            }
            break;
        case 3:
            printf("Enter the no of element you want to delete from front:");
            scanf("%d", &n);
            printf("deleted elements are:");
            for (i = 0; i < n; i++)
            {
                data = dequeue_front(n);
                printf(" %d \n", data);
            }
            break;
        case 4:
            printf("Enter the no of element you want to delete from rear:");
            scanf("%d", &n);
            printf("deleted elements are:");
            for (i = 0; i < n; i++)
            {
                data = dequeue_rear(n);
                printf(" %d \n", data);
            }
            break;
        case 5:
            printf("the topmost element is :%d \n", peek());
            break;
        case 6:
            display(max);
            break;
        case 7:
            exit(1);
        default:
            printf("Invalid choice!");
        }
    }
}
void enqueue_front(int data, int n)
{
    if (isfull(n))
    {
        printf("Queue is overflowed!");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Q[front] = data;
    }
    else if (front == 0)
    {
        front = n - 1;
        Q[front] = data;
    }
    else
    {
        front--;
        Q[front] = data;
    }
}
void enqueue_rear(int data, int n)
{
    if (isfull(n))
    {
        printf("Queue is overflowed!");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Q[rear] = data;
    }
    else if (rear == n - 1)
    {
        rear = 0;
        Q[rear] = data;
    }
    else
    {
        rear++;
        Q[rear] = data;
    }
}
int isfull(int n)
{
    if ((rear + 1) % n == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeue_front(int n)
{
    int data, i;
    if (isempty())
    {
        printf("Queue is underflowed!");
        exit(1);
    }
    else if (front == rear)
    {
        data = Q[front];
        front = -1;
        rear = -1;
    }
    else if (front == n - 1)
    {
        data = Q[front];
        front = 0;
    }
    else
    {
        data = Q[front];
        front = front + 1;
    }
    return data;
}
int dequeue_rear(int n)
{
    int data, i;
    if (isempty())
    {
        printf("Queue is underflowed!");
        exit(1);
    }
    else if (front == rear)
    {
        data = Q[rear];
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        data = Q[rear];
        rear = n - 1;
    }
    else
    {
        data = Q[rear];
        rear = rear - 1;
    }
    return data;
}

int isempty()
{
    if (front == -1)
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
        printf("Stack is empty!");
        exit(1);
    }
    int data;
    data = Q[front];
}

void display()
{
    int i = front;
    printf("elements are:\n");
    while (i != rear)
    {
        printf("%d", Q[i]);
        i = (i + 1) % n;
    }
    printf("%d", Q[rear]);
}
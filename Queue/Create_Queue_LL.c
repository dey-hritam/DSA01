#include <stdio.h>
#include <stdlib.h>

struct nodes
{
    int data;
    struct nodes *link;
};

struct nodes *enqueue(struct nodes **, struct nodes **);
struct nodes *dequeue(struct nodes **, struct nodes **);
void peek(struct nodes *front);
void display(struct nodes *front);

int main(void)
{
    int ch;
    struct nodes *front = NULL, *rear = NULL;
    printf("\n 1.enter the elements in queue \n 2.delete elements from queue  \n 3.peek element of the stack \n 4.display \n 5.Exit\n");
    while (1)
    {
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&front, &rear);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            peek(front);
            break;
        case 4:
            display(front);
            break;
        case 5:
            exit(1);
        }
    }
}

struct nodes *enqueue(struct nodes **front, struct nodes **rear)
{
    int i, n, val;
    struct nodes *newnode;
    newnode = (struct nodes *)malloc(sizeof(struct nodes));
    printf("Enter the number of new nodes you want to create:");
    scanf("%d", &n);
    printf("Enter the data for node[1]:");
    scanf("%d", &val);
    newnode->data = val;
    newnode->link = NULL;
    if (*front == NULL)
    {
        *front = newnode;
        *rear = newnode;
    }
    for (i = 2; i <= n; i++)
    {
        struct nodes *current;
        current = (struct nodes *)malloc(sizeof(struct nodes));
        printf("Enter the data for node[%d]:", i);
        scanf("%d", &val);
        current->data = val;
        current->link = NULL;
        (*rear)->link = current;
        *rear = current;
    }
}

struct nodes *dequeue(struct nodes **front, struct nodes **rear)
{
    int i, n;
    if (*front == NULL)
    {
        printf("Queue is already empty!");
        exit(1);
    }
    struct nodes *temp = NULL;
    printf("Enter the number of nodes you want to delete:");
    scanf("%d", &n);
    printf("deleted elements are:");
    for (i = 0; i < n; i++)
    {
        temp = *front;
        *front = (*front)->link;
        temp->link = NULL;
        printf("%d  ", temp->data);
        free(temp);
    }
    printf("\n");
}

void peek(struct nodes *front)
{
    if (front == NULL)
    {
        printf("Queue is empty!");
        exit(1);
    }
    printf("Peek element of the queue is : %d \n", front->data);
}

void display(struct nodes *front)
{
    struct nodes *temp = NULL;
    temp = front;
    printf("Queue is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
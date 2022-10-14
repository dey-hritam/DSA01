#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void create_node(int n)
{
    int i, val1, val2;
    struct node *head = NULL, *temp = NULL, *current = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Enter data for  node[0]:");
        scanf("%d", &val1);
        head->data = val1;
        head->link = NULL;
        temp = head;
        for (i = 1; i < n; i++)
        {
            current = (struct node *)malloc(sizeof(struct node));
            if (current == NULL)
            {
                printf("Memory is not allocated");
                break;
            }
            else
            {
                printf("Enter data for node[%d]:", i);
                scanf("%d", &val2);
                current->data = val2;
                current->link = NULL;
                temp->link = current;
                temp = temp->link;
            }
        }
    }
    insert_node(n, head);
}
void insert_node(int n, struct node *head)
{
    int val, key;
    struct node *temp = NULL, *newp = NULL;
    newp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for new nodes:");
    scanf("%d", &val);
    temp = head;
    if (newp == NULL)
    {
        printf("Memory is not allocated!");
    }
    else
    {
        newp->data = val;
        newp->link = NULL;
        key = newp->data;
        if (head == NULL && key < head->data)
        {
            newp->link = head;
            head = newp;
        }
        while (temp->link != NULL && temp->link->data < key)
        {
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }

    display_node(head);
}
void display_node(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->link;
        }
    }
}
int main(void)
{
    int n;
    printf("Enter the number of nodes you want to create:");
    scanf("%d", &n);
    create_node(n);
}
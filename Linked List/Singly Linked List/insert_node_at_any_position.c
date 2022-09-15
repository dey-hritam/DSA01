// insertion nodes at any position......

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
    int val, pos;
    struct node *ptr = NULL, *temp = NULL;
    if (head == NULL)
    {
        printf("memory is not allocated");
    }
    else
    {
        ptr = head;
        printf("Enter the position you want to insert the node:");
        scanf("%d", &pos);
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory is not allocated");
        }
        else
        {
            printf("Enter value for node:");
            scanf("%d", &val);
            temp->data = val;
            temp->link = NULL;
            pos--;
            while (pos != 1)
            {
                ptr = ptr->link;
                pos--;
            }
            temp->link = ptr->link;
            ptr->link = temp;
        }
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
/*
output:
Enter the number of nodes you want to create:3
Enter data for  node[0]:1
Enter data for node[1]:2
Enter data for node[2]:3
Enter the position you want to insert the node:3
Enter value for node:2
1  2  2  3
*/
// delete node at any position...
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} * head;
void intput_nodes(int);
void delete_node();
void display();
int main()
{
    int n;
    printf("Enter the number of nodes you want to create:");
    scanf("%d", &n);
    input_nodes(n);
    return 0;
}
void input_nodes(int n)
{
    int val1, val2, i;
    struct node *ptr = NULL, *current = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {

        printf("Enter the value for node[0]:");
        scanf("%d", &val1);
        head->data = val1;
        head->link = NULL;
        ptr = head;
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
                printf("Enter the value for node[%d]:", i);
                scanf("%d", &val2);
                current->data = val2;
                current->link = NULL;
                ptr->link = current;
                ptr = ptr->link;
            }
        }
    }
    delete_node();
}
void delete_node()
{
    int pos;
    if (head == NULL)
    {
        printf("Linked lsist is empty");
    }
    else
    {
        printf("Enter the position of the node you want to delete:");
        scanf("%d", &pos);
        struct node *temp1 = NULL, *temp2 = NULL;
        temp1 = head;
        temp2 = head;
        if (pos < 1)
        {
            printf("postion is invalid!");
        }
        else if (pos == 1)
        {
            head = temp1->link;
            free(temp1);
            temp1 = NULL;
        }
        else
        {
            while (pos > 1)
            {
                temp2 = temp1;
                temp1 = temp1->link;
                pos--;
            }
            temp2->link = temp1->link;
            free(temp1);
            temp1 = NULL;
        }
    }
    display();
}
void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
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
/*
output:
Enter the number of nodes you want to create:3
Enter the value for node[0]:1
Enter the value for node[1]:2
Enter the value for node[2]:3
Enter the position of the node you want to delete:2
1  3
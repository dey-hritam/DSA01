// delete last node
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} * head;
input_nodes(int n)
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
    if (head == NULL)
    {
        printf("Linked lsist is empty");
    }
    else
    {
        struct node *ptr1 = NULL, *ptr2 = NULL;
        ptr1 = head;
        ptr2 = head;
        while (ptr1->link != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->link;
        }
        ptr2->link = NULL;
        free(ptr1);
        ptr1 = NULL;
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
int main()
{
    int n;
    printf("Enter the number of nodes you want to create:");
    scanf("%d", &n);
    input_nodes(n);
    return 0;
}
/*
Enter the number of nodes you want to create:3
Enter the value for node[0]:1
Enter the value for node[1]:2
Enter the value for node[2]:3
1  2
*/
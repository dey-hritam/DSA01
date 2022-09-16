//reverse the linked_list.....
#include <stdio.h>
#include <stdlib.h>
struct nodes
{
    int data;
    struct nodes *link;
} * head;
void create_list(int n)
{
    int val1, val2, i;
    head = (struct nodes *)malloc(sizeof(struct nodes));
    struct nodes *temp = NULL, *ptr = NULL;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Enter data for node[0]:");
        scanf("%d", &val1);
        head->data = val1;
        head->link = val2;
        temp = head;
        for (i = 1; i < n; i++)
        {
            ptr = (struct nodes *)malloc(sizeof(struct nodes));
            if (ptr == NULL)
            {
                printf("Linked list is empty");
            }
            else
            {
                printf("Enter data for node[%d]:", i);
                scanf("%d", &val2);
                ptr->data = val2;
                ptr->link = NULL;
                temp->link = ptr;
                temp = temp->link;
            }
        }
    }
    reverse_list();
}
void reverse_list()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        struct nodes *temp1 = NULL, *temp2 = NULL;
        while (head->link != NULL)
        {
            temp2 = head->link;
            head->link = temp1;
            temp1 = head;
            head = temp2;
        }
        head->link = temp1;
    }
    display_list();
}
display_list()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        struct nodes *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}
int main(void)
{
    int n;
    printf("Enter the range of the list:");
    scanf("%d", &n);
    create_list(n);
}
/*
output:
Enter the range of the list:4
Enter data for node[0]:1
Enter data for node[1]:2
Enter data for node[2]:3
Enter data for node[3]:4
4 3 2 1
*/

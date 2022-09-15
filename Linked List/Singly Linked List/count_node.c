// write a c programme to count no of nodes in a linkedlist....

#include <stdio.h>
#include <stdlib.h>
struct nodes
{
    int data;
    struct node *link;
} *head = NULL;
void create_node()
{
    printf("\nCreating Linked list......");
    printf("\nfor end enter -1");
    int val1, val2, i;
    head = (struct nodes *)malloc(sizeof(struct nodes));
    struct nodes *temp = NULL, *ptr = NULL;
    if (head == NULL)
    {
        printf("Linked list is empty!");
    }
    else
    {
        printf("\nEnter data for node[0]:");
        scanf("%d", &val1);
        if (val1 != -1)
        {
            head->data = val1;
            head->link = NULL;
            ptr = head;

            for (i = 1;; i++)
            {
                temp = (struct nodes *)malloc(sizeof(struct nodes));
                if (temp == NULL)
                {
                    printf("Memory is not allocated!");
                }
                else
                {
                    printf("Enter data for node[%d]:", i);
                    scanf("%d", &val2);
                    if (val2 != -1)
                    {
                        temp->data = val2;
                        temp->link = NULL;
                        ptr->link = temp;
                        ptr = ptr->link;
                    }
                    else
                        break;
                }
            }
        }
    }
    display_ll();
    count_nodes();
}
void count_nodes()
{
    int count = 0;
    struct nodes *ptr = NULL;
    ptr = head;
    if (head == NULL)
    {
        printf("count=0");
    }
    else
    {
        while (ptr != NULL)
        {
            count = count + 1;
            ptr = ptr->link;
        }
    }
    printf("\nnumber of nodes are:%d", count);
}
void display_ll()
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
int main()
{
    create_node();
    return 0;
}
/* output:

Creating Linked list......
for end enter -1
Enter data for node[0]:2
Enter data for node[1]:3
Enter data for node[2]:4
Enter data for node[3]:-1
2 3 4
number of nodes are:3
*/
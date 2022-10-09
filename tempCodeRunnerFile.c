#include <stdio.h>
#include <stdlib.h>
struct nodes
{
    struct nodes *prev;
    int data;
    struct nodes *next;
} *head = NULL;
void create_doubly_ll(int n)
{
    int val1, val2, i;
    head = (struct nodes *)malloc(sizeof(struct nodes));
    struct nodes *temp = NULL, *ptr = NULL;
    if (head == NULL)
    {
        printf("Mmemory has not allocated!");
    }
    else
    {
        printf("Enter data for node[0]:");
        scanf("%d", &val1);
        head->prev = NULL;
        head->data = val1;
        head->next = NULL;
        ptr = head;
        for (i = 1; i < n; i++)
        {
            temp = (struct nodes *)malloc(sizeof(struct nodes));
            if (temp == NULL)
            {
                printf("Mmemory has not allocated!");
            }
            else
            {
                printf("Enter data for node[%d]:", i);
                scanf("%d", &val2);
                temp->prev = NULL;
                temp->data = val2;
                temp->next = NULL;
                ptr->next = temp;
                temp->prev = ptr;
                ptr = ptr->next;
            }
        }
    }
    delete_ll();
}
void delete_ll()
{
    int val, i, p;
    struct nodes *ptr = NULL;
    if (head == NULL)
    {
        printf("memory is not allocated");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
        ptr = NULL;
    }
    display_ll();
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
            ptr = ptr->next;
        }
    }
}
int main(void)
{
    int n;
    printf("Enter the range:");
    scanf("%d", &n);
    create_doubly_ll(n);
}

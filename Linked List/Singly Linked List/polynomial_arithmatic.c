// Create a polynomial equation by c.....
#include <stdio.h>
#include <stdlib.h>

struct nodes
{
    float coeff;
    int expo;
    struct nodes *link;
};

void display(struct nodes *head)
{
    if (head == NULL)
    {
        printf("NO polynomial!");
        return;
    }
    printf("Polynomial Equation is\n");
    struct nodes *temp = head;
    while (temp != NULL)
    {
        printf("(%.1fx^%d)", temp->coeff, temp->expo);
        temp = temp->link;
        if (temp != NULL)
        {
            printf(" + ");
        }
    }
}

struct nodes *insert(struct nodes *head, float co, int ex)
{
    struct nodes *temp;
    struct nodes *newp = (struct nodes *)malloc(sizeof(struct nodes));
    newp->expo = ex;
    newp->coeff = co;

    if (head == NULL || ex > head->expo)
    {
        newp->link = head;
        head = newp;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo > ex)
        {
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}

struct nodes *create(struct nodes *head)
{
    float coeff;
    int i, expo, n;
    printf("\nEnter the number of terms:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the coefficient for node[%d]:", i + 1);
        scanf("%f", &coeff);

        printf("\nenter the exponent for node[%d]:", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

int main()
{
    struct nodes *head = NULL;
    printf("Enter the polynomial:-");
    head = create(head);
    display(head);
    return 0;
}
/*
output:-
Enter the polynomial:-
Enter the number of terms:5

Enter the coefficient for node[1]:1

enter the exponent for node[1]:2

Enter the coefficient for node[2]:3

enter the exponent for node[2]:4

Enter the coefficient for node[3]:5

enter the exponent for node[3]:6

Enter the coefficient for node[4]:7

enter the exponent for node[4]:8

Enter the coefficient for node[5]:9

enter the exponent for node[5]:10
Polynomial Equation is
(9.0x^10) + (7.0x^8) + (5.0x^6) + (3.0x^4) + (1.0x^2)
*/
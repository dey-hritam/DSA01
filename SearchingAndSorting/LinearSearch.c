//Find the given element using Linear Search method.
#include <stdio.h>
int main()
{
    int n, j = -1, i,t;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d",&a[i]);
    }
    printf("Enter the target element:");
    scanf("%d", &t);
    for (i = 0; i < n; i++)
    {
        if (a[i] == t)
        {
            j = j + 1;
        }
    }
    if (j != -1)
    {
        printf("number is found ");
    }
    else
    {
        printf("number is not found!");
    }
}
/* output::-
    
Enter a[0]:2

Enter a[1]:7

Enter a[2]:8

Enter a[3]:5
Enter the target element:5
number is found
*/

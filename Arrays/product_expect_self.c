// wap find the product of all elements in the array except the position where the loop itarated...
#include <stdio.h>
int main(void)
{
    int i, n, pro = 1, p, j;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:", n);
    // for input
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
    }
    printf("product of the numbers is:");
    for (i = 0; i < n; i++)
    {
        pro = (pro * a[i]);
    }
    for (i = 0; i < n; i++)
    {
        p = pro / a[i];
        printf("%d ", p);
    }

    return 0;
}
/*
output:
Enter the no of elements:4
Enter 4 elements:
Enter a[0]:3

Enter a[1]:4

Enter a[2]:1

Enter a[3]:2
product of the numbers is:8 6 24 12
*/
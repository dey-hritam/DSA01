/*
Given an integer array nums,
find a contiguous non-empty subarray within the array that has the largest product, and return the product.*/
#include <stdio.h>
int main(void)
{
    int i, n, current_pro = 1, maxpro = 1;
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
    // for finding maximum subarray
    for (i = 0; i < n; i++)
    {
        current_pro = current_pro * a[i];
        if (current_pro > maxpro)
        {
            maxpro = current_pro;
        }
        else
        {
            current_pro = 1;
        }
    }
    printf("maximum product is %d", maxpro);
    return 0;
}
/*Enter 6 elements:
Enter a[0]:1

Enter a[1]:2

Enter a[2]:-1

Enter a[3]:3

Enter a[4]:2

Enter a[5]:0
maximum product is 6
*/
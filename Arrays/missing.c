// find the missing integer between two integers.difference between missing and given integer should be 1....

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j, n, diff, temp;
    printf("Enter the size of an array:");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter %d elements in the array:", n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    // for sorting
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("sorted array is :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    // for find missing
    printf("\nmissing elements is:");
    for (i = 0; i < n; i++)
    {
        diff = a[i + 1] - a[i];
        if (diff > 1 && diff < 3)
        {
            printf("%d  ", a[i + 1] - 1);
        }
    }
    return 0;
}
/*output:
Enter the size of an array:4
Enter 4 elements in the array:
 Enter a[0]: 7

 Enter a[1]: 5

 Enter a[2]: 3

 Enter a[3]: 4
sorted array is :3 4 5 7
missing elements is:6
*/
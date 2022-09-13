#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j, n, k, temp;
    printf("Enter the size of an array:");
    scanf("%d", &n);
    int a[n], new_array[n];
    printf("Enter the kth largset number:");
    scanf("%d", &k);
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
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\n sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    // for finding kth largset number
    for (i = 0; i < n; i++)
    {
        if (k - i == 1)
        {
            printf("\n %dth largest element is :%d", k, a[i]);
            exit(0);
        }
    }

    return 0;
}

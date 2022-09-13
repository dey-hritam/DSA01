// rain water trapping
#include <stdio.h>
int main(void)
{
    int n, i, j, left, right, sum = 0;
    printf("Enter the no of blocks:");
    scanf("%d", &n);
    int a[n], b[n], c[n], temp[n], t[n], d[n];
    printf("Enter the height of %d blocks:", n);
    // for input
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
        temp[i] = a[i];
        t[i] = a[i];
    }
    // for left
    printf("\nacording to left maximum numbers of wall is:");
    left = a[0];
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
        if (left < a[i + 1])
        {
            left = a[i + 1];
        }
        else if (left > a[i + 1])
        {
            a[i + 1] = left;
        }
        printf("%d ", b[i]);
    }
    // for right
    printf("\nacording to right maximum numbers of wall is:");
    right = temp[n - 1];
    for (i = n - 1; i >= 0; i--)
    {
        c[i] = temp[i];
        if (right < temp[i - 1])
        {
            right = temp[i - 1];
        }
        else if (right > temp[i - 1])
        {
            temp[i - 1] = right;
        }
        printf("%d ", c[i]);
    }
    // for difference & sum
    printf("\n total no of water which is in trap:");
    for (i = 0; i < n; i++)
    {
        if (b[i] < c[i])
        {
            d[i] = b[i] - t[i];
        }
        else
        {
            d[i] = c[i] - t[i];
        }
        printf("%d ", d[i]);
        sum = sum + d[i];
    }
    printf("\nsum is: %d", sum);
    return 0;
}

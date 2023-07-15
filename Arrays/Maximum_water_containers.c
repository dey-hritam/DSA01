#include <stdio.h>
int maxArea(int *, int);
int main()
{
    int n, i, h, max;
    printf("Enter the number of pillers:");
    scanf("%d", &n);
    int height[n];
    printf("Enter the heights of the pillers:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter[%d]:", i);
        scanf("%d", &h);
    }
    max = maxArea(height, n);
    printf("Maximum area to contains most water is: %d ", max);
}

int maxArea(int height[], int heightSize)
{

    int left = 0, right = heightSize - 1, max = 0, current_max, min_h;
    int lh, rh;
    while (left < right)
    {
        lh = height[left];
        rh = height[right];
        if (lh > rh)
        {
            min_h = rh;
            rh--;
        }
        else
        {
            min_h = lh;
            lh++;
        }
        current_max = (right - left) * min_h;
        if (current_max > max)
        {
            max = current_max;
        }
    }
    return max;
}
#include <stdio.h>
int BinarySearch(int a[], int, int, int);
int main()
{
    int n, key, i, t, index;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements in sorted way:");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
    }
    printf("Enter the target:");
    scanf("%d", &t);
    index = BinarySearch(a, 0, n - 1, t);
    if (index == -1)
    {
        printf("Element is not found!");
    }
    else
    {
        printf("%d element found at %d index", t, index);
    }
}
int BinarySearch(int a[], int low, int high, int val)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == val)
        {
            return mid;
        }
        if (a[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
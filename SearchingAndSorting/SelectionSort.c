#include <stdio.h>
void SelectionSort(int a[], int);
int main()
{
    int n, i;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
    }
    SelectionSort(a, n);
    printf("\n Sorted Array is:");
    for (i = 0; i < n; i++)
    {
        printf("  %d", a[i]);
    }
}
void SelectionSort(int a[], int size)
{
    int i, j, swap, smallest;
    for (int i = 0; i < size - 1; i++)
    {
        smallest = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[smallest])
            {
                smallest = j;
            }
        }
        swap = a[smallest];
        a[smallest] = a[i];
        a[i] = swap;
    }
}
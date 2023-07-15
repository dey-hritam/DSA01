#include <stdio.h>
void QuickSort(int a[], int, int);
int partition(int a[], int, int);
int main()
{
    int n, i;
    printf("Enter the range of the Array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]:", i);
        scanf("%d", &a[i]);
    }
    QuickSort(a, 0, n - 1);
    printf("After sorting the array is:");
    for (i = 0; i < n; i++)
    {
        printf("  %d", a[i]);
    }
}
void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pividx = partition(a, low, high);
        QuickSort(a, low, pividx - 1);
        QuickSort(a, pividx + 1, high);
    }
}
int partition(int a[], int low, int high)
{
    int swap;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }
    i++;
    swap = a[i];
    a[i] = pivot;
    a[high] = swap;
    return i;
}
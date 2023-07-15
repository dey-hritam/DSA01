//Sort the given array using Quick sort method.

/* Time Complexity:-
        The average time complexity of quick sort is O(N log(N)).
        The derivation is based on the following notation: T(N) = Time Complexity of Quick Sort for input of size N.
        At each step, the input of size N is broken into two parts say J and N-J.
*/

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
    printf("Sorted array is:");
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
/* Output:-
Enter the range of the Array:4

Enter a[0]:7

Enter a[1]:2

Enter a[2]:5

Enter a[3]:10
Sorted array is:  2  5  7  10
*/

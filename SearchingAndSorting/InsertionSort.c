#include <stdio.h>
void insertionSort(int a[], int);
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
    insertionSort(a, n);
    printf("After sorting the array is:");
    for (i = 0; i < n; i++)
    {
        printf("  %d", a[i]);
    }
}
void insertionSort(int a[], int n)
{
    int i, j, curr;
    for (i = 0; i < n - 1; i++)
    {
        j = i - 1;
        curr = a[i];
        while (j >= 0 && curr < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
}
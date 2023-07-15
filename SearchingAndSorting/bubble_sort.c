//Sort the given array using Bubble sort method.

/*Time complexity:-
    Bubble Sort is an easy-to-implement, stable sorting algorithm with a time complexity of O(n²),
    in the average and worst cases – and O(n) in the best case.
*/

#include <stdio.h>
void bubble_sort(int a[], int);
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
    bubble_sort(a, n);
    printf("\n Sorted Array is:");
    for (i = 0; i < n; i++)
    {
        printf("  %d", a[i]);
    }
}
void bubble_sort(int a[], int size)
{
    int i, j, swap;
    for (int i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
            }
        }
    }
}
/* output:-
Enter the size of the array:4

Enter a[0]:5

Enter a[1]:9

Enter a[2]:2

Enter a[3]:8

 Sorted Array is:  2  5  8  9
*/

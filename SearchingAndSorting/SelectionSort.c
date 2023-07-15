//Sort the given Array using Selection Sort method.

/*Time Complexity:-
Time & Space Complexity of Selection Sort:-
Worst Case Time Complexity is: O(N2)
Average Case Time Complexity is: O(N2)
Best Case Time Complexity is: O(N2)
Space Complexity: O(1)
*/
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

/*Output:-
Enter the size of the array:4

Enter a[0]:5

Enter a[1]:9

Enter a[2]:2

Enter a[3]:8

 Sorted Array is:  2  5  8  9
*/

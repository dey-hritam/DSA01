//Sort the given array using insertion sort method

/* Time Complexity:-
    Complexity Analysis of Insertion Sort
    Therefore, the insertion sort algorithm encompasses a time complexity of O(n2) and a space complexity of O(1),
    because it necessitates some extra memory space for a key variable to perform swaps.
*/
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
    printf("Sorted array is:");
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
/*output:-
Enter the range of the Array:5

Enter a[0]:1

Enter a[1]:9

Enter a[2]:4

Enter a[3]:2

Enter a[4]:8
Sorted array is:  1  2  4  9  8 */

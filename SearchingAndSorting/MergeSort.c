//Sort the given array using merge sort.

/*Time Complexity:-
    Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation,
    T(n) = 2T(n/2) + O(n) The solution of the above recurrence is O(nLogn).*/


#include <stdio.h>
void Divide(int a[], int, int);
void Conqure(int a[], int, int, int);
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
    Divide(a, 0, n - 1);
    printf("After sorting the array is:");
    for (i = 0; i < n; i++)
    {
        printf("  %d", a[i]);
    }
}
void Divide(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    Divide(a, low, mid);
    Divide(a, mid + 1, high);
    Conqure(a, low, mid, high);
}
void Conqure(int a[], int low, int mid, int high)
{
    int merged[high - low + 1];
    int idx1 = low;
    int idx2 = mid + 1;
    int i = 0, j;
    while (idx1 <= mid && idx2 <= high)
    {
        if (a[idx1] <= a[idx2])
        {
            merged[i] = a[idx1];
            i++;
            idx1++;
        }
        else
        {
            merged[i] = a[idx2];
            i++;
            idx2++;
        }
    }
    while (idx1 <= mid)
    {
        merged[i] = a[idx1];
        i++;
        idx1++;
    }
    while (idx2 <= high)
    {
        merged[i] = a[idx2];
        i++;
        idx2++;
    }
    for (i = 0, j = low; i < high + 1; i++, j++)
    {
        a[j] = merged[i];
    }
}
/*output:-
Enter the range of the Array:5
    
Enter a[0]:6

Enter a[1]:8

Enter a[2]:9

Enter a[3]:5

Enter a[4]:2
Sorted array is:  2  5  6  8  9
*/

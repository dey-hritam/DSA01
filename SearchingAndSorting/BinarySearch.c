//Serach the given number using binary search method.

/*Time Complexity:-
    The time complexity of the binary search algorithm is O(log n). 
    The best-case time complexity would be O(1) when the central index would directly match the desired value, 
    Binary search worst case differs from that.
*/

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
        printf("element %d found at index no : %d", t, index);
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

//output:-

/*
Enter the size of the array:4

Enter the elements in sorted way:
Enter a[0]:1

Enter a[1]:5

Enter a[2]:9

Enter a[3]:2
Enter the target:9
element 9 found at index no : 2
*/

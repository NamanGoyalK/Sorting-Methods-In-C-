#include <iostream>
using namespace std;

// Partition function: Rearranges the array and returns the pivot index
int partition(int arr[], int start, int end)
{
    int pivot = arr[end]; // Choose the last element as the pivot
    int pos = start - 1;  // Initialize the position of the smaller element

    // Traverse the array and rearrange elements around the pivot
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            pos++;                  // Move the position of the smaller element
            swap(arr[pos], arr[j]); // Swap elements to maintain the order
        }
    }

    swap(arr[pos + 1], arr[end]); // Move the pivot to its correct position
    return pos + 1;               // Return the updated pivot index
}

// Recursive Quick Sort
void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(arr, start, end); // Get pivot index
        QuickSort(arr, start, pivotIndex - 1);       // Sort left subarray
        QuickSort(arr, pivotIndex + 1, end);         // Sort right subarray
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1); // Sort the entire array

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

const int FIRST_ELEMENT = 0;

// Merge two sorted subarrays into a single sorted array
void merge(int arr[], int first, int middle, int last)
{
    const int length1 = middle - first + 1;
    const int length2 = last - middle;

    int leftSubarray[length1];
    int rightSubarray[length2];

    // Populate leftSubarray and rightSubarray
    for (int i = 0; i < length1; i++)
    {
        leftSubarray[i] = arr[first + i];
    }
    for (int i = 0; i < length2; i++)
    {
        rightSubarray[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = first;

    // Merge the two Subarrays back into arr
    while (i < length1 && j < length2)
    {
        if (leftSubarray[i] < rightSubarray[j])
        {
            arr[k] = leftSubarray[i];
            i++;
        }
        else
        {
            arr[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from leftSubarray
    while (i < length1)
    {
        arr[k] = leftSubarray[i];
        i++;
        k++;
    }

    // Copy any remaining elements from rightSubarray
    while (j < length2)
    {
        arr[k] = rightSubarray[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort
void MergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int middle = (first + last) / 2;

        // Recursively sort the left and right halves
        MergeSort(arr, first, middle);
        MergeSort(arr, middle + 1, last);

        // Merge the sorted halves
        merge(arr, first, middle, last);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input. Please enter a positive number of elements." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, FIRST_ELEMENT, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

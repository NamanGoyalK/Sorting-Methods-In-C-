#include <iostream>

// Function to perform Counting Sort
void CountingSort(int input_array[], int size, int range)
{
    // Create an array to store the counts of each element
    int count_array[range + 1] = {0}; // Initialize with zeros

    // Count the occurrences of each element
    for (int i = 0; i < size; ++i)
    {
        count_array[input_array[i]]++;
    }

    // Reconstruct the sorted array
    int output_array[size];
    int output_index = 0;
    for (int i = 0; i <= range; ++i)
    {
        while (count_array[i] > 0)
        {
            output_array[output_index] = i;
            output_index++;
            count_array[i]--;
        }
    }

    // Print the sorted array
    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << output_array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Find the maximum value in the array
    int max_value = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }

    CountingSort(arr, n, max_value);

    return 0;
}

#include <iostream>

// Function to sort an array containing 0s, 1s, and 2s (Dutch National Flag problem)
void sort012(int a[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            // If the current element is 0, swap it with the element at 'low' index
            std::swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            // If the current element is 1, just move the 'mid' index forward
            mid++;
        }
        else
        {
            // If the current element is 2, swap it with the element at 'high' index
            std::swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    int a[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);

    // Call the sorting function
    sort012(a, n);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

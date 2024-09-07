#include <iostream>

void Swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void WaveSort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            Swap(arr, i, i - 1);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            Swap(arr, i, i + 1);
        }
    }
}

int main()
{
    int n;
    std::cout << "Please enter the number of elements:";
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    WaveSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
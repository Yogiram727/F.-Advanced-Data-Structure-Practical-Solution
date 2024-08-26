#include <iostream>
using namespace std;

int linearSearch(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        int first = 0, last = n - 1, middle;
        while (first <= last)
        {
            middle = first + (last - first) / 2;
            if (array[middle] == x)
            {
                return middle;
            }
            else
            {
                if (array[middle] > x)
                {
                    last = middle - 1;
                }
                else
                {
                    first = middle + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int array[5], n = 5, x = 16;

    cout << "Enter 5 elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    // int result = linearSearch(array, n, x);
    int result = binarySearch(array, n, x);
    if (result == -1)
    {
        cout << "Element Not Found";
    }
    else
    {
        cout << "Element is at index " << result << endl;
    }
    return 0;
}
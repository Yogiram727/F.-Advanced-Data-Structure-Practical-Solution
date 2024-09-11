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
    return -1;
}

int main()
{
    int array[5], x, n = 5, result;
    cout << "Enter 5 elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << endl;
    cout << "Enter the element to search" << endl;
    cin >> x;
    result = binarySearch(array, n, x);
    // result = linearSearch(array, n, x);
    if (result == -1)
    {
        cout << "Element is not in the array" << endl;
    }
    else
    {
        cout << "Element is at index: " << result << endl;
    }
    return 0;
}
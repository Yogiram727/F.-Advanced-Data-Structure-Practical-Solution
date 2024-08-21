#include <iostream>
using namespace std;

int binarySearch(int array[], int n, int x)
{
    int first = 0, last = n - 1, middle;

    // Loop until the search interval is empty
    while (first <= last)
    {
        middle = first + (last - first) / 2;

        if (array[middle] == x)
        {
            return middle;
        }
        else if (array[middle] < x)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return -1;
}

int main()
{
    int array[5];
    cout << "Enter 5 sorted elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    int x = 16;

    int result = binarySearch(array, 5, x);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}
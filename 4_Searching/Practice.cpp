#include <iostream>
using namespace std;

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
    int n = 5;
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    cout << endl;

    int x = 16;
    int result = binarySearch(array, n, x);

    if (result == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << result;
    }
    return 0;
}
#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arry[], int n, int x)
{
    int first = 0, last = n - 1, middle;
    while (first <= last)
    {
        middle = first + (last - first) / 2;
        if (arry[middle] == x)
        {
            return middle; // Element found
        }
        else if (arry[middle] < x)
        {
            first = middle + 1; // Search in the right half
        }
        else
        {
            last = middle - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

int main()
{
    int array[5];

    // Read array elements. Enter the elements 3 6 10 12 16
    /*If output is not seen and only passed is seen then click on compile and run button again*/

    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }

    int x = 16; // Target value to search for

    // Perform binary search
    int result = binarySearch(array, 5, x);

    if (result != -1)
    {
        cout << result << endl; // output
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}

/*Problem Statement

Write a program in C++ to implement iterative Binary search to print index location of data item 16 in the array of [3,6,10,12,16] elements.*/
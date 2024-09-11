#include <iostream>
using namespace std;

void bubbleSorting(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int main()
{
    int array[5], n = 5;
    cout << "Enter 5 element of array to be sorted" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    // bubbleSorting(array, n);
    selectionSort(array, n);
    cout << endl;
    cout << "Array after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
#include <iostream>
using namespace std;

// function to swap the position of two
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// function to print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            int min_idx = step;
            for (int i = step + 1; i < size; i++)
            {
                // To sort in descending order, change > to < in this line
                // Select the minimum element in each loop
                if (array[i] < array[min_idx])
                    min_idx = i;
            }
            // put min at the correct position
            swap(&array[min_idx], &array[step]);
        }
    }
}
int main()
{
    int data[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> data[i];
    }
    int size = 5;
    selectionSort(data, size);
    printArray(data, size);
}

/*Problem Statement

Write a program to implement selection sort to sort the array [45,13,112,150,116].*/
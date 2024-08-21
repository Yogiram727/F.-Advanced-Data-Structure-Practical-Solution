#include <iostream>
using namespace std;

int search(int array[], int n, int x)
{
    // Going through array sequentially
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int array[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    int x = 54;
    int n = 5;
    int result = search(array, n, x);
    if (result == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << result;
    }
    return 0;
}
#include <iostream>
using namespace std;

void checkPrime(int num)
{
    int count = 0;
    if (num < 2)
    {
        cout << "Number is not prime" << endl;
        return;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            count++;
            break;
        }
    }
    if (count > 0)
    {
        cout << "Number is not prime" << endl;
    }
    else
    {
        cout << "Number is prime" << endl;
    }
}

int main()
{
    int num;
    cout << "Enter any number to check prime" << endl;
    cin >> num;
    checkPrime(num);
    return 0;
}
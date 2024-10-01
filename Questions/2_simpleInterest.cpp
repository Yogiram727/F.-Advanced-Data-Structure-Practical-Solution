#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std;

int main()
{
    float principal, time, rate, simpleInterest;

    cout << "Enter principal amount: ";
    cin >> principal;

    cout << "Enter time in years: ";
    cin >> time;

    cout << "Enter rate of interest: ";
    cin >> rate;

    simpleInterest = (principal * time * rate) / 100;

    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "Simple Interest = " << simpleInterest << endl;

    return 0;
}

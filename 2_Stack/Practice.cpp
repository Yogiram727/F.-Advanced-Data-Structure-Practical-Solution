#include <iostream>
using namespace std;

int Stack[5], n = 5, top = -1;

void PUSH(int value)
{
    if (top == n - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        Stack[top] = value;
    }
}

void POP()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << Stack[i] << endl;
    }
    cout << endl;
}

int main()
{
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    PUSH(5);
    PUSH(6);
    cout << "Element of Stack" << endl;
    display();
    POP();
    POP();
    cout << "Stack after deletion" << endl;
    display();
    cout << endl;
    POP();
    POP();
    POP();
    cout << "Stack after Deletion of all" << endl;
    display();
}
#include <iostream>
using namespace std;

int top = -1, stack[5], n = 5;

void PUSH(int item)
{
    if (top == n - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

void POP()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
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
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}

int main()
{
    PUSH(10);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    cout << "Stack items" << endl;
    display();
    cout << endl;
    POP();
    POP();
    cout << "Stack after POP" << endl;
    display();
    cout << endl;
    POP();
    POP();
    POP();
    cout << "Stack after all POP" << endl;
    display();
    cout << endl;
    return 0;
}
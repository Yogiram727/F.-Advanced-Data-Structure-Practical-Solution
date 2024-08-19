#include <iostream>
using namespace std;

int Stack[5], n = 5, top = -1;

void PUSH(int new_item)
{
    if (top == n - 1)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        top = top + 1;
        Stack[top] = new_item;
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
        cout << "Top Element Deleted" << endl;
        top--;
    }
}

void DISPLAY()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack Elements are : " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << Stack[i] << endl;
        }
        cout << endl;
    }
}

int main()
{
    PUSH(4);
    PUSH(5);
    PUSH(6);
    PUSH(7);
    PUSH(8);
    PUSH(9);
    DISPLAY();
    POP();
    POP();
    POP();
    POP();
    POP();
    POP();
    DISPLAY();
}
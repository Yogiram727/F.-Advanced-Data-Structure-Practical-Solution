#include <iostream>
using namespace std;

int Stack[5], n = 5, top = -1;

void PUSH(int item)
{
    if (top >= n - 1)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        top = top + 1;
        Stack[top] = item;
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
        for (int i = top; i >= 0; i--)
        {
            cout << "Stack Elements are : " << Stack[i] << endl;
        }
    }
}

int main()
{
    PUSH(10);
    PUSH(20);
    PUSH(30);
    PUSH(40);
    PUSH(50);
    PUSH(60);
    DISPLAY();
    POP();
    POP();
    POP();
    POP();
    POP();
    POP();
    POP();
    DISPLAY();

    return 0;
}
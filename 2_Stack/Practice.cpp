#include <iostream>
using namespace std;

int stack[5], n = 5, top = -1;

void push(int value)
{
    if (top == n - 1)
    {
        cout << "Stack is Full" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    top--;
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}

int main()
{
    int value;
    cout << "Enter any 5 item in the stack" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        push(value);
    }

    cout << "Given stack" << endl;
    display();
    pop();
    pop();
    cout << "Stack after partial deletion" << endl;
    display();
    return 0;
}
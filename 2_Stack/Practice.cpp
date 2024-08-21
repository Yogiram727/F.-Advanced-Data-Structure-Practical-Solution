#include <iostream>
using namespace std;

int stack[5], n = 5, top = -1;

void push(int value)
{
    if (top >= n - 1)
    {
        cout << "Stack Overflow" << endl;
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
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    cout << "Stack elements are " << endl;
    display();
    pop();
    pop();
    pop();
    cout << "Stack elements after pop" << endl;
    display();
    push(10);
    cout << "Stack elements at the end" << endl;
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    return 0;
}
#include <iostream>
using namespace std;

int stack[5], n = 5, top = -1;

void push(int item)
{
    if (top == n - 1)
    {
        cout << "Stack is full" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
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
        cout << "Stack is empty" << endl;
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
    push(10);
    push(20);
    push(3);
    push(50);
    cout << "Stack before deletion" << endl;
    display();
    pop();
    pop();
    cout << endl;
    cout << "Stack after deletion" << endl;
    display();
    return 0;
}
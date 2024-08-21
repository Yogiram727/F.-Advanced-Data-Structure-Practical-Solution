#include <iostream>
using namespace std;

#define MAX 100 // Define maximum size of stack

class Stack
{
    int arr[MAX]; // Array to store stack elements
    int top;      // Index of the top element in the stack

public:
    // Constructor to initialize the stack
    Stack() : top(-1) {}

    // Method to push an element onto the stack
    void push(int value)
    {
        if (top >= MAX - 1)
        {
            return; // Stack overflow, do nothing
        }
        arr[++top] = value;
    }

    // Method to pop an element from the stack
    void pop()
    {
        if (top < 0)
        {
            return; // Stack underflow, do nothing
        }
        top--; // Remove the top element
    }

    // Method to display all elements of the stack
    void display() const
    {
        if (top < 0)
        {
            return; // Stack is empty, do nothing
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i];
            if (i > 0)
            {
                cout << " "; // Print space between elements
            }
        }
        cout << endl;
    }
};

int main()
{
    Stack stack; // Create a stack object

    // Perform stack operations
    stack.push(5);
    stack.push(10);
    stack.push(8);
    stack.pop();
    stack.push(12);
    stack.push(15);
    stack.push(23);
    stack.pop();
    stack.push(27);

    // Display all existing items in the stack
    stack.display();

    return 0;
}

/*Problem Statement

Write a program to implement STACK using array and perform operations in following sequence: - PUSH(5), PUSH(10), PUSH(8), POP, PUSH(12), PUSH(15), PUSH(23), POP, PUSH(27), DISPLAY(). At the end display all existing items of STACK.

*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = nullptr;

void push(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

void display()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node *ptr = top;
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    push(10);
    push(2);
    push(3);
    cout << endl;
    display();
    cout << endl;
    pop();
    pop();
    display();
    cout << endl;
    pop();
    display();
    cout << endl;
    return 0;
}
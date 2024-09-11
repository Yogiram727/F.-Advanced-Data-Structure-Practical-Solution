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
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void display()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        Node *ptr = top;
        while (ptr != nullptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    cout << endl;
    cout << "Stack before deletion" << endl;
    display();
    cout << endl;
    cout << "Stack after deletion" << endl;
    pop();
    display();
    return 0;
}
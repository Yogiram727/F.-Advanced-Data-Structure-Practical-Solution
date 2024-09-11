#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = nullptr;

void push(int item)
{
    Node *new_node = new Node();
    new_node->data = item;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack is emtpy" << endl;
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
    cout << endl;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    cout << endl;
    cout << "Stack before deletion" << endl;
    display();
    cout << endl;
    pop();
    pop();
    pop();
    pop();
    pop();
    cout << "stack after deletion" << endl;
    display();
    return 0;
}
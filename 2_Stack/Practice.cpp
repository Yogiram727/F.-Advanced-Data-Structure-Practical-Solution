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
        cout << "Stack is empty" << endl;
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
    push(10);
    push(30);
    push(100);
    push(20);
    display();
    cout << endl;
    pop();
    pop();
    cout << "List after partial deletion" << endl;
    display();
    cout << endl;
    return 0;
}
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
    else
    {
        if (top->next == nullptr)
        {
            delete top;
            top = nullptr;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
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
    push(22);
    push(33);
    push(44);
    display();
    cout << endl;
    pop();
    pop();
    cout << "Stack after partial deletion" << endl;
    display();
    return 0;
}
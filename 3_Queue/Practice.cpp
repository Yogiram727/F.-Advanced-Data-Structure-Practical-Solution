#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

void push(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    if (front == nullptr)
    {
        rear = new_node;
        front = new_node;
        rear->next = front;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        rear->next = front;
    }
}

void pop()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        if (front == rear)
        {
            delete front;
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            rear->next = front;
        }
    }
}

void display()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        Node *ptr = front;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != front);
    }
}

int main()
{
    push(10);
    push(55);
    push(60);
    push(66);
    display();
    cout << endl;
    pop();
    pop();
    cout << " Queue after partial deletion" << endl;
    display();
    return 0;
}
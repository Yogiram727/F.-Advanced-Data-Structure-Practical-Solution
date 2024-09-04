#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *rear = nullptr;
Node *front = nullptr;

void enqueue(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    if (front == nullptr)
    {
        front = new_node;
        rear = new_node;
        rear->next = front;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        rear->next = front;
    }
}

void dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    else
    {
        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }
}

void display()
{
    if (front == nullptr)
    {
        cout << "Queue is Empty" << endl;
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(55);
    display();
    cout << endl;
    dequeue();
    dequeue();
    cout << "Queue after partial deletion" << endl;
    display();
    return 0;
}
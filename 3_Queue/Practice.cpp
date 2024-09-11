#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

void enqueue(int item)
{
    Node *new_node = new Node();
    new_node->data = item;
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
            rear->next = front;
            delete temp;
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
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(44);
    enqueue(55);
    enqueue(66);
    enqueue(77);
    cout << "Queue before deletion" << endl;
    display();
    cout << endl;

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    cout << "Queue after deletion" << endl;
    display();
}
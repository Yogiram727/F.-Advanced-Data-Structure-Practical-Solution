#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

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
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        if (rear == front)
        {
            delete front;
            rear = nullptr;
            front = nullptr;
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
        cout << "List is empty" << endl;
        return;
    }
    Node *ptr = front;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != front);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    cout << endl;
    dequeue();
    dequeue();
    cout << "List after partial deletion" << endl;
    display();
    return 0;
}
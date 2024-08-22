#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert(int value)
{
    struct Node *new_node = new Node();
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL)
    {
        front = new_node;
        rear = new_node;
        new_node->next = front;
    }

    else
    {
        rear->next = new_node; // current rear
        rear = new_node;       // update rear
        rear->next = front;    // new rear
    }
}

void Dequeue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else if (front == rear)
    {
        delete front;
        front = NULL;
        rear = NULL;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

void display()
{
    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else
    {
        struct Node *ptr = front;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != front);
        cout << endl;
    }
}

int main()
{
    insert(1);
    insert(20);
    insert(30);
    insert(40);
    cout << "Element in Queue" << endl;
    display();
    Dequeue();
    Dequeue();
    cout << "Element in Queue ater deletion" << endl;
    display();
    Dequeue();
    Dequeue();
    cout << "Element in Queue" << endl;
    display();
    cout << endl;
    return 0;
}
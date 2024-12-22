#include <iostream>
using namespace std;

int front = -1, rear = -1, queue[5], n = 5;

void enqueue(int value)
{
    if ((rear + 1) % n == front)
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % n;
    }
    queue[rear] = value;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % n;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    int i = front;
    while (i != rear)
    {
        cout << queue[i] << " ";
        i = (i + 1) % n;
    }
    cout << queue[rear] << endl;
}

int main()
{
    enqueue(10);
    enqueue(30);
    enqueue(40);
    enqueue(60);
    cout << "Given element of the queue" << endl;
    display();
    cout << "Queue after deletion of partial elements" << endl;
    dequeue();
    dequeue();
    display();
    cout << endl;
    cout << "Queue after deletion of all the element" << endl;
    dequeue();
    dequeue();
    display();
    cout << endl;
    return 0;
}
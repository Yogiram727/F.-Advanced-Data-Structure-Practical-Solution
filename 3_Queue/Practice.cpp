#include <iostream>
using namespace std;

int queue[5], n = 5, front = -1, rear = -1;

void insert(int value)
{
    if ((rear + 1) % n == front)
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    else
    {
        if (front == -1)
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
}

void Dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else
    {
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
}

void display()
{
    if (front == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else
    {
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < n; i++)
            {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    cout << "Queue after insertion" << endl;
    display();
    Dequeue();
    Dequeue();
    Dequeue();
    cout << "Queue after partial deletion" << endl;
    display();
    Dequeue();
    Dequeue();
    Dequeue();
    cout << "Queue after fully deletion" << endl;
    display();
    cout << endl;
    return 0;
}
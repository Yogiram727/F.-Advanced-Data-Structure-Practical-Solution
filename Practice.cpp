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

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
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
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            int i = front;
            do
            {
                cout << queue[i] << " ";
                i = (i + 1) % n;
            } while ((rear + 1) % n != i);
            // for (int i = front; i < n; i++)
            // {
            //     cout << queue[i] << " ";
            // }
            // for (int i = 0; i <= rear; i++)
            // {

            //     cout << queue[i] << " ";
            // }
        }
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    cout << "Queue before deletion" << endl;
    display();
    cout << endl;
    cout << "Queue after deletion" << endl;
    dequeue();
    dequeue();
    display();
    return 0;
}
#include <iostream>
using namespace std;

int queue[5], n = 5, front = -1, rear = -1;

void insert(int val)
{
    if ((rear == front - 1) || ((rear == n - 1) && (front == 0)))
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = val;
        }
        else if ((front != 0) && (rear == n - 1))
        {
            rear = 0;
            queue[rear] = val;
        }
        else
        {
            rear++;
            queue[rear] = val;
        }
    }
}

void Delete()
{
    if ((rear == -1) && (front == -1))
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else if (front == rear)
    {
        cout << "Element deleted is : " << queue[rear] << endl;
        front = -1;
        rear = -1;
    }
}
#include <iostream>
using namespace std;

int rear = -1, front = -1, queue[5], n = 5;

void insert(int val)
{
    if ((rear == front - 1 || (front == 0 && front == n - 1)))
    {
        cout << "Queue OverFlow" << endl;
    }
    else
    {
        if (front == -1 || rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = val;
        }
        else if (front != 0 && rear == n - 1)
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
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow";
        return;
    }
    else if (front == rear)
    {
        cout << "Element delete from queue is :" << queue[front] << endl;
        front = -1;
        rear = -1;
    }
    else if (front == n - 1)
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front = 0;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
    }
}

void Display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else if (rear >= front)
    {
        cout << "Front= " << front << " and Rear = " << rear << endl;
        cout << "Queue elements are : outside " << endl;
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "Front= " << front << "and Rear = " << rear << endl;
        cout << "Queue elements aer : Inside " << endl;
        for (int i = front; i < n; i++)
        {
            cout << queue[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << queue[i] << " ";
            cout << endl;
        }
    }
}
int main()
{
    insert(10);
    Display();
}
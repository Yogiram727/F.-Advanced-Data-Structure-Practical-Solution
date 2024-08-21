#include <iostream>
using namespace std;

int queue[5], n = 5, front = -1, rear = -1;

void insert(int val)
{
    if ((rear + 1) % n == front)
    {
        cout << "Queue is Full" << endl;
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
        queue[rear] = val;
    }
}

void Delete()
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
    }
    else
    {
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
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
            cout << endl;
        }
    }
}

int main()
{
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(10);
    display();
    Delete();
    Delete();
    Delete();
    Delete();
    display();
    Delete();
    Delete();
    display();
    insert(9);
    insert(10);
    display();
}
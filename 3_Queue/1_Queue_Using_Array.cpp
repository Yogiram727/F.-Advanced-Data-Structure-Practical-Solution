#include <iostream>
using namespace std;

int queue[5], n = 5, front = -1, rear = -1;

void insert(int val)
{
    if ((rear + 1) % n == front)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        if (front == -1) // Queue is empty
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
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Element deleted is : " << queue[front] << endl;

    if (front == rear) // Queue has only one element
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

    cout << "Rear = " << rear << " Front = " << front << endl;

    if (rear >= front)
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
    cout << endl;
}

int main()
{
    cout << "Inserting elements into the queue: " << endl;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Queue after insert: " << endl;
    display();

    cout << "Deleting an element from the queue:" << endl;
    Delete();

    cout << "Queue after one delete: " << endl;
    display();

    cout << "Inserting more elements into the queue: " << endl;
    insert(60);
    insert(70);

    cout << "Queue after additional inserts: " << endl;
    display();

    cout << "Deleting all elements from the queue: " << endl;
    Delete();
    Delete();
    Delete();
    Delete();
    Delete();

    cout << "Queue after deleting all elements: " << endl;
    display();

    return 0;
}

#include <iostream>
using namespace std;

#define MAX 100 // Define maximum size of queue

class Queue
{
    int arr[MAX]; // Array to store queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int size;     // Number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue() : front(0), rear(-1), size(0) {}

    // Method to insert an element into the queue
    void insert(int value)
    {
        if (size >= MAX)
        {
            return; // Queue is full, do nothing
        }
        rear = (rear + 1) % MAX; // Move rear to next position
        arr[rear] = value;
        size++;
    }

    // Method to delete an element from the queue
    void deleteElement()
    {
        if (size <= 0)
        {
            return; // Queue is empty, do nothing
        }
        front = (front + 1) % MAX; // Move front to next position
        size--;
    }

    // Method to display all elements of the queue
    void display() const
    {
        if (size <= 0)
        {
            return; // Queue is empty, do nothing
        }
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << arr[i];
            if (count < size - 1)
            {
                cout << " "; // Print space between elements
            }
            i = (i + 1) % MAX; // Move to next element
        }
        cout << endl;
    }
};

int main()
{
    Queue queue; // Create a queue object

    // Perform queue operations
    queue.insert(15);
    queue.insert(40);
    queue.insert(38);
    queue.deleteElement();
    queue.insert(82);
    queue.insert(65);
    queue.insert(43);
    queue.deleteElement();
    queue.insert(87);

    // Display all existing items in the queue
    queue.display();

    return 0;
}

/*

Problem Statement
Write a program to implement a Queue using an array and perform operations in the following sequence:

INSERT(15)
INSERT(40)
INSERT(38)
DELETE
INSERT(82)
INSERT(65)
INSERT(43)
DELETE
INSERT(87)
DISPLAY()
*/
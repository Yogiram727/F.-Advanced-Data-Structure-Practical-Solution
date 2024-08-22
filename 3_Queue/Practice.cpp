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
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (front == NULL)
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

void Delete()
{
    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else if (front == rear)
    {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    struct Node *ptr = front;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != front);
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
    cout << endl;
    Delete();
    Delete();
    display();
    cout << endl;
    Delete();
    Delete();
    cout << endl;
    display();
    cout << endl;
    return 0;
}
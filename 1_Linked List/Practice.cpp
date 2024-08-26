#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *head = nullptr;

void insertAtBeginning(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = NULL;
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    Node *last = nullptr;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;
}

void insertAfter(int prev, int value)
{
    Node *current = head;
    while (current != nullptr && current->data != prev)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Can't find the node" << endl;
        return;
    }
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
}

void delStart()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void delEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *last = head;
    Node *second_last = nullptr;
    while (last->next != nullptr)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = nullptr;
    delete last;
}

void display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int value, prev, newValue;
    cout << "Enter 5 element to insert in the list " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertAtBeginning(value);
        // insertAtEnd(value);
    }

    display();

    cout << endl;
    cout << "Enter after which node you want to insert the new value" << endl;
    cin >> prev;
    cout << endl;
    cout << "Enter the value that you want to insert" << endl;
    cin >> newValue;
    insertAfter(prev, newValue);
    cout << endl;
    cout << "List after insertion" << endl;
    display();
    return 0;
}
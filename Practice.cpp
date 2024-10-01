#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void insertFirst(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insertLast(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    Node *last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;
}

void insertAfter(int prev, int new_value)
{
    Node *current = head;
    while (current != nullptr && current->data != prev)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Given element not found" << "\n";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_value;
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
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
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
    cout << endl;
}

int main()
{
    int value, prev, new_value;
    cout << "Enter any 5 element to enter in list" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertFirst(value);
        // insertLast(value);
    }
    cout << endl;
    display();
    cout << endl;
    cout << "Enter after which node you want to insert the new value" << endl;
    cin >> prev;
    cout << endl;
    cout << "Enter the new Value that you want to insert" << endl;
    cin >> new_value;
    insertAfter(prev, new_value);
    cout << endl;
    cout << "List after insertion" << endl;
    display();
    cout << "list after deletion of first element" << endl;
    delStart();
    display();
    cout << endl;
    cout << "List after deletion of last element" << endl;
    delEnd();
    display();
    cout << endl;
    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = nullptr;

void insertAtFirst(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insertAtLast(int value)
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

void insertAfter(int prev, int value)
{
    Node *current = head;
    while (current != nullptr && current->data != prev)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Element not found" << endl;
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
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void delEnd()
{
    if (head == nullptr)
    {

        cout << "List is empty" << endl;
        return;
    }
    else
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
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
    }
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
    cout << "Enter 5 element to insert in the list" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertAtFirst(value);
        // insertAtLast(value);
    }
    cout << endl;
    cout << "List after insertion " << endl;
    display();
    cout << endl;
    cout << "Enter the value after which you want to insert a new value" << endl;
    cin >> prev;
    cout << endl;
    cout << "Enter the new value that you want to insert" << endl;
    cin >> new_value;
    insertAfter(prev, new_value);
    cout << endl;
    cout << "List after insertion" << endl;
    display();
    cout << endl;
    cout << "List after deletion of the first element" << endl;
    delStart();
    display();
    cout << endl;
    cout << "List after deletion of the last element" << endl;
    delEnd();
    display();
    return 0;
}
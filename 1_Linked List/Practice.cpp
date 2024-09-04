#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    else
    {
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

void insertAfter(int prev, int value)
{
    Node *current = head;
    while (current != nullptr && current->data != prev)
    {
        current = current->next;
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
        Node *last = head;
        Node *secondLast = nullptr;
        while (last->next != nullptr)
        {
            secondLast = last;
            last = last->next;
        }
        secondLast->next = nullptr;
        delete last;
    }
}

void display()
{
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
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        // insertAtBeginning(value);
        insertAtEnd(value);
    }
    display();
    cout << endl;
    cout << "Enter the node after which you want to insert" << endl;
    cin >> prev;
    cout << "Enter the vaue that you want to insert after that node" << endl;
    cin >> newValue;
    insertAfter(prev, newValue);
    cout << endl;
    cout << "List after insertion" << endl;
    display();
    delStart();
    cout << endl;
    display();
    cout << endl;
    delEnd();
    display();
    return 0;
}
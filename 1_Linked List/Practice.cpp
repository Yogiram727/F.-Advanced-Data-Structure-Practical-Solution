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
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertAfter(int prev, int newValue)
{
    Node *current = head;
    while (current != nullptr && current->data != prev)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Node not found" << endl;
        return;
    }
    Node *newNode = new Node();
    newNode->data = newValue;
    newNode->next = current->next;
    current->next = newNode;
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
    Node *secondLast = nullptr;
    while (last->next != nullptr)
    {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = nullptr;
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
    int value, newValue, prev;
    cout << "Enter any 5 value to insert into the list " << endl;
    ;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        // insertAtFirst(value);
        insertAtEnd(value);
    }
    cout << endl;
    cout << "Given List :" << endl;
    display();
    cout << endl;
    cout << "Enter the value after which you want to insert a node" << endl;
    cin >> prev;
    cout << endl;
    cout << "Enter the new value that you want to insert" << endl;
    cin >> newValue;
    insertAfter(prev, newValue);
    cout << "endl";
    cout << "List after insertion of the new Node" << endl;
    display();
    cout << endl;
    cout << "List after deletion of the first Node" << endl;
    delStart();
    display();
    cout << endl;
    cout << "List after deletion of the last Node" << endl;
    delEnd();
    display();
    cout << endl;
    return 0;
}

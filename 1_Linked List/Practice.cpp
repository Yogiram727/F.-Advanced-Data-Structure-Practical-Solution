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
    // Node *newNode = new Node();//
    Node *newNode = (Node *)malloc(sizeof(Node));
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

void insertAfter(int pre, int value)
{
    Node *current = head;
    while (current != nullptr && current->data != pre)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Node Not Found" << endl;
        return;
    }
    Node *newNode = new Node();
    newNode->data = value;
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
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int value;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        // insertAtBeginning(value);
        insertAtEnd(value);
    }
    display();
    delStart();
    cout << endl;
    display();
    delEnd();
    cout << endl;
    display();
    cout << endl;
    int prev, newValue;
    cout << "Enter the number after which you want to insert the value" << endl;
    cin >> prev;
    cout << endl;
    cout << "Enter the number that you want to insert" << endl;
    cin >> newValue;
    insertAfter(prev, newValue);
    cout << endl;
    display();
    return 0;
}
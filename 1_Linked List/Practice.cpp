#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

void insertAfter(int prev, int value)
{
    struct Node *current = head;
    while (current != NULL && current->data != prev)
    {
        current = current->next;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
}

void delStart()
{
    struct Node *temp = NULL;
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delEnd()
{

    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *last = head;
    struct Node *second_last = NULL;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    free(last);
}

void display()
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int value;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertAtBeginning(value);
        // insertAtEnd(value);
    }
    display();
    cout << endl;

    cout << "Given Linked List" << endl;
    display();
    cout << endl;
    int prev, new_value;
    cout << "Enter after which node you want to insert: " << endl;
    cin >> prev;
    cout << "Enter the value you want to insert" << endl;
    cin >> new_value;
    insertAfter(prev, new_value);
    cout << "After Insertion" << endl;
    display();
    cout << endl;
    delStart();
    display();
    cout << endl;
    delEnd();
    display();
    cout << endl;
    return 0;
}
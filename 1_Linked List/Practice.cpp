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

void insertAfterNode(int prev, int value)
{
    struct Node *current = head;
    while (current != NULL && current->data != prev)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "Data Not Found" << endl;
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delStart()
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    else
    {
        struct Node *temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delend()
{
    if (head == NULL)
    {
        cout << "Empty List " << endl;
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
    cout << "Given Linked List" << endl;
    display();
    cout << endl;
    int prev, new_value;

    cout << "Insert the value after which you want to insert the value: " << endl;
    cin >> prev;
    cout << endl;
    cout << "Insert the value that you want to insert" << endl;
    cin >> new_value;
    insertAfterNode(prev, new_value);
    cout << "Linked List after insertion of new value: " << endl;
    display();
    delend();
    cout << endl;
    display();
    delStart();
    cout << endl;
    display();
    return 0;
}
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
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
    // insertAtEnd(2);
    // insertAtEnd(3);
    // insertAtEnd(4);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    display();
    return 0;
}
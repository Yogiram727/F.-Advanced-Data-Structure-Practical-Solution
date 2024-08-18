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

void insertAfterNode(int value, int new_data)
{
    struct Node *current = head;
    while (current != NULL && current->data != value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "The Given Value Doesn't Exist" << endl;
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = current->next;
    current->next = new_node;
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
    int new_data;
    for (int i = 0; i < 5; i++)
    {
        cin >> new_data;
        insertAtBeginning(new_data);
        // insertAtEnd(new_data);
    }
    cout << "Current List: ";
    display();

    int value, new_value;
    cout << "Enter the value after which to insert: ";
    cin >> value;
    cout << "Enter the value to be insserted: ";
    cin >> new_value;
    insertAfterNode(value, new_value);

    cout << "Updated List: ";
    display();
}
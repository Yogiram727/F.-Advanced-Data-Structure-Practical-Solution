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

void display()
{
    struct Node *ptr;
    ptr = head;
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
    }
    display();
    return 0;
}

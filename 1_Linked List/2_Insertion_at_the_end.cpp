#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertAtEnd(int new_value)
{
    // struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *new_node = new Node(); // Use `new` instead of `malloc`
    new_node->data = new_value;
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
    int new_data;
    for (int i = 0; i < 5; i++)
    {
        cin >> new_data;
        insertAtEnd(new_data);
    }
    display();
    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

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

void deletionAtEnd()
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
    cout << "Given Data: " << endl;
    display();
    deletionAtEnd();
    cout << "After deletion at the end:" << endl;
    display();
    return 0;
}
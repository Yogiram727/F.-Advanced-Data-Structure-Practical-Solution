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

void deleteBeginning()
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
    cout << "Insert 5 data: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> new_data;
        insertAtBeginning(new_data);
    }
    cout << "Given Data: " << endl;
    display();
    cout << endl;
    cout << "After Deletion" << endl;
    deleteBeginning();
    display();
    deleteBeginning();
    display();
    deleteBeginning();
    display();
    deleteBeginning();
    display();
    deleteBeginning();
    display();
    deleteBeginning();
    display();
}

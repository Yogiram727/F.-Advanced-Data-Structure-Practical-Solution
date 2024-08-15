#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr; // Use nullptr instead of NULL

// Function to insert a new node at the beginning
void insertAtBeginning(int new_data)
{
    Node *new_node = new Node; // Use new instead of malloc
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

// Function to insert a new node at the end
void insertAtEnd(int new_data)
{
    Node *new_node = new Node; // Use new instead of malloc
    new_node->data = new_data;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

// Function to insert a new node after a given value
void insertAfterValue(int value, int new_data)
{
    Node *current = head;
    while (current != nullptr && current->data != value)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    Node *new_node = new Node; // Use new instead of malloc
    new_node->data = new_data;
    new_node->next = current->next;
    current->next = new_node;
}

// Function to display the linked list
void display()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " "; // Add space for readability
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int new_value;

    // Insert some initial values
    for (int i = 0; i < 5; i++)
    {
        cin >> new_value;
        insertAtBeginning(new_value);
    }

    // Display the list
    cout << "Current list: ";
    display();

    // Insert after a specific value
    int value, new_data;
    cout << "Enter the value after which to insert: ";
    cin >> value;
    cout << "Enter new value to insert: ";
    cin >> new_data;

    insertAfterValue(value, new_data);

    // Display the updated list
    cout << "Updated list: ";
    display();

    return 0;
}

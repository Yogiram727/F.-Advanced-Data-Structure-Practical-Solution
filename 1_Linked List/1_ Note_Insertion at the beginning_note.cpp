/*--------------------Linked List-----------------*/
/*Insertion at the Beginning*/

#include <iostream>  // Include the iostream library to use input and output functions
using namespace std; // Use the standard namespace

// Define the structure of a node in the linked list
struct Node
{
    int data;          // Store the data value of the node
    struct Node *next; // Pointer to the next node in the linked list
};

struct Node *head = NULL; // Initialize the head of the linked list to NULL

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    new_node->data = new_data;                                          // Set the data of the new node
    new_node->next = head;                                              // Make the new node point to the current head
    head = new_node;                                                    // Update the head to be the new node
}

// Function to display the linked list
void display()
{
    struct Node *ptr; // Create a pointer to traverse the linked list
    ptr = head;       // Start from the head of the linked list
    while (ptr != NULL)
    {                             // Traverse until the end of the linked list
        cout << ptr->data << " "; // Print the data of each node
        ptr = ptr->next;          // Move to the next node
    }
    cout << endl; // Print a new line at the end
}

int main()
{
    int value; // Variable to store input values
    // Insert five values at the beginning of the linked list
    for (int i = 0; i < 5; i++)
    {
        cin >> value;             // Read a value from the user
        insertAtBeginning(value); // Insert the value at the beginning
    }
    // Display the linked list
    display();
    return 0; // Return 0 to indicate successful execution
}

/*
Algorithm for Inserting a Node at the Beginning
1. Allocate Memory for the New Node
    -> Create a new node.

2. Set the Data of the New Node
    -> Assign the new data value to the data part of the new node.

3. Link the New Node to the Existing List
    -> Set the next pointer of the new node to the current head of the list.

4. Update the Head to Point to the New Node
    -> Update the head pointer to point to the new node.



          +-----------+      +-----------+      +-----------+
Head ---> |  data: 10 | ---> |  data: 20 | ---> |  data: 30 |
          |  next: ----+     |  next: ----+     |  next: NULL|
          +-----------+      +-----------+      +-----------+


          */

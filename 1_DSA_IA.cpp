#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insert(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void del()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        cout << "Underflow";
    }
    else
    {
        head = temp->next;
        free(temp);
    }
}

void lastinsert(int item)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    if (new_node == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        new_node->data = item;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = NULL;
        }
    }
}

void delend()
{
    struct Node *ptr1;
    if (head == NULL)
    {
        cout << "Underflow";
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
    }
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
}
int main()
{
    int ch;
    for (int i = 0; i < 5; i++)
    {
        cin >> ch;
        insert(ch);
    }
    // display();
    // del();
    // cout << "\n";
    // display();
    // delend();
    // cout << "\n";
    display();
    return 0;
}
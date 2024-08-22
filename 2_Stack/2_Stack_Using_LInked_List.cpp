#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
Node *top = NULL;

void PUSH(int item)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node *));
    new_node->data = item;
    new_node->next = top;
    top = new_node;
}

void POP()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << " Top Element Deleted: " << top->data << endl;
        struct Node *temp;
        temp = top;
        top = top->next;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        struct Node *ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main()
{
    PUSH(10);
    PUSH(20);
    PUSH(30);
    display();
    POP();
    POP();
    POP();

    display();
    return 0;
}
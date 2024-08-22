#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void PUSH(int item)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
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
        struct Node *temp = NULL;
        temp = top;
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    PUSH(10);
    PUSH(2);
    PUSH(3);
    PUSH(5);
    cout << "Stack item list: " << endl;
    display();
    cout << endl;
    POP();
    POP();
    cout << "Stack after POP: " << endl;
    display();
    cout << endl;
    POP();
    POP();
    POP();
    display();
    cout << endl;
    return 0;
}
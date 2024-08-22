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
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    struct Node *ptr = top;
    if (ptr == NULL)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

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
    PUSH(20);
    PUSH(50);
    PUSH(60);
    display();
    cout << endl;
    POP();
    POP();
    display();
    cout << endl;
    POP();
    POP();
    POP();
    display();
}
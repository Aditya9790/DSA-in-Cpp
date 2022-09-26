#include <iostream>
#include <vector>
using namespace std;
/*
Stack follows Last In First Out Principle (LIFO). main operations carried out in stack are :
1. Push : Add element to the stack.
2. Pop : The element that is added last is removed from stack
3. Peek or Top : Does not change the stack. Only returns the element that was lastly added.
4. isEmpty : Check whether stack is empty or not.

Time complexity of all operations in O(1) as no loops are involved.

To maintain time complexity of 1 we will always insert element in the beginning.
*/

// Stack using Linked List

class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *top = NULL;

StackNode *newNode(int data) // create a node
{
    StackNode *new_node = new StackNode();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void pushStack(StackNode *sn, int data)
{
    StackNode *currnode = newNode(data);
    if (top == NULL)           // if stack empty
        currnode->next = NULL; // point curr next to null
    else
        currnode->next = top;
    top = currnode;
}

int popStack(StackNode *sn)
{
    if (top == NULL)
        cout << "No element to pop" << endl;

    StackNode *temp = top; // temp variable to point to top
    top = temp->next;

    int a = temp->data; // store data of temp in a
    free(temp);         // free temp
    return a;
}

int peek(StackNode *sn)
{
    if (top == NULL)
        cout << "Empty Stack" << endl;
    else
        return top->data;
    return 0;
}

void printStack(StackNode *sn)
{
    if (top == NULL)
        cout << "Stack empty" << endl;

    StackNode *curr = top;

    while (curr->next != NULL)
    {
        cout << curr->data << "-->";
        curr = curr->next;
    }
    cout << curr->data << "-->NULL";
}

int main()
{
    StackNode sn;

    pushStack(&sn, 10);
    pushStack(&sn, 20);
    pushStack(&sn, 30);
    cout<<"\nTop element is :"<<peek(&sn)<<endl;

    printStack(&sn);
    cout << endl;
    popStack(&sn);
    printStack(&sn);
    return 0;
}
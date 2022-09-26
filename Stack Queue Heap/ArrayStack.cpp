#include <iostream>
using namespace std;

#define len 4 // macros
int stack[len];
int top = -1;
void push_stack(int data)
{
    if (top == len - 1)
        cout << "Stack Full" << endl;
    else
    {
        top++;
        stack[top] = data;
    }
}

void pop()
{
    // int num;
    if (top == -1)
        cout << "Underflow" << endl;
    else
        top--;
}

int peek()
{
    if (top == -1)
        return 0;
    return stack[top];
}

void print_stack()
{
    for (int i = top; i >= 0 ; i--)
        cout << stack[i] << "-->";
}

int main()
{
    push_stack(10);
    push_stack(20);
    push_stack(30);
    push_stack(40);

    cout<<"\nbefore popping"<<endl;
    print_stack();

    cout<<"\nPeek"<<peek()<<endl;
    pop();
    pop();

    cout<<"after popping"<<endl;
    print_stack();
    return 0;
}
#include <iostream>
#define N 5
using namespace std;

int queue[N];
int front = -1, rear = -1;

void enqueue(int x)
{
    if(rear == N-1)
        cout<<"Overflow!! Cannot add element"<<endl;
    else if(rear == -1 && front == -1) // first element to add
    {
       rear = 0; front = 0;
       queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1) // queue empty
        cout<<"Underflow!! Queue Empty"<<endl;
    else if(rear == front) // only 1 element
    {
        rear = -1;front =-1;
    }
    else
    {
        cout<<"Dequeued element is :"<<queue[front]<<endl;
        front++; // increment front
    }
}

int peek()
{
    return queue[front]; // return front
}

void display()
{
    for(int i=front;i<=rear;i++)
        cout<<queue[i]<<"-->";
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    cout<<"\nTop element is : "<<peek()<<endl;
    cout<<endl;
    cout<<"Queue is :";
    cout<<endl;
    display();
    cout<<endl;

    dequeue();
    cout<<"Top element is : "<<peek()<<endl;

    cout<<endl;
    cout<<"Queue is :";
    cout<<endl;
    display();
    cout<<endl;
    
    
    return 0;
}
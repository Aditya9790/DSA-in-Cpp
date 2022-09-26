/*
When implementing a queue with an array of fixed size, say we have added elements until the queue is full.
And now when we dequeue an element from a queue we increment the front to front+1 but while doing so the elements that are prior in the array i.e. from index 0 t0 front-1 now becomes a garbage value as we incremented the front.

After dequeuing when we try to enqueue an element the program returns Overflow condition as we have already used up all the space in the queue. But in reality the space from 0th index to (front-1)th index is available in the memory the only problem is since we increment front every time the program sees the array as ranging from front to rear.

And this leads to wastage of space. So to tackle this problem we will implement circular queue data structure.
*/

#include <iostream>
#define N 5
using namespace std;

int circle_queue[N];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        circle_queue[rear] = x;
    }
    else if ((rear + 1) % N == front) // condition for full queue
    {
        cout << "\nQueue is Full" << endl;
        return;
    }

    else
    {
        rear = (rear + 1) % N; // important
        circle_queue[rear] = x;
    }
}

void dequeue()
{
    if (rear == -1 && front == -1)
        cout << "\nUnderflow!! Empty queue" << endl;
    else if (rear == front) // only one element in queue
    {
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "\nDequeued element is :" << circle_queue[front] << endl;
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if (rear == -1 && front == -1)
        cout << "\nEmpty queue" << endl;
    else
    {
        cout << "Queue is :" << endl;
        while (i != rear)
        {
            cout << circle_queue[i] << "-->";
            i = (i + 1) % N;
        }
        cout<<circle_queue[rear]<<endl;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    enqueue(100); // cout<<"Add";
    display();
    return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
 
class Queue
{
    // Initialize front and rear
    int rear, front;
 
    // Circular Queue
    int size;
    int *arr;
public:
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }
 
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};
 
 
// Function to create Circular queue 
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        printf("\nQueue is Full");
        return;
    }
 
    else if (front == -1) // Insert First Element 
    {
        front = rear = 0;
        arr[rear] = value;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
 
    else
    {
        rear++;
        arr[rear] = value;
    }
}
 
// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }
 
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    return data;
}
 
// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

// Driver of the program 
int main()
{
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
 
    // Display elements present in Circular Queue
    q.displayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
 
    q.displayQueue();
 
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
 
    q.displayQueue();
 
    q.enQueue(20);
    return 0;
}
*/
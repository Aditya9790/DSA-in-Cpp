/*
We need to implement a stack such that along with regular push pop operations that can be performed in O(1) time we need to also perform operations these (push, pop) operations on middle element of stack in O(1) space.
*/

// We will use DLL for this
#include <iostream>
using namespace std;
class Stack
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int num) { this->data = num; }
    };

    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

    void push(int data)
    {
        Node *tem = new Node(data);
        if (size == 0) // if 1st element to be added
        {
            head = tem;
            mid = tem;
            size += 1;
            return;
        }

        head->next = tem;
        tem->prev = head;

        // update head
        head = head->next;
        if (size % 2 == 1)
            mid = mid->next;
        size += 1;
    }

    int pop()
    {
        int popped = -1;
        if (size > 0)
        {
            popped = head->data;
            // if there is only 1 element
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                Node *tem = head->prev;
                tem->next = NULL;
                head = tem;
                if (size % 2 == 0) // mid only change when size is even
                    mid = mid->prev;
            }
            size -= 1;
        }
        return popped;
    }

    int findMiddle()
    {
        if (size == 0)
            return -1;
        return mid->data;
    }

    void deleteMiddle()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                mid = mid->prev;
                head = head->prev;
                head->next = NULL;
            }
            else
            {
                Node *tem = mid->prev;
                tem->next = mid->next;
                mid->next->prev = tem;
                if (size % 2 == 1)
                    mid = mid->next;
                else
                    mid = mid->prev;
            }
            size -= 1;
        }
    }
};
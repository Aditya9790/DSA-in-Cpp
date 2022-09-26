#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s, int top)
{
    if(s.empty() || top > s.top())
    {
        s.push(top);
        return;
    }
    int upper = s.top();
    s.pop();
    insert(s, top);
    s.push(upper);
}

void sortStack(stack<int> &s)
{
    if(s.empty()) return;

    int top = s.top();
    s.pop();
    sortStack(s);
    insert(s, top);
}

int main()
{
    stack<int> s; //{50, 20, 0, 10};
    s.push(3);
    s.push(2);
    s.push(1);
    // s.push(2);
    sortStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
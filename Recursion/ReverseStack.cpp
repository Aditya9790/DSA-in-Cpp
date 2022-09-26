#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int tem)
{
    if (s.empty())
    {
        s.push(tem);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s, tem);
    s.push(top);
        
}

void reverse(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int top = s.top();
    s.pop();
    reverse(s);
    insert(s, top);
}

int main()
{
    stack<int> s;
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10); 

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
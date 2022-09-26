// Remove middle eloement of stack
#include<iostream>
# include<stack>
using namespace std;

void solve(stack<int>&s, int k)
{
    if(k == 1) {
        s.pop();
        return;
    }
    int tem= s.top();
    s.pop();
    solve(s, k-1);
    s.push(tem); // store last popped element
}
void middle(stack<int> &s, int size)
{
    // k is the index of element from top

    if(s.empty()) return;
    // base case

    int k = (size/2) + 1;
    solve(s, k);
    // return{};
}


int main()
{
    stack<int> s; //{50, 20, 0, 10};
    s.push(5);
    s.push(1);
    s.push(0);
    s.push(2); 

    middle(s, s.size());
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
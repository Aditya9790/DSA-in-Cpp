#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int checkpred(char op)
    {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return -1;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        stack<char> st;
        string res;

        for (int i = 0; i < s.length(); i++)
        {
            char temp = s[i];

            if (isdigit(temp) || isalpha(temp))
            {
                // cout<<temp<<endl;
                res += temp;
            }
            else if (temp == '(')
                st.push('(');
            else if (temp == ')')
            {
                while (st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && (checkpred(s[i]) <= checkpred(st.top())))
                {
                    if (temp == '^' && st.top() == '^')
                        break;
                    else
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                st.push(temp); // else push
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int  main()
{
    string exp;
    cin>>exp;
    Solution sol;
    cout<<"Postfix is: "<<sol.infixToPostfix(exp)<<endl;
    return 0;
}
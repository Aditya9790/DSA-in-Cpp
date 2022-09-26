/*
Given a set of positive integers, find all its subsets.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subset;
void solve(vector<int> A, vector<int> ans, int index)
{
    if (index == A.size())
    {
        subset.push_back(ans);
        return;
    }

    else
    {
        solve(A, ans, index + 1); // skip the curr emenent
        ans.push_back(A[index]);
        solve(A, ans, index + 1); // take curr elem in subset
    }
}
vector<vector<int>> subsets(vector<int> &A)
{
    // code here
    vector<int> ans;
    solve(A, ans, 0);
    sort(subset.begin(), subset.end());
    return subset;
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<vector<int>> ans;
    ans = subsets(a);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
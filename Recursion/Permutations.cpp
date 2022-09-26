#include <bits/stdc++.h>
using namespace std;

void perm(string S, unordered_set<string> &all_perm, int index)
{
    // base case
    // if we come at last index then push the result in vector
    if (index >= S.length())
    {
        all_perm.insert(S);
        return;
    }
    // swap current index with i and then again call the perm function
    // give chance to each element at each position
    for (int i = index; i < S.length(); i++)
    {
        swap(S[index], S[i]);
        perm(S, all_perm, index + 1);
        // again swap so as to revert back to original string
        // i.e. if initial string is abc
        // after completing 1st recursive call then index will point to
        // b and after performing recursive calls on b
        // then next time the index will point to c
        // this means every time we are calling recursion we are performing swapping operations on original string
        // to do so we need to undo the swap the we had made before callin grecursive function.
        swap(S[index], S[i]);
    }
}
vector<string> find_permutation(string S)
{
    // create set so that automatically all unique entries will be stored
    unordered_set<string> all_perm;
    perm(S, all_perm, 0);
    vector<string> ans;

    for (auto i : all_perm)
        ans.push_back(i);

    sort(ans.begin(), ans.end());

    return ans;
}
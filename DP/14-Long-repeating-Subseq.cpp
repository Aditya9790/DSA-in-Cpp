#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input: str = "aabb"
Output: "ab"

Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a'
(second). Note that 'b' cannot be considered
as part of subsequence as it would be at same
index in both.

Here we will find the LCS of a string with itself
But here we will check a additional condition that if s1[i-1] == s2[j-1] then i != j.

we will check i!=j condition because we need subsequences that occur at distince positions
ex : absdahbqs
Here we get "abs" at two diff positions.
*/

string long_rep_subseq(string s1, string s2)
{
    int m = s1.length();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

    // fill dp table
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j) // check condition i != j
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][m];
}

int main()
{
    string s = "axxzxy";
    cout << "LRS length: " << long_rep_subseq(s, s) << endl;
    return 0;
}
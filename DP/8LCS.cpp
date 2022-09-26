/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 

// m = s1.length(), n = s2.length()
/*
consider ex : s1 = adbeh s2 = adbph
if s1[m-1] ans s2[n-1] are eaual then in the LCS will fore surely contain h character so we increment count by 1.
ans call LCS by decreasing size of both strings by 1.

Now s1[m-2] = e && s2[n-1] = p
Here we have rwo choices either to take substring s1 from 0th index to m-2 index and compare it with s2
or vice versa

And since we need max length So we call LCS on both the above mentioned options and take the max of the both ans obtained

*/

// ------Recursive Approach--------------
int LCS(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0) // if either of 1 string length is 0 then LCS will be 0
        return 0;

    if (s1[m - 1] == s2[n - 1]) // if char match
        return 1 + LCS(s1, s2, m - 1, n - 1);

    return max(LCS(s1, s2, m - 1, n), LCS(s1, s2, m, n - 1));
}

// -----------Memoization or Bottom UP DP-------------

int memo(int m, int n, string s1, string s2, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + memo(m - 1, n - 1, s1, s2, dp);
    else
    {
        dp[m][n] = max(memo(m, n - 1, s1, s2, dp), memo(m - 1, n, s1, s2, dp));
        return dp[m][n];
    }
}

int LCS_memo(int m, int n, string s1, string s2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int memo_ans = memo(m, n, s1, s2, dp);
    return memo_ans;
}

// ---------------Top Down DP-------------------

int top_down(int m, int n, string s1, string s2, vector<vector<int>> &dp)
{
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // ans = max(ans, dp[i][j]);
                }
                
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int LCS_top_down(int m, int n, string s1, string s2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // we will fill dp table
    // all entries where dp[i][0] and dp[0][j] will be 0 where i and j range from 0 to n+1
    // we will do this because even length of one of the string is 0 the length of LCS will be 0

    // fill 1st column
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;

    // fill 1st row
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;

    return top_down(m, n, s1, s2, dp);
}

int main()
{
    string s1 = "acbcf";
    string s2 = "abcdaf";
    int ans = LCS_top_down(s1.length(), s2.length(), s1, s2);
    cout << "Length of maximum common substring is :" << ans << endl;
    return 0;
}
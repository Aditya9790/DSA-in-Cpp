/*
Given two strings. The task is to find the length of the longest common substring.

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

/*
The approach is same as that of length of longest common subsequence.

In this code if we find a mismatch reset the count to 0
the rest of the procedure is same as that of LCS
*/

int top_down(int m, int n, string s1, string s2, vector<vector<int>> &dp)
{
    int ans = 0;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0; // count is reset
        }
    }
    return ans;
}

int LCS_top_down(int m, int n, string s1, string s2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int count = 0; // length of max common substring
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

// -------------------Memoization------------------------------
// int memo_ans(int m, int n, string s1, string s2, vector<vector<int>> &dp, int &count, int &ans)
// {
//     if (m == 0 || n == 0)
//         return 0;

//     if (dp[m][n] != -1)
//         return dp[m][n];

//     if (s1[m - 1] == s2[n - 1])
//     {
//         count += 1;
//         dp[m][n] = 1 + memo_ans(m - 1, n - 1, s1, s2, dp, count, ans);
//         ans = max(dp[m][n], count);
//         return dp[m][n];
//     }

//     else
//         return dp[m][n] = 0;
// }

// int memo(int m, int n, string s1, string s2)
// {
//     int count = 0;
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     int ans = 0;
//     return memo_ans(m, n, s1, s2, dp, count, ans);
// }

int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";
    int m = s1.length(), n = s2.length();
    cout << LCS_top_down(m, n, s1, s2) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

// https://leetcode.com/discuss/interview-question/1273766/longest-common-substring

int LCS(int m, int n, string s1, string s2, vector<vector<int>> &dp)
{
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int longestPalindromeSubseq(string s)
{

    ios::sync_with_stdio(false);

    string s1 = s;
    string s2 = "";

    // reverse s
    for (int i = s1.length() - 1; i >= 0; i--)
        s2 += s1[i];

    int m = s1.length(), n = s2.length();

    // reverse the current string ans find longest common subsequence of reversed string and
    // original string this is longest palindromic subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // fill dp table
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;

    int ans = LCS(m, n, s1, s2, dp);
    return ans;
}

int main()
{
    string s = "agbcba";

    int max_palin_len = longestPalindromeSubseq(s);
    cout << "Longest palin Subseq len : " << max_palin_len;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Input: s = "abc", t = "ahbgdc"
Output: true
*/

// check if s is subseq of t
int isSubSeq(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "abc", s2 = "ahbgdc";
    if (isSubSeq(s1, s2) == s1.length())
        cout << " s1 is subsequence of s2" << endl;
    else
        cout << "s1 is not subsequence of s2" << endl;
    return 0;
}
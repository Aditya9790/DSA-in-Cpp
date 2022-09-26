#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

class Solution
{
public:
    string long_common_substr(int m, int n, string s1, string s2, vector<vector<int>> &dp)
    {
        int ans = 0;
        string palin;
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > ans)
                    {
                        string tem = s1.substr(i - dp[i][j], dp[i][j]); // travel diagonally
                        string tem2 = string(tem.rbegin(), tem.rend());
                        if (tem == tem2)
                        {
                            ans = dp[i][j];
                            palin = tem;
                        }
                    }
                }
                else
                    dp[i][j] = 0; // count is reset
            }
        }
        return palin;
    }

    string longestPalindrome(string s)
    {
        int m = s.length();

        string s2 = string(s.rbegin(), s.rend());
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // we will fill dp table
        // all entries where dp[i][0] and dp[0][j] will be 0 where i and j range from 0 to n+1
        // we will do this because even length of one of the string is 0 the length of LCS will be 0

        // fill 1st column
        for (int i = 0; i < m + 1; i++)
            dp[i][0] = 0;

        // fill 1st row
        for (int j = 0; j < n + 1; j++)
            dp[0][j] = 0;

        string long_palin = long_common_substr(m, n, s, s2, dp);
        return long_palin;
    }
};
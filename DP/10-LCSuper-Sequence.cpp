#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

/*
Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
*/

class Solution
{
public:
    // add two strings and remove the LCS string
    // adding two strings gives str1 + str2 = cababac
    // subtract the LCS from the addition i.e. remove ab
    // ans is cabac

    string shortestCommonSupersequence(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();

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

        /*
            While filling DP table when s1[i-1]==s2[j-1] we change dp[i][j] as 1+dp[i-1][j-1] and when they are not equal we take max ans then fill up the corresp place.

            Simillarly here we will start from last pos in dp table i.e. dp[m][n] and add the char at that indices where
            dp[i]==dp[j].

            And for decrementing i and j we will use max rule that we used to updat dp top down table.

            if(dp[i][j-1] > dp[i-1][j]) then we will decrement j
            else decrement i
        */

        // actual printing
        int i = m, j = n;
        string LCS = "";

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1]) // if char equal
            {
                LCS.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    LCS.push_back(s1[i - 1]);
                    i--;
                }

                else
                {
                    LCS.push_back(s2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0)
        {
             // if after including all common there is are still
             // remaining characters then include the remaining.
            LCS.push_back(s1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            LCS.push_back(s2[j - 1]);
            j--;
        }

        reverse(LCS.begin(), LCS.end());

        return LCS;
    }
};
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string print_top_down(int m, int n, string s1, string s2, vector<vector<int>> &dp)
{
    string LCS = "";
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
    // return dp[m][n];

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
                i--;
            else
                j--;
        }
    }
    reverse(LCS.begin(), LCS.end());
    return LCS;
}

string LCS_top_down(int m, int n, string s1, string s2)
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

    return print_top_down(m, n, s1, s2, dp);
}

int main()
{
    string s1 = "zzazz";
    string s2 = "zzazz";
    string ans = LCS_top_down(s1.length(), s2.length(), s1, s2);
    cout << "Longest common subsequence is :" << ans << endl;
    cout << "Length of maximum common substring is :" << ans.length() << endl;
    return 0;
}


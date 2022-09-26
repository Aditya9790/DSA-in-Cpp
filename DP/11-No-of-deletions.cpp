#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

/*
 Minimum number of deletions and insertions to transform one string into another
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
Example:
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
         Minimum Insertion = 0
*/

/*
Operations to make str1 to str2 we need to delete cretain char or add some char.
The only part that is left unchanged in str1 and str2 is the LCS of str1 and str2

No of deletions = len(str1) - len(LCS)
No of insertion = len(str2) - len(LCS)

ex str1 = heap and str2 = pea

common part in str1 and str2 is LCS i.e.(ea) . we will delete char other than "ea" i.e. h and p (no of deletion = 2) than str1 will be "ea" and we will add "p" from str2 to str1 (no of insertion 1) then str1 will become "pea".
Total operations = 3
*/

int LCS(string str1, string str2)
{
    int m = str1.length(), n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // fill dp table
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;

    // actual dp code
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int insertion_deletion(string str1, string str2)
{
    int lcs = LCS(str1, str2);

    int deletion = str1.length() - lcs;
    int insertion = str2.length() - lcs;
    return deletion + insertion;
}

int main()
{
    string str1 = "heap", str2 = "ea";
    int ans = insertion_deletion(str1, str2);
    cout << "operations : " << ans << endl;
    return 0;
}

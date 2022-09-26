/*
Divide an array into two pats such that both of them have qeual sum :
Ex : {1, 5, 11, 5}
ans : {1, 5, 5} and {11}
both arrays have equal sum
*/

/*
Approach to this problem is :
First we need two arrays with equal sum, then that means bots arrays will have sum == s

Therefore sum of all elements in question array must be even then and then only we can divide the arrays into two parts such that sum of their elements will be equal.

Here sum of all elements is 22 => we can divide this array in two parts with sum of each aray being 11.
*/

/*
Now first we will find sum of all elements of question array. Say it's s.
Divide it by 2==> (s/2) then find are there elements present in array that sum up to (s/2).
If yes then the remaining elements will automatically sum up to other hals i.e. s/2.

This problem is reduced to subset sum problem.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool subsetSum(vector<int> nums, int sum, int n, vector<vector<bool>> &dp)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
            {
                bool take = dp[i - 1][j - nums[i - 1]];
                bool not_take = dp[i - 1][j];
                dp[i][j] = take || not_take;
                // if(dp[i][j]) ans.push_back(nums[i]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

bool equal_sum(vector<int> nums)
{
    // first sum all elements in array
    int n = nums.size();
    int sum = 0;
    for (auto i : nums)
        sum += i;

    // now if sum is odd then we cannot divide it into two equal parts so return false.
    if (sum % 2 != 0)
    {
        cout << "Cannot divide" << endl;
        return false;
    }

    else // if even then check whether subset sum == sum/2
    {
        // before calling subset sum function initialize dp array
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));

        // sum = 0 when size ranges from 0 to n
        // empty array
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;

        // array size==0 but sum ranges from 1 to n
        // not possible
        for (int j = 1; j < sum + 1; j++)
            dp[0][j] = false;

        return subsetSum(nums, sum / 2, n, dp);
    }
}

int main()
{
    vector<int> nums = {1001, 5, 11, 5};
    // vector<int> ans;
    if (equal_sum(nums))
    {
        cout << "Partition Possible" << endl;
    }
    else
        cout << "Partition not possible" << endl;
    return 0;
}
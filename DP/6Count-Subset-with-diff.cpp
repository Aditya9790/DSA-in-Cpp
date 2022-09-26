/*
Given in question :
an array (arr)
a difference (diff)
Task: To find count of all arrays whose difference is equal to diff.

Theory
    assume we find 2 subsets S1 and S2 whose:-
    eqn1 --> S1+S2 = array_sum
    eqn2 -- > S1-S2 = diff
    2*S1 = (array_sum + diff) we get the value of S1 and S2.
    S1 = (array_sum+diff)/2 , S2 = (array_sum-S1)
    both means S1 will always be even i.e. if we get a odd S1 value return "no such subset possible"

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int Countsubset(vector<int> nums, int sum, int n, vector<vector<int>> &dp)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
            {
                int take = dp[i - 1][j - nums[i - 1]];
                // cout << "take at i=" << i << " j=" << j << " j-nums[i-1] " << j - nums[i - 1] << endl;
                int not_take = dp[i - 1][j];

                // we will add insted of taking or as if we found 1 subset then we want to keep moving forward until all subsets having sum==k is found
                dp[i][j] = take + not_take;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int CountSubsetDiff(vector<int> nums, int diff)
{
    // we only need to find the count of subsets that sum up to
    // (diff+subset_sum)/2
    // if above is even then we get count
    // else 0
    int n = nums.size();
    int sum = 0;
    for (auto i : nums)
        sum += i;
    cout<<"Sum is :"<<sum<<endl;
    sum = (diff + sum) / 2;
    // if (sum % 2 != 0)
    //     return 0;

    // dp array
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    // initialize column
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;

    return Countsubset(nums, sum, n, dp);
}

int main()
{
    vector<int> nums = {1, 1, 2, 3};
    int diff = 1;
    int ans = CountSubsetDiff(nums, diff);
    cout<<"ans is :"<<ans<<endl;
    return 0;
}
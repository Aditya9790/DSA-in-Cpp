#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
Given an array arr of size N containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Input: N = 4, arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

*/

/*
To approach this problem let's take a small array of [1,2,7]
we need to divide array in two subsets such that the diff of the two sum will be minimum.
Here array will be divided in {1, 2} ans {7} then diff will be min i.e. 4

To start solving first find the range in which the sum will belong which will be from 0 i.e. empty array to 10(sum of all elements.)

Then we will find the sum that the possible subsets can generate from given range.
The applicable sum will lie in range 0-10.

But no matter how we try we will not be able to generate 4, 5, 6 from the given set.

So our search space will be reduced.

New search space : {0, 1, 2, 3, 7, 8, 9, 10}

Now we will use subset sum question to find whether a subset is present which can yield sum that is present in "sum" array.

We will only perform above check for half of the array. i.e. from elem 0 to elem 3. As the other elem will just be Range - num.

Now since we want to minimize S2-S1 (S1 sum of 1st subset)
(S2 sum of other subset)

Since S2 == Range-S1
Then we want to minimize = S2-S1
                         = Range-S1-S1 = Range-2*S1

Fill the dp array for lower left half of S1 and find min of Range-2*S1

Fill the dp array for left half of sum array.
*/

void subSetSum(vector<int> &nums, int maxSum, int n, vector<vector<int>> &dp)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < maxSum + 1; j++)
        {
            if (nums[i - 1] <= j) // if curr elem < req sum
            {
                int take = dp[i - 1][j - nums[i - 1]];
                int not_take = dp[i - 1][j];
                dp[i][j] = take || not_take;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return;
}

int minSubsetDiff(vector<int> &nums, int n)
{
    int maxSum = 0;
    int minSum = 0;
    for (auto i : nums)
        maxSum += i;

    // pass maxSum so that we get dp table
    vector<vector<int>> dp(n + 1, vector<int>(maxSum + 1, 0));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int j = 1; j < maxSum + 1; j++)
        dp[0][j] = 0;

    subSetSum(nums, maxSum, n, dp);

    // we will now check for the last row in table
    // for every element in last row it will tell us
    // whether there exits a subset at index dp[i][j] with subset size as i and req sum as j.

    int min_diff = INT_MAX;
    for (int i = 0; i <= maxSum / 2; i++)
    {
        if (dp[n][i])
            min_diff = min(min_diff, maxSum - (2 * i));
    }
    return min_diff;
}

int main()
{
    vector<int> nums = {1, 6, 11, 5};
    int n = nums.size();
    int sum = 5;
    cout << "Min Difference is :" << minSubsetDiff(nums, n) << endl;
    return 0;
}
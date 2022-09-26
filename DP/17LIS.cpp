#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

int LIS(vector<int> &nums, int index, int prev, vector<vector<int>> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    int take = 0;
    // do not consider current element
    int not_take = LIS(nums, index + 1, prev, dp);

    if (prev == -1 || nums[prev] < nums[index])
        // take the current element
        take = 1 + LIS(nums, index + 1, index, dp);

    return dp[index][prev + 1] = max(take, not_take);
}

int lengthOfLIS(vector<int> &nums)
{
    int index = 0;
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    return LIS(nums, index, -1, dp);
}

/*

Brute Force

int LIS(vector<int> &nums, int index, int prev)
    {
        if(index >= nums.size()) return 0;
        
        int take = 0, not_take = LIS(nums, index+1, prev);
        
        if(prev < nums[index]) take = 1 + LIS(nums, index+1, nums[index]);
        
        return max(take, not_take);
        
    }
*/

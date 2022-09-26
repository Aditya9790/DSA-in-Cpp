/*
Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.

Ex:
Input:
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 1
Explanation: we can divide above array
into 3 parts with equal sum as (2, 4),
(1, 5), (6)
*/

#include <bits/stdc++.h>
using namespace std;

bool partition(vector<int> &nums, vector<bool> &visited, int target, int cur_sum, int i, int k)
{
    // if k=3 and we found 2 subsets that have equal sum then
    // this subset must have sum of elemen ts equal to that of the other 2
    // if we found k-1 subsets then k th
    // one must be the one that makes the 4 th side of square
    if (k == 1)
        return true;

    if (cur_sum == target)                                    // if we found 1st subset decrease k by 1 and again call
        return partition(nums, visited, target, 0, 0, k - 1); // with cur_sum as 0

    for (int j = i; j < nums.size(); j++)
    {
        // if we already visited a index or cur_sum + number at cur index
        // is greater than target skip
        if (visited[j] || cur_sum + nums[j] > target)
            continue;

        // mark visited as true
        visited[j] = true;

        if (partition(nums, visited, target, cur_sum + nums[j], j + 1, k))
            return true;

        // if curr index cannot be a part of square then again reset the visited[j] to 0.
        visited[j] = false;
    }
    return false;
}

bool isKPartitionPossible(vector<int> &nums, int k)
{
    int sum = 0;
    for (auto i : nums)
        sum += i;

    // if size of input array is less then k then return false
    // also return false if sum of all elements in array is not divisible ny k
    // ex if we want array to divide in 3 equal parts and sum of all elements of array is 15 then we can divide the array in 3 subsets each havinf sum 5.
    // but if sum of all elements in array is 13 then we can only divide array having equal sum in two equal parts i.e. two subarray of size 4 and other of 1.
    // but the above partition will not have been partioned on basis of given condition.
    if (nums.size() < k || sum % k)
        return false;

    vector<bool> visited(nums.size(), false);

    return partition(nums, visited, sum / k, 0, 0, k);
}
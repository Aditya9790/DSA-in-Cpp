/*
Advanced Binary Search

Question :

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

// Solution : https://youtu.be/YTTdLgyqOLY?t=2626

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stalls, int k, int mid)
{
    int cowCount = 1; // initially process for cow 1
    int lastPos = stalls[0]; // initially place at 0th index

    for(int i=0;i<stalls.size();i++)
    {
        // we take >= as if it is possible to place at mid then it will also be possible to place cow at index > mid in order to get 
        if(stalls[i]-lastPos >= mid)
        {
            cowCount++;
            if(cowCount == k) return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCow(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    // find max value
    for (int i = 0; i < stalls.size(); i++)
        maxi = max(maxi, stalls[i]);

    int e = maxi; // maximum stall
    int ans = -1;
    int mid = s + (e - s) / 2;
    // s = low, e = high analogy
    while (s <= e)
    {
        // is possible at a k th index them extend search from next of mid
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            // if not possible at kth index narrow down search from low i.e. s to mid-1
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    return 0;
}
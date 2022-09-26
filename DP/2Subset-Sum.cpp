/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.


Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
There is a subset (4, 5) with sum 9.
*/

/*
This problem is simillar to knapsack where for each integer we have two choices whether to take it in subset or not to take.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
bool subset(int nums[], int sum, int n, vector<vector<bool>> &dp)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if(nums[i-1] <= j)
                {
                    bool take = dp[i-1][j-nums[i-1]]; cout<<"take at i="<<i<<" j="<<j<<" j-nums[i-1] "<< j-nums[i-1]<<endl;
                    bool not_take = dp[i-1][j];
                    dp[i][j] = take || not_take;
                }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for(auto i:dp)
    {
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<"\nN is:"<<n<<" sum is:"<<sum<<endl;
    return dp[n][sum];
}

int main()
{
    int a[6] = {2, 3, 5, 6, 8, 10};
    int n = 6;
    int sum = 5;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    // bool dp[n+1][sum+1];

    // initially we will initialize array
    // consider for 0th column the row values will range from 0 to sum
    // this means that we want a subset with sum=0 and size of array will be n from (0 to n)
    // this is possible as any empty subset will have sum 0 irrespective the size of array
    // i.e. dp[i][0] = true; i=0 to n

    // simillarly for 0th row and all columns
    // except for dp[0][0] we cannot have true in them
    // this is because if row=0 and column = 3 this means that we want sum=3 and with size of array as 0, which is impossible
    // therefore, dp[0][j] = false ; j = 1 to sum

    // initialize row
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    // initialize column
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = false;

    cout << subset(a, sum, 6, dp);
    return 0;
}
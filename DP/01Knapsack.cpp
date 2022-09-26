/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum  of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick  it (0-1 property).
*/

/*
While making a matrix for DP take size of matrix such that the values that change in the problem will be it's size

Ex: Here the weight W and size of knapsac is n i.e. matrix size is dp[n+1][w+1]
Initialize it's all values with -1

For any weight we will have two options either to choose it or not choose it, then decrease the size of array and call recursive function again.

The final ans will be max of choose ot not choose.

i.e. for any element we will first not choose it ans then find the ans
then again we will choose that element and find ans.

The final ans will be max of the above two.

In doing so if we find such a weight value that has value > wt value of knapsac we will just exclude element ans perform knapsac excluding that element.

Also at each step we will check whether the value that we are searching is present in out dp matrix or not.
If present then simply return dp[i][j]
else call recursive function and store the obtained value in our result.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

int memo(vector<vector<int>> &dp, int w, int wt[], int val[], int n)
{
    // if n==0 or total weight==0 return 0
    if (n == 0 || w == 0)
        return 0;

    // if value already present(i.e. != -1) in dp return
    if (dp[n][w] != -1)
        return dp[n][w];

    // if the weight of an element  > capacity of bag exclude that element
    if (wt[n - 1] > w)
        return memo(dp, w, wt, val, n - 1);
    else // if wt of that elem <= w then we have two choice either to include it or exclude it and find ans
    // final ans will be maximum of the two
    {
        int include = val[n - 1] + memo(dp, w - wt[n - 1], wt, val, n - 1); // if we include elem at n-1 th index then the total available capacity
                                                                            // of knapsack will decrease by the choosen wt i.e. wt at n-1 th index
        int exclude = memo(dp, w, wt, val, n - 1);                          // if we do not include the element then available weight of knapsack will not decrease

        // update the max of thw two in dp matrix
        dp[n][w] = max(include, exclude);
        return dp[n][w];
    }
}

int knapsack(int wt[], int val[], int w, int n)
{
    // wt[] = weight vector
    // val[] = value of each element
    // W = total weight for which we want to choose element
    // n = size of wt and val vector

    // initialize dp matrix
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    return memo(dp, w, wt, val, n);
}

//############ By Top Down Approach ###########################

/*
We will convert the memoized version to a matrix approach.
Insted of calling recursive function we will maintain a matrix similar to memo method but will not call recursive function.

We will choose a dp matrix of suitable size.
Now in our recursive function the base case was if W==0 or n==0
then we would return 0 simillarly here we will fill the 0 th row and 0th column of matrix WITH 0 AS this is our base condition.

This all will be put inside a loop :
{
    Now moving towards the next condition i.e.
    if the weight of an element  > capacity of bag exclude that element

    This condition will be written as
    dp[n][w] = dp[n-1][w] ; n-1 because we have not included that element as it's wt was > wt of knapsack.

    Now if that's not the case then

    dp[n][w] = max(include, exclude)
    here,
    include means we will include that element then,
    ** include = val[n-1] + dp[n-1][w-wt[n-1]]
    this [w-wt[n-1]] is because as we have included that element then the size of knapsach has decreased by that qty.

    ** Exclude = dp[n-1][w] // no change in w as element not included
}
*/

int knapsackDP(int wt[], int val[], int w, int n)
{
    int dp[n + 1][w + 1];

    // matrix initialization
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < w + 1; j++)
        dp[0][j] = 0;

    // start the filling of matrix
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}
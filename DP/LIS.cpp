class Solution {
public:

    int LIS(vector<int> &nums, int index, int prev, vector<vector<int>> &dp)
    {
        if(index >= nums.size()) return 0;
        
        if(dp[index][prev+1] != -1) return dp[index][prev+1];
        
        
        int take = 0, not_take = LIS(nums, index+1, prev, dp);
        
        if(prev == -1 || nums[prev] < nums[index]) take = 1 + LIS(nums, index+1, index, dp);
        
        return dp[index][prev+1] = max(take, not_take);
        
    }
    
    int lengthOfLIS(vector<int>& nums)
    {
        int index = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return LIS(nums, index, -1, dp);
    }
};


// Brute Force

/*int LIS(vector<int> &nums, int index, int prev)
    {
        if(index >= nums.size()) return 0;
        
        int take = 0, not_take = LIS(nums, index+1, prev);
        
        if(prev < nums[index]) take = 1 + LIS(nums, index+1, nums[index]);
        
        return max(take, not_take);
        
    }*/

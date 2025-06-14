//Recursive

class Solution {
public:
    int recursive(int index, int prev_ind, vector<int>&nums)
    {
        int n = nums.size();
        if (index == n) return 0;

        int len = 0 + recursive(index+1, prev_ind, nums);       //NOT TAKE

        if (prev_ind == -1 || nums[index] > nums[prev_ind])
        {
            len = max (len, 1 + recursive(index+1, index, nums));      //Take
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        return recursive(0,-1,nums);
    }
};

//TC : O(2^N)
//SC : O(N)

//Memoization
class Solution {
public:
    int recursive(int index, int prev_ind, vector<int>&nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (index == n) return 0;

        if (dp[index][prev_ind+1] != -1) return dp[index][prev_ind+1];    //using coordinate shift to take care of prev_ind being in -1.

        int len = 0 + recursive(index+1, prev_ind, nums,dp);       //NOT TAKE

        if (prev_ind == -1 || nums[index] > nums[prev_ind])
        {
            len = max (len, 1 + recursive(index+1, index, nums,dp));      //Take
        }

        return dp[index][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recursive(0,-1,nums,dp);
    }
};

//TC: O(N*N)
//SC: O(N*N) + O(N)

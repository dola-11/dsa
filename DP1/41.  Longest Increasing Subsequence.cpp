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


//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index = n-1; index >= 0; index--)
        {
            for (int prev_ind = index-1; prev_ind >= -1; prev_ind --)
            {
                int len = 0 + dp[index+1][prev_ind+1];       //NOT TAKE
                if (prev_ind == -1 || nums[index] > nums[prev_ind])
                {
                    len = max (len, 1 + dp[index+1][index+1]);      //Take
                }
                dp[index][prev_ind+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};

//Time : O(n²)
//Space : O(n²)

//Space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);

        for(int index = n-1; index >= 0; index--)
        {
            for (int prev_ind = index-1; prev_ind >= -1; prev_ind --)
            {
                int len = 0 + next[prev_ind+1];       //NOT TAKE
                if (prev_ind == -1 || nums[index] > nums[prev_ind])
                {
                    len = max (len, 1 + next[index+1]);      //Take
                }
                curr[prev_ind+1] = len;
            }
            next = curr;
        }
        return next[-1+1];
    }
};

//Time : O(n²)
//Space : O(n)

//Tabulation algo 2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;

        for(int i=0; i<n; i++)
        {
            for(int prev = 0; prev<= i; prev++)
            {
                if (nums[prev] < nums[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

//Time : O(n²)
//Space : O(n)

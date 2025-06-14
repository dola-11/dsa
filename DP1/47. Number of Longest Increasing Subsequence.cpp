class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);

        int maxi = 1;

        for (int i=0; i<n; i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];        //inherit
                }
                else if (nums[prev]<nums[i] && 1 + dp[prev] == dp[i])
                {
                    //increase the cnt
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int nos = 0;
        for (int i=0; i<n; i++)
        {
            if (dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};

//Time: O(n²)
//Space: 	O(n)

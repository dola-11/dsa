//A strictly increasing or a strictly decreasing sequence should  is considered as a bitonic sequence
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) 
    {
        // code here
        vector<int> dp1(n,1);
        for (int i=0; i<n; i++)
        {
            for(int prev = 0; prev <i; prev++)
            {
                if (nums[prev] < nums[i] && dp1[i] < 1 + dp1[prev])
                {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
        
        vector<int> dp2(n,1);
        for(int i=n-1; i>=0; i--)
        {
            for(int prev=i+1; prev<n; prev++)
            {
                if (nums[prev] < nums[i] && dp2[i] < 1 + dp2[prev])
                {
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }
        
        int maxi = 0;
        for (int i=0;i<n;i++)
        {
            maxi = max(maxi, dp1[i] + dp2[i]-1);
        }
        return maxi;
    }
};

/*
For both dp1 and dp2 → O(N²)

Total time: O(N²)

Space: O(N)
*/


//A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) 
    {
        // code here
        vector<int> dp1(n,1);
        for (int i=0; i<n; i++)
        {
            for(int prev = 0; prev <i; prev++)
            {
                if (nums[prev] < nums[i] && dp1[i] < 1 + dp1[prev])
                {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
        
        vector<int> dp2(n,1);
        for(int i=n-1; i>=0; i--)
        {
            for(int prev=i+1; prev<n; prev++)
            {
                if (nums[prev] < nums[i] && dp2[i] < 1 + dp2[prev])
                {
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }
        
        int maxi = 0;
        for (int i=0;i<n;i++)
        {
            if (dp1[i] >= 2 && dp2[i] >= 2)
            {
                maxi = max(maxi, dp1[i] + dp2[i]-1);
            }
        }
        return maxi;
    }
};

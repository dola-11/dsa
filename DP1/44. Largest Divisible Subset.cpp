class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        int maxi = 1;
        int lastIndex = 0;

        sort(nums.begin(),nums.end());
        
        for(int index = 0; index<n; index++)
        {
            hash[index] = index;
            for(int prev = 0; prev <index; prev++)
            {
                if (nums[index]% nums[prev] == 0 && dp[prev] + 1 > dp[index])
                {
                    dp[index] = dp[prev] + 1;
                    hash[index] = prev;
                }
            }

            if (dp[index] > maxi)
            {
                maxi = dp[index];
                lastIndex = index;
            }
        }

        vector<int>temp;
        temp.push_back(nums[lastIndex]); 
        
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//TC:O(n²)
//SC:O(n)

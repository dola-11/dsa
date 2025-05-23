class Solution{
    public:
    int countSubsequence(int ind, int size, int sum, int target, vector<int>&nums)
    {
        if (ind == size)
        {
            if (sum == target)
            {
                return 1;
            }
            return 0;
        }

        sum += nums[ind];
        int l = countSubsequence(ind+1,size,sum,target,nums);
        sum -= nums[ind];
        int r = countSubsequence(ind+1,size,sum,target,nums);

        return l+r;
    }  

    int countSubsequenceWithTargetSum(vector<int>& nums, int k)
    {
        return countSubsequence(0, nums.size(), 0, k, nums);
    }
};

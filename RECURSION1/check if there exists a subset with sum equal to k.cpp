class Solution{
    public:
    bool check(int index, vector<int>nums,int sum, int size, int target)
    {
        if (index == size)
        {
            if (sum == target) return true;
            return false;
        }
        
        sum += nums[index];
        if (check(index+1,nums,sum,size,target) == true) return true;

        sum -= nums[index];
        if (check(index+1,nums,sum,size,target) == true) return true;

        return false;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) 
    {
        return check(0,nums,0,nums.size(),k);
    }
};

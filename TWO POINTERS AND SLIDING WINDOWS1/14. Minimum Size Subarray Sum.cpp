class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int minlen = INT_MAX;

        int sum = 0;
        while(right<n)
        {
            sum = nums[right] + sum;

            while(sum >=target)
            {
                minlen = min(minlen, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

//TC : O(n)
//SC : O(1)

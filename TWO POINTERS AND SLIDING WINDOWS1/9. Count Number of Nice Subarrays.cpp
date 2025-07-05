class Solution {
public:
    int countNiceSubarrays(vector<int>& nums, int k)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int count = 0;

        while(right < nums.size())
        {
            sum += nums[right] % 2;
            while(sum > k )
            {
                sum -= nums[left] % 2;
                left+=1;
            }
            count += right-left+1;
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return countNiceSubarrays(nums, k) - countNiceSubarrays(nums,k-1);
    }
};

//TC : O(N)
//SC : O(1)

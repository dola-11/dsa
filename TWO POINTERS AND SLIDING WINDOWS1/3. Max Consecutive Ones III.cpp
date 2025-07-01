class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int maxlen = 0;
        int left = 0;
        int right = 0;
        int zeros = 0;
        while(right<nums.size())
        {
            if (nums[right] == 0)
            {
                zeros ++;
            }
            if (zeros>k)
            {
                if (nums[left] == 0)
                {
                    zeros --;
                }
                left ++;
            }
            if (zeros<=k)
            {
                int len = right - left +1;
                maxlen = max (len,maxlen);
            }
            right++;
        }
        return maxlen;
    }
};

//TC : O(N)
//SC : O(1)

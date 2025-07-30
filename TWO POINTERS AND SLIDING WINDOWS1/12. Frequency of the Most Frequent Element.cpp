//Without sorting, you can’t ensure the increments are used optimally.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int left = 0;
        int ans = 0;
        int n = nums.size();
        long curr = 0;

        for (int right=0; right<n; right++)
        {
            long target = nums[right];
            curr+=target;

            while((right-left+1)*target - curr > k)
            {
                curr-= nums[left];
                left++;
            }
            ans = max (ans, right-left+1);
        }
        return ans;
    }
};


//TC :  O(n log n) (due to sorting, loop is O(n))
//SC : O(1) 

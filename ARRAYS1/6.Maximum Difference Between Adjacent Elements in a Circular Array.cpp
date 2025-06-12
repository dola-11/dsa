class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int maxDiff = INT_MIN;
        int k = nums.size();

        for (int i=0; i<k; i++)
        {
            int diff = abs(nums[(i+1)%k]-nums[i%k]);
            maxDiff = max(maxDiff,diff);
        }
        return maxDiff;
    }
};

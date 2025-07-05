class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int jumps = 0;
        int right = 0;
        int left = 0;
        int n = nums.size();

        while(right<n-1)
        {
            int farthest = 0;
            for (int i=left; i<=right; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            left = right + 1;
            right = farthest;
            jumps = jumps + 1;
        }
        return jumps;
    }
};

//TC : O(N)
//SC : O(1)

//If you use while (right < n), then:
//The loop might execute one more time even after you've reached the end, resulting in an extra jump or even going out of bounds if not handled carefully.

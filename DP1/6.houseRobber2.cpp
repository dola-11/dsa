//almost same as the last ques

class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end)
    {
        int n = end - start;
        if (n==0) return 0;
        if (n==1) return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start],nums[start+1]);

        for (int i= start+2; i< end; i++)
        {
            int pick = nums[i] + prev2;
            int nonpick = 0 + prev1;
            int current = max(pick, nonpick);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];

        int max1 = robLinear(nums,0, n-1);
        int max2 = robLinear(nums,1, n);

        return max(max1,max2);
    }
};

//TC : O(n)
//SC : O(1)

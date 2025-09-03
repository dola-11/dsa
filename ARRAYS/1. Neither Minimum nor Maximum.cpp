class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
        if (nums.size()<3) return -1;
        sort(nums.begin(),nums.end());
        return nums[1];
    }
};

//TC : O(nlogn)
//SC :O(1)

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
        int n = nums.size();
        if (n<3) return -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int none = -1;

        for (int i=0; i<n; i++)
        {
            if (nums[i]>maxi)
            {
                maxi = nums[i];
            }
            if(nums[i]<mini)
            {
                mini = nums[i];
            }
        }

        for (int x : nums)
        {
            if (x!=mini && x!=maxi)
            {
                return x;
            }
        }

        return -1;
    }
};


//TC : O(N)
//SC : O(1)

//Since the problem guarantees distinct positive integers, you can solve in O(1) by just looking at the first three numbers:
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
        if (nums.size()<3) return -1;
        return max(min(nums[0], nums[1]), min(max(nums[0], nums[1]), nums[2]));
    }
};

//O(1) trick

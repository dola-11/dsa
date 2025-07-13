class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> mpp;
        for (int num : nums) 
        {
            mpp[num]++;
        }

        vector<int> ans;
        for (auto it : mpp) 
        {
            if (it.second == 1) 
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

//TC : O(2n) 
//SC : O(n)


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long long xorVal = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            xorVal = xorVal^nums[i];
        }

        int rightMost = (xorVal & (xorVal-1)) ^ xorVal;
        int b1 = 0;
        int b2 = 0;

        for(int i=0; i<n; i++)
        {
            if (nums[i] & rightMost)
            {
                b1 = b1^nums[i];
            }
            else
            {
                b2 = b2^nums[i];
            }
        }

        return {b1,b2};
    }
};

//TC : O(2N)
//SC : O(1)

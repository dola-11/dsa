class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        //no ofsubsets = 2^n
        int n = nums.size();
        int subsets = 1<<n;
        vector<vector<int>>ans;

        for(int i=0 ; i<subsets; i++)
        {
            vector<int>list;
            for(int j=0; j<n; j++)
            {
                if(i & (1<<j))
                {
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};

//TC : O(n × 2ⁿ) — loop over all 2ⁿ subsets and for each, check up to n elements
//SC : O(n × 2ⁿ) — for storing all subsets

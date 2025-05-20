class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int> &soln, vector<vector<int>> &result )
    {
        result.push_back(soln);
        for (int i = start; i<nums.size(); i++)
        {
            soln.push_back(nums[i]);
            backtrack(nums,i+1,soln,result);
            soln.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>result;
        vector<int>soln;
        backtrack(nums,0,soln,result);
        return result;
    }
};

//SC : O(n) + O(2^n * n) = O(2^n * n)
//TC : O(2^n * n)

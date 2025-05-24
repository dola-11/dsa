class Solution {
public:
    void subsetSum2(int index, vector<int> &solution, vector<vector<int>> &result, vector<int>&nums )
    {
        result.push_back(solution);

        for (int i=index; i<=nums.size()-1; i++)
        {
            if (i>index && nums[i] == nums[i-1]) continue;

            solution.push_back(nums[i]);
            subsetSum2(i+1,solution,result,nums);
            solution.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>>result;
        vector<int>solution;
        sort(nums.begin(),nums.end());
        subsetSum2(0,solution,result,nums);
        return result;
    }
};

//TC : O(2^n × n)
//SC : O(2^n × n) + O(n)

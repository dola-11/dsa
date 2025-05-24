//method 1
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>res;
        vector<int>solution;
        vector<bool>used(nums.size(),false);
        permutations(nums,solution,res,used);
        return res;
    }

    void permutations(vector<int> &nums, vector<int> &solution, vector<vector<int>> &res, vector<bool> &used)
    {
        if (solution.size() == nums.size())
        {
            res.push_back(solution);
            return;
        }

        for (int i=0; i<nums.size(); i++)
        {
            if (!used[i])
            {
                solution.push_back(nums[i]);
                used[i] = true;
                permutations(nums,solution,res,used);
                used[i] = false;
                solution.pop_back();
            }
        }
    }
};
//TC : O(n! * n)
//SC : O(n) + O(n) + O(n) + O(n! × n) = O(n! × n)


//method 2:
//swapping logic

class Solution {
public:
    void permutations(int index, vector<int> &nums, vector<vector<int>> &result)
    {
        if (index >= nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i=index; i<nums.size(); i++)
        {
            swap(nums[index],nums[i]);
            permutations(index+1, nums, result);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        permutations(0,nums,result);
        return result;   
    }
};

//TC: O(n!) 
//SC: O(n! × n) 

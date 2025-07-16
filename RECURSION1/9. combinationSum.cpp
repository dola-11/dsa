//you can pick the same element multiple times (unbounded pick)
class Solution {
public:
    void sumCombinations(int index, int sum, int target, int n, vector<int> &candidates, vector<int> &sol, vector<vector<int>> &result)
    {
        if (sum == target )
        {
            result.push_back(sol);
            return;
        }

        if (sum > target || index >= n)
        {
            return;
        }
        
        //considering the next
        sumCombinations(index+1,sum,target,n,candidates,sol,result);

        //considering the current any no of times
        sol.push_back(candidates[index]);

        //sum is passed by value, not by reference.
        sumCombinations(index,sum+candidates[index],target,n,candidates,sol,result);
        sol.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        vector<vector<int>>result;
        vector<int>sol;
        sumCombinations(0,0,target,n, candidates,sol,result);
        return result;
    }
};

// TC: O(2^n * target),  2^n from considering each element either included or excluded, T because of repeated picking of the same element to reach the target.
// SC: exponential in the worst case.

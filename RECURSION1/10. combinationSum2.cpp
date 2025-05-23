class Solution {
public:
    void combinations(vector<int> &candidates ,vector<int> &solution,vector<vector<int>> &result, int start, int target)
    {
        if (target == 0)
        {
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i <= candidates.size()-1; i++)
        {
            if (i>start && candidates[i] == candidates[i-1]) continue;

            if (candidates[i] > target ) break;

            solution.push_back(candidates[i]);
            combinations(candidates,solution,result,i+1,target-candidates[i]);
            solution.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int>solution;
        sort(candidates.begin(),candidates.end());
        combinations(candidates, solution, result, 0, target);
        return result;
    }
};

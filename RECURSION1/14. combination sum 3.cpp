class Solution {
public:
    void combinationHelper(int index, int k, int n, vector<int> & solution, vector<vector<int>>& result)
    {
        if (solution.size() == k && n==0)
        {
            result.push_back(solution);
            return;
        }

        if (solution.size()>k || n<0) return;

        for (int i = index; i <= 9; i++)
        {
            solution.push_back(i);
            combinationHelper(i+1,k,n-i,solution,result);
            solution.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> result;
        vector<int> solution;
        combinationHelper(1,k,n,solution,result);
        return result;
    }
};

//TC : O(C(9, k) × k)
//SC : O(C(9, k) × k + k) = O(C(9, k) × k)

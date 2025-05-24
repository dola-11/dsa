class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> sol;
        backtrack(1,n,k,sol,res);
        return res;
    }

    void backtrack(int start, int n, int k, vector<int>& sol, vector<vector<int>>& res)
    {
        if (sol.size() == k)
        {
            res.push_back(sol);
            return;
        }

        for(int i = start; i<=n; i++)
        {
            sol.push_back(i);
            backtrack(i+1,n,k,sol,res);
            sol.pop_back();
        }
    }
};

//TC - O(k * nCk)
//SC - O(k)

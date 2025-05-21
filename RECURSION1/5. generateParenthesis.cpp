class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string>result;
        string soln;
        backtrack(0,0,result,soln,n);
        return result;
    }

    void backtrack(int open, int close, vector<string>&result, string soln, int n)
    {
        if (soln.size() == 2*n)
        {
            result.push_back(soln);
            return;
        }

        if (open < n)
        {
            soln.push_back('(');
            backtrack(open+1,close,result,soln,n);
            soln.pop_back();
        }

        if (close < open)
        {
            soln.push_back(')');
            backtrack(open, close+1, result, soln, n);
            soln.pop_back();
        }
    }
};

//Space Complexity: O(n) (stack) + O(4^n / √n × 2n) ≈ O(4^n / √n × n)
//Time Complexity: O(4^n / √n)

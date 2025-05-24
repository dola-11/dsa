class Solution {
public:
    void backtrack(int index, string &digits, unordered_map<char,string> &phoneMap, string &sol, vector<string> & result)
    {
        if (index == digits.size())
        {
            result.push_back(sol);
            return;
        }

        string possible = phoneMap[digits[index]];
        for (char c : possible)
        {
            sol.push_back(c);
            backtrack(index+1,digits,phoneMap,sol,result);
            sol.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        string sol;

        if (digits.empty()) return {};

        unordered_map<char,string> phoneMap = {{'2', "abc"}, {'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        backtrack(0,digits,phoneMap,sol,result);
        return result;
    }
};

//TC : O(4^n × n)
//SC : O(4^n × n)

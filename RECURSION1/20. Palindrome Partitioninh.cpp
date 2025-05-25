class Solution {
public:
    bool isPalindrome(string s,int start, int end)
    {
        while(start<=end)
        {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void backtrackHelper(int index, string &s, vector<string> &path, vector<vector<string>> & result)
    {
        if (index == s.length())
        {
            result.push_back(path);
            return;
        }

        for (int i = index; i<s.length(); i++)
        {
            if (isPalindrome(s,index,i))
            {
                path.push_back(s.substr(index, i - index +1));
                backtrackHelper(i+1,s,path,result);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>result;
        vector<string>path;
        backtrackHelper(0,s,path,result);
        return result;
    }
};

//TC : O(n * 2^n)
//SC : O(n * 2^n)

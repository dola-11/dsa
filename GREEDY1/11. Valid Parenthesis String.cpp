class Solution {
public:
    bool checkValidString(string s) 
    {
        int min = 0;
        int max = 0;
        int n = s.size();

        for (int i=0; i<n; i++)
        {
            if (s[i] == '(')
            {
                min = min+1;
                max = max+1;
            }
            else if (s[i] == ')')
            {
                min = min-1;
                max = max-1;
            }
            else
            {
                min = min-1;
                max = max+1;
            }
            if(min<0) min = 0;      //min cannot be negative provided max is also non negative
            if(max<0) return false;
        }
        //Only valid if there's at least one interpretation with no open brackets left
        return (min == 0);
    }
};

//TC : O(N)
//SC : O(1)

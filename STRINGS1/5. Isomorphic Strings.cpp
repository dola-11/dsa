class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.size() != t.size()) return false;

        map<char,char> mpp;
        map<char, char> reverseMpp;

        for(int i=0; i<s.size(); i++)
        {
            char cs = s[i];
            char ct = t[i];

            // If the mapping already exists, it must match
            if(mpp.count(cs))
            {
                if(mpp[cs] != ct)
                {
                    return false;
                }
            }
            else
            {
                if (reverseMpp.count(ct))
                {
                    return false;   // Ensure no other char already maps to ct
                }
                else
                {
                    mpp[cs] = ct;
                    reverseMpp[ct] = cs;
                }                  
            }
        }
        return true;
    }
};

//Time: O(n)
//SC : O(1) 

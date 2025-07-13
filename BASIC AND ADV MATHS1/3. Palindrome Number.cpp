class Solution {
public:
    bool isPalindrome(int x) 
    {
        long revnum = 0;
        int dup = x;
        while(x>0)
        {
            int rem = x%10;
            revnum = revnum*10 + rem;
            x = x/10;
        }

        if (dup == revnum)
        {
            return true;
        }
        return false;
    }
};

//TC : 	O(log₁₀ x)
//SC : O(1)

class Solution {
public:
    int mirrorDistance(int n) 
    {
        int revnum = 0;
        int m = n;

        while(m>0)
        {
            int ld = m%10;
            if ((revnum > INT_MAX/10) || (revnum < INT_MIN/10))
            {
                return 0;
            }
            else
            {
                revnum = revnum*10 + ld;
                m = m/10;
            } 
        }
        return abs(n - revnum);
    }
};

//TC : O(logn)
//SC : O(1)

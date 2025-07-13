class Solution {
  public:
    int countDigits(int n) 
    {
        // code here
        int cnt = 0;
        while(n>0)
        {
            cnt++;
            n = n/10;
        }
        return cnt;
    }
};

//TC : Time: O(log₁₀ n)
//SC : O(1)

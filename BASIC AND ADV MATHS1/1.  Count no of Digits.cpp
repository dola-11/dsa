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

int countDigits(int n) {
    if (n == 0) return 1;  // Special case: log10(0) is undefined
    return (int)(log10(n) + 1);
}

//TC : O(1)
//SC : O(1)

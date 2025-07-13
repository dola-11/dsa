// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) 
    {
        // code here
        int count = (int)(log10(n)+1);
        int sum = 0;
        int num = n;
        
        while(n>0)
        {
            int ld = n%10;
            sum += pow(ld,count);
            n = n/10;
        }
        
        if(num == sum)
        {
            return true;
        }
        return false;
    }
};

//TC : log10(n)
//SC : O(1)

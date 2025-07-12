class Solution {
  public:
    int setBits(int n) 
    {
        // Write Your Code here
        int count = 0;
        while(n!=0)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};

//TC : O(31)
//SC : O(logn base 2)

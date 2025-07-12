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

//TC : O(number of 1's in n) ≤ O(log n)
//SC : O(1)

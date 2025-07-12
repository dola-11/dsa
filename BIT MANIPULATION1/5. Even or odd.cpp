class Solution {
  public:
    bool isEven(int n) 
    {
        // code here
        return ((n&1) == 0);
    }
};

//TC : O(1)
//SC : O(1)

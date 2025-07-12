class Solution {
  public:
    bool checkKthBit(int n, int k) 
    {
        //  code here
        return (((n>>k)&1)!= 0);
    }
};

class Solution {
  public:
    bool checkKthBit(int n, int k) 
    {
        //  code here
        return ((n & (1 << k)) != 0);
    }
};

//TC : O(1)
//SC : O(1)

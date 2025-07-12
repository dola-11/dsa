class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        return (n | (1<<k));
    }
};


//TC : O(1)
//SC : O(1)

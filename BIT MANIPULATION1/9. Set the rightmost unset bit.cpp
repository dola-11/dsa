class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        return (n|n+1);
    }
};

//TC : O(1)
//SC : O(1)

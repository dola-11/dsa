// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) 
    {
        // code here
        int coins[10] = {1,2,5,10,20,50,100,200,500,2000};
        int coinPointer = 9;         //(n-1)
        vector<int>Coins;
        
        while(N > 0)
        {
            if (coins[coinPointer] <= N)
            {
                N = N - coins[coinPointer];
                Coins.push_back(coins[coinPointer]);
            }
            else
            {
                coinPointer--;
            }
        }
        return Coins;
    }
};

//TC : O(N)
//SC : O(1)

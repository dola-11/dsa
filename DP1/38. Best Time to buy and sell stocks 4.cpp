//See all the methods in Best Time to buy and sell stocks 3.cpp

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> ahead(2*k+1, 0);
        vector<int> curr(2*k+1, 0); 

        for (int index = n-1; index>=0; index--)
        {
            for (int transNo = 2*k-1; transNo >= 0; transNo --)
            {
                if(transNo%2 == 0)
                {
                    curr[transNo] = max(- prices[index] + ahead[transNo+1], 0 + ahead[transNo]);
                }

                if(transNo%2 != 0)
                {
                    curr[transNo] = max(prices[index]+ ahead[transNo+1], 0 + ahead[transNo]);
                }
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

//Time Complexity=O(n⋅2k)=O(nk)
//Space Complexity=O(2k)=O(k)

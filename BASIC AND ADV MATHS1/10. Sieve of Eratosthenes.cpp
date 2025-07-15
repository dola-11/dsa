class Solution {
  public:
    vector<int> sieve(int n) 
    {
        // code here
        vector<int>prime(n+1,1);
        vector<int>ans;
        prime[0] = prime[1] = 0;
        
        for (int i=2; i*i<=n; i++)
        {
            if(prime[i] == 1)
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    prime[j] = 0;
                }
            }
        }
        
        for(int i=2; i<=n; i++)
        {
            if(prime[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//TC : O(n log log n)
//SC : O(n)

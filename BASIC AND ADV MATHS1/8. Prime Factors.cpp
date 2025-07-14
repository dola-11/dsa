class Solution {
  public:
    vector<int> primeFac(int n) 
    {
        // code here
        vector<int>primes;
        for(int i=2; i*i<=n; i++)
        {
            if (n%i == 0)
            {
                primes.push_back(i);
                while(n%i == 0)
                {
                    n = n/i;
                }
            }
        }
        
        if (n!=1)
        {
            primes.push_back(n);
        }
        return primes;
    }
};

//TC : O(√n)
//SC : O(1)

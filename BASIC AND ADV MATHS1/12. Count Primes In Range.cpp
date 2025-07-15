// User function Template for C++

class Solution {
  public:
    vector<int>sievePrimes(int n)
    {
        vector<int>primes(n+1,1);
        primes[0] = 0;
        primes[1] = 0;
        
        for(int i=2; i*i<=n; i++)
        {
            if(primes[i] == 1)
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    primes[j] = 0;
                }
            }
        }
        return primes;
    }
    
    int countPrimes(int L, int R) 
    {
        // code here
        vector<int> getPrime = sievePrimes(200000);
        int cnt = 0;
        for(int i=2; i<=200000; i++)
        {
            cnt = cnt + getPrime[i];
            getPrime[i] = cnt;
        }
        
        return (getPrime[R] - getPrime[L-1]);
    }
};


| Operation           | Complexity     |
| ------------------- | -------------- |
| Sieve Preprocessing | O(N log log N) |
| Prefix Sum Build    | O(N)           |
| Query (L to R)      | O(1)           |
| Space               | O(N)           |

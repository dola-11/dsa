class Solution {
  public:
    bool isPrime(int n) 
    {
        // code here
        int cnt = 0;
        for(int i=1; i*i<=n; i++)
        {
            if(n%i == 0)
            {
                cnt++;
                if(n/i != i)
                {
                    cnt++;
                }
            }
        }
        if(cnt == 2)
        {
            return true;
        }
        return false;
    }
};

//TC : O(√n)
//SC : O(1)


//checking for 6k+1 and 6k-1
class Solution {
  public:
    bool isPrime(int n) 
    {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};

//TC : O(√n)
//SC : O(1)

class Solution {
  public:
    void print_divisors(int n) 
    {
        // Code here.
        if (n==0) cout << 0;
        
        for(int i=1; i<=n; i++)
        {
            if(n%i==0)
            {
                cout << i << " ";
            }
        }
    }
};

//TC : O(n)
//SC : O(1)


class Solution {
  public:
    void print_divisors(int n) 
    {
        // Code here.
        vector<int>divisors;
        int sqrtN = sqrt(n);
        
        for(int i=1; i<=sqrtN; i++)
        {
            if(n%i == 0)
            {
                divisors.push_back(i);
                
                if(i != n/i)
                {
                    divisors.push_back(n/i);
                }
            }
        }
        
        sort(divisors.begin(),divisors.end());
        for(int num : divisors)
        {
            cout << num << " ";
        }
    }
};

//TC : O(√n + √n log n) 
//SC : O(√n)

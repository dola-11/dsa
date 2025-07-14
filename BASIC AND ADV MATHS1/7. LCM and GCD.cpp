
//gcd(a,b) = gcd(a-b,b) if a>b

class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        
        int Gcd = gcd(a,b);
        int Lcm = (a*b)/Gcd;
        
        vector<int> result;
        
        result.push_back(Lcm);
        result.push_back(Gcd);
        
        return result;
    }
    
    int gcd(int a, int b)
    {
        while (a>0 && b>0)
        {
            if (a>b)
            {
                a = a%b;
            }
            else
            {
                b = b%a;
            }
        }
        return (a == 0) ? b : a;
    }
};

//TC : O(log max(a, b))
//SC : O(1)

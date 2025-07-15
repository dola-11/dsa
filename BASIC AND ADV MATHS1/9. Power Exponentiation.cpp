class Solution {
public:
    double pow(double x,long long i)
    {
        if (i==0) return 1.0;
        if (i==1) return x;

        double half = pow(x,i/2);
        {
            if (i%2 == 0)
            {
                return half*half;
            }
            else
            {
                return half*half*x;
            }
        }
    }
    
    double myPow(double x, int n) 
    {
        int nn = n;
        if (nn<0)
        {
            nn = -nn;
            x = 1/x;
        }
        return pow(x,nn);
    }
};

//TC : log2(n)
//SC : O(1)

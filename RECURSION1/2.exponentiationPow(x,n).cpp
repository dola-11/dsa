//iterative

class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans = 1.0;
        long long nn = n;  // to handle INT_MIN safely

        if (nn < 0) {
            nn = -nn;
            x = 1 / x;  // invert x upfront for cleaner logic
        }

        while (nn > 0) {
            if (nn % 2 == 1) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }

        return ans;
    }
};


//recursive approach
class Solution {
public:
    double power(double x, long long i)
    {
        if (i == 0) return 1.0;
        if (i == 1) return x;

        double half = power(x,i/2);
        if (i%2 == 0)
        {
            return half*half;
        }
        else
        {
            return half*half*x;
        }
    }
    double myPow(double x, int n) 
    {
        long long nn = n;
        if (nn<0)
        {
            x = 1/x;
            nn = -nn;
        }
        return pow(x,nn);
    }
};

//TC = O(logn)

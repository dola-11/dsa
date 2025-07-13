class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == divisor)
        {
            return 1;
        }
            
        bool sign = true;

        if (dividend >= 0 && divisor < 0) sign = false;
            
        if (dividend < 0 && divisor >= 0)  sign = false;
           
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        long quotient = 0;

        while (n >= d) 
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) 
            {
                cnt += 1;
            }
            quotient += 1L << cnt;
            n -= (d << cnt);
        }
        
        if (quotient == (1L << 31) && sign)
            return INT_MAX;
        if (quotient == (1L << 31) && !sign)
            return INT_MIN;

        return sign ? quotient : -quotient;
    }
};

//TC : 

| Operation          | Complexity |
| ------------------ | ---------- |
| Outer `while` loop | O(log n)   |
| Inner `while` loop | O(log n)   |
| Total              | O(log² n)  |

//SC : O(1)

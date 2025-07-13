// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) 
    {
        // code here
        int count = (int)(log10(n)+1);
        int sum = 0;
        int num = n;
        
        while(n>0)
        {
            int ld = n%10;
            sum += pow(ld,count);
            n = n/10;
        }
        
        if(num == sum)
        {
            return true;
        }
        return false;
    }
};

//TC : log10(n)
//SC : O(1)


// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) 
    {
        if (n == 0) return true;  // 0 is an Armstrong number

        int num = n;
        int count = 0;

        // Count the number of digits (no log10 to avoid precision issues)
        int temp = n;
        while (temp > 0) {
            count++;
            temp /= 10;
        }

        int sum = 0;
        temp = n;

        // Calculate the sum of digits raised to 'count'
        while (temp > 0) {
            int ld = temp % 10;

            // Manual power calculation to avoid floating-point errors
            int digitPower = 1;
            for (int i = 0; i < count; i++) {
                digitPower *= ld;
            }

            sum += digitPower;
            temp /= 10;
        }

        return sum == num;
    }
};

//TC : O(d × p), where d = number of digits, p = power computation per digit (up to d multiplications). For small n, this is negligible.
//SC : O(1)

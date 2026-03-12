//Method 1 : convert to string and flip

//Method 2: bit by bit flipping:
class Solution {
public:
    int bitwiseComplement(int n) 
    {
        int ans = 0;
        int currBit = 1;
        if(n == 0) return 1;

        while(n>0)
        {
            if ((n&1) == 0)
            {
                ans |= currBit;
            }
            currBit <<= 1;
            n >>= 1;
        }

        return ans;
    }
};


//TC : O(log n)
//SC : O(log1)


//Method 3: Using mask
class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n == 0) return 1;
        
        int bits = log2(n) + 1;
        int mask = (1<<bits) - 1;

        return mask ^ n;
    }
};

//TC : O(1)

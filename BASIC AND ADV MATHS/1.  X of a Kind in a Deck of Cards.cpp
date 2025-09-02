class Solution {
public:
    int calcGCD(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        map<int,int>freq;

        for (int card : deck)
        {
            freq[card]++;
        }

        int g = 0;
        for (auto &p : freq)
        {
            g = gcd(g,p.second);
        }

        return g>1;
    }
};

/*
Building frequency map
Iterates over all n elements in deck.
Insertion into map takes O(log k) where k is number of distinct elements.
Total: O(n log k)

Computing GCD
You iterate over each distinct element count (k times).
Each gcd() call is O(log m) where m is the maximum count value.

Total: O(k log m)

Overall Time Complexity = O(n log k + k log m)
Since k ≤ n and m ≤ n, we can simplify to O(n log n) in the worst case.


Space Complexity:

Frequency map → stores up to k distinct integers.
O(k) space.
GCD variables → constant extra space.
Overall Space Complexity = O(k)
In worst case (all cards distinct), O(n).
*/

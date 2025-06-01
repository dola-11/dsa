class Solution {
public:
    #define ll long long
    ll combinations(ll n)
    {
        if (n<0) return 0;
        return 1LL*(n+1)*(n+2)/2;
    }
    long long distributeCandies(int n, int limit) 
    {
        //x+y+z = n, (n+2C2) , if no limits


        //atleast1 = 3*(n-(limits+1)C2)
        //atleast2 = 3*(n-2*(limits+1)C2)
        //all3 = (n-3*(limits+1)C2); 

        ll allCombinations = combinations(n);
        ll oneAbove = 3LL*combinations(n-(limit+1));
        ll twoAbove = 3LL*combinations(n-2*(limit+1));
        ll threeAbove = combinations(n-3*(limit+1));

        ll validCombinations = allCombinations - (oneAbove - twoAbove + threeAbove);
        return validCombinations;
    }
};

//TC: O(1)
//SC : O(1)

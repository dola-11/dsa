class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();
        int i=0;

        while(i<n-1)
        {
            if (bits[i] == 1)
            {
                i+=2;
            }
            else
            {
                i++;
            }
        }

        return (i == n-1); //since its given that bits ends with 0 
    }
};

//TC : O(N)
//SC : O(1)

//Method 1: brute force

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int>prefixMax(n);
        vector<int>suffixMax(n);

        prefixMax[0] = height[0];
        for(int i=1; i<n; i++)
        {
            prefixMax[i] = max(prefixMax[i-1],height[i]);
        }

        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>0; i--)
        {
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }

        int total = 0;
        for (int i=0; i<n; i++)
        {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];

            if (height[i] < leftMax && height[i] < rightMax)
            {
                total += min(leftMax,rightMax) - height[i];
            }
        }
        return total;
    }
};

//TC : O(3N)
//SC : O(2N)

//2nd approach
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int lMax = 0;
        int rMax = 0;
        int total = 0;
        int l = 0;
        int r = n-1;

        while(l<r)
        {
            if (height[l]<height[r])
            {
                if (lMax > height[l])
                {
                    total += lMax - height[l];
                }
                else
                {
                    lMax = height[l];
                }
                l = l+1;
            }
            else
            {
                if (rMax > height[r])
                {
                    total += rMax - height[r];
                }
                else
                {
                    rMax = height[r];
                }
                r = r-1;
            }
        }
        return total;
    }
};

//TC : O(N)
//SC : O(1)

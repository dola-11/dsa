//My brute force approach

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int size = nums.size();
        set<int>ansIndices;

        for(int j=0; j<size; j++)
        {
            if (nums[j] == key)
            {
                for (int i=0; i<size; i++)
                {
                    if (abs(i-j)<=k)
                    {
                        ansIndices.insert(i);
                    }
                }
            }
        }

        vector<int>ans(ansIndices.begin(), ansIndices.end());
        return ans;
    }
};

//TC:O(n^2 log n) -> worst case
//O(n) for storing indices in the set
//O(n) for the result vector


//MAIN APPROACH
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<int>result;
        int r = 0;
        int n = nums.size();

        for(int j=0; j<n; j++)
        {
            if (nums[j]== key)
            {
                int l = max(r, j-k);
                r = min(n-1,j+k)+ 1;

                for (int i = l; i < r; i++) 
                {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};

//Each index is added at most once → O(n)
//O(1) extra space (res is output)

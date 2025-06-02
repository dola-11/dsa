class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) 
    {
        int n = arr.size();
        int secondSmallest = INT_MAX;
        int smallest = INT_MAX;
        
        for (int i=0; i<n; i++)
        {
            if (arr[i] < smallest)
            {
                secondSmallest = smallest;
                smallest = arr[i];
            }
            else if (arr[i] < secondSmallest && arr[i] != smallest)
            {
                secondSmallest = arr[i];
            }
        }
        if (secondSmallest == INT_MAX)
            return {-1, -1};
        return {smallest, secondSmallest};
    }
};

//TC : O(n)
//SC : O(1)

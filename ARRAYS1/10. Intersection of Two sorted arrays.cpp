class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) 
    {
        // Your code here
        vector<int>intersection;
        int m = arr1.size();
        int n = arr2.size(); 
        int i = 0, j = 0;
        
        while(i<m && j<n)
        {
            if (arr1[i] == arr2[j])
            {
                if (intersection.size()==0 || intersection.back() != arr1[i])
                {
                    intersection.push_back(arr1[i]);
                }
                i++;
                j++;
            }
            else if (arr1[i] < arr2[j])
                i++;
            else
                j++;
        }
        return intersection;
    }
};

//Time:O(m + n)
//Space:O(min(m, n))

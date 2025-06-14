class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) 
    {
        // Your code here
        
        // return vector with correct order of elements
        vector<int>uni;
        int i=0;
        int j=0;
        int m = a.size();
        int n = b.size();
        
        while(i<m && j<n)
        {
            // If both are equal, add any one and move both pointers
            if (a[i] == b[j]) 
            {
                if (uni.size() == 0 || uni.back() != a[i])
                    uni.push_back(a[i]);
                i++;
                j++;
            }
            // If a[i] < b[j], add a[i] and move i
            else if (a[i] < b[j]) 
            {
                if (uni.size() == 0 || uni.back() != a[i])
                    uni.push_back(a[i]);
                i++;
            }
            // If b[j] < a[i], add b[j] and move j
            else {
                if (uni.size() == 0 || uni.back() != b[j])
                    uni.push_back(b[j]);
                j++;
            }
        }
        // Add remaining elements of a[]
        while(i < m) {
            if (uni.size() == 0 || uni.back() != a[i])
                uni.push_back(a[i]);
            i++;
        }

        // Add remaining elements of b[]
        while(j < n) {
            if (uni.size() == 0 || uni.back() != b[j])
                uni.push_back(b[j]);
            j++;
        }

        return uni;
    
    }
};

//Time:O(m + n)
//Space:O(m + n) (total) - to return 

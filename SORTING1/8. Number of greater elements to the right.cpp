// User function Template for C++

class Solution {
  public:
    void merge(vector<pair<int,int>> &vec, vector<int> &ans, int low,int mid, int high)
    {
        vector<pair<int,int>> temp(high-low+1);
        int i = low;
        int j = mid+1;
        int k = 0;
        
        while(i<=mid && j<=high)
        {
            if (vec[i].first < vec[j].first)
            {
                ans[vec[i].second] += (high - j + 1);
                temp[k++] = vec[i++];
            }
            else
            {
                temp[k++] = vec[j++];
            }
        }
        
        while (i <= mid) 
        {
            temp[k++] = vec[i++];
        }
        
        while (j <= high) 
        {
            temp[k++] = vec[j++];
        }
        
        for (int p = 0; p < temp.size(); ++p) 
        {
            vec[low + p] = temp[p];
        }
        
    }
    void mergeSort(vector<pair<int,int>> &vec, vector<int> &ans,int low, int high)
    {
        if (low>=high) return;
        int mid = low + (high-low)/2;
        mergeSort(vec,ans,low,mid);
        mergeSort(vec,ans,mid+1,high);
        merge(vec,ans,low,mid,high);
    }
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) 
    {
        // write your code here
        vector<pair<int,int>> vec;
        for (int i=0; i<n; i++)
        {
            vec.push_back({arr[i],i});
        }
        
        vector<int>ans(n,0);
        mergeSort(vec, ans, 0, n-1);
        
        vector<int>result;
        for (int ind : indices)
        {
            result.push_back(ans[ind]);
        }
        return result;
    }
};

//TC: O(n log n + queries)
//SC : O(n) for temp arrays during merge.
//O(n) for ans.
//O(n) for vec.
//So: O(n) auxiliary space.

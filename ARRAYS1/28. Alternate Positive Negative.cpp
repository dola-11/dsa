// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) 
    {
        // code here
        vector<int>pos,neg;
        int n = arr.size();
        for (int i=0; i<n;i++)
        {
            if (arr[i]<0)
            {
                neg.push_back(arr[i]);
            }
            else
            {
                pos.push_back(arr[i]);
            }
        }
        
        if (pos.size()>neg.size())
        {
            for (int i=0; i<neg.size(); i++)
            {
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
            
            int index = 2*neg.size();
            for (int i=neg.size(); i<pos.size(); i++)
            {
                arr[index] = pos[i];
                index++;
            }
        }
        else
        {
            for (int i=0; i<pos.size(); i++)
            {
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
            
            int index = 2*pos.size();
            for (int i=pos.size(); i<neg.size(); i++)
            {
                arr[index] = neg[i];
                index++;
            }
        }
        
    }
};

//TC : O(N) + O(m(pos,neg)) + O(leftovers) = O(N) + O(N)
//SC : O(N)

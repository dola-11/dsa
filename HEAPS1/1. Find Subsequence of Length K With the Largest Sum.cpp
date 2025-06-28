class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i],i});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(),ans.end());

        for(int i=0; i<ans.size(); i++)
        {
            ans[i] = nums[ans[i]];
        }

        return ans;
    }
};

//TC : O(n log k) + O(k log k) + O(k) = O(n log k)
//SC : 	O(3k) = 	O(k)

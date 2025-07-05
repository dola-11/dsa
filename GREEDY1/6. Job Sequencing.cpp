//This code gives TLE, have to use disjoint set

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) 
    {
        // code here
        int n = deadline.size();
        vector<pair<int,int>>jobs;
        
        for (int i=0; i<n; i++)
        {
            jobs.push_back({profit[i],deadline[i]});
        }
        
        // Sort jobs by profit in descending order
        sort(jobs.rbegin(), jobs.rend());
        
        int maxDeadline = 0;
        for(int i=0; i<n; i++)
        {
            maxDeadline = max(maxDeadline, jobs[i].second);
        }
        
        vector<int>slots(maxDeadline+1,-1);
        
        int count = 0;
        int totalProfit = 0;
        
        for(int i=0; i<n; i++)
        {
            int d = jobs[i].second;
            int p = jobs[i].first;
            
            for(int j = d; j>=1; j--)
            {
                if (slots[j] == -1)
                {
                    slots[j] = i;
                    count++;
                    totalProfit += p;
                    break;
                }
            }
        }
        return {count,totalProfit};
    }
};

//TC : O(n * maxDeadline)
//SC : O(n + D), D = max(deadline[i])

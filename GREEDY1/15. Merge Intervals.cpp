class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> mergedIntervals;

        for(int i=0; i<n; i++)
        {
            auto currentInterval = intervals[i];
            
            if(mergedIntervals.empty() || mergedIntervals.back()[1] < currentInterval[0])
            {
                mergedIntervals.push_back(currentInterval);
            }
            else 
            {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], currentInterval[1]);
            }
        }
        
        return mergedIntervals;
    }
};

//TC : O(n log n) + O(n)
//SC : O(n)

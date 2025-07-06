class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>>finalIntervals;
        int i = 0;
        int n = intervals.size();

        //left portion
        while(i<n && intervals[i][1] < newInterval[0])
        {
            finalIntervals.push_back(intervals[i]);
            i++;
        }

        //overlaps
        while(i<n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        finalIntervals.push_back(newInterval);

        //right portion
        while(i<n)
        {
            finalIntervals.push_back(intervals[i]);
            i++;
        }

        return finalIntervals;
    }
};

//TC : O(N)
//SC : O(1)

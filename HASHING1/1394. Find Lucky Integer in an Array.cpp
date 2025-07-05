//my solution
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int,int> freqMap;
        
        for(int i=0; i<arr.size(); i++)
        {
            freqMap[arr[i]]++;
        }

        int maxLucky = 0;
        for(int i=0; i<arr.size();i++)
        {
            if(freqMap[arr[i]] == arr[i])
            {
                maxLucky = max(maxLucky,arr[i]);
            }
        }

        return maxLucky > 0 ? maxLucky : -1;
    }
};

//TC : O(n)
//SC : O(k) 

//MORE EFFICIENT
int findLucky(vector<int>& arr) 
{
    unordered_map<int, int> freqMap;
    
    for (int num : arr) {
        freqMap[num]++;
    }

    int maxLucky = -1;
    for (auto& [num, freq] : freqMap) {
        if (num == freq) {
            maxLucky = max(maxLucky, num);
        }
    }

    return maxLucky;
}

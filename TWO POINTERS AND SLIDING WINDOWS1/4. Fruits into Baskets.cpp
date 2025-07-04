class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int n = fruits.size();
        unordered_map<int,int>fruitHash;

        while(right < n)
        {
            fruitHash[fruits[right]]++;
            if (fruitHash.size() > 2)
            {
                fruitHash[fruits[left]]--;
                if(fruitHash[fruits[left]] == 0)
                {
                    fruitHash.erase(fruits[left]);
                }
                left++;
            }
            if(fruitHash.size()<=2)
            {
                maxlen = max(maxlen, right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};

//Time: O(n)
//Space: O(1)

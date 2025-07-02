class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch] ++;
        }
        
        priority_queue<pair<int,char>> maxHeap;

        for (auto &[ch,f]: freq)
        {
            maxHeap.push({f,ch});
        }

        string result;
        while(!maxHeap.empty())
        {
            auto [f,ch] = maxHeap.top();
            maxHeap.pop();
            result.append(f, ch); 
        }

        return result;
    }
};

/*
Time Complexity: O(n log k)
Where:
n = length of the input string s
k = number of unique characters in s (at most 128–256 for ASCII)

Breakdown:
Frequency count (unordered_map):
O(n) — One pass through the string to count frequencies.
Building the heap (priority_queue):
O(k log k) — Inserting k elements into a max-heap.
Building result string from heap:
O(n log k) — In the worst case, we pop k times and append up to n total characters.
Thus, total = O(n + k log k + n) = O(n log k) (since k ≤ n).

Space Complexity: O(n)
Breakdown:

unordered_map<char, int> → up to k unique characters → O(k)
priority_queue<pair<int, char>> → up to k entries → O(k)
Result string → length n → O(n)
Total auxiliary space = O(k + n) = O(n)
*/

class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch] ++;
        }
        
        int n = s.length();
        vector<vector<char>> buckets(n + 1);  // because max frequency is <= n

        for (auto& [ch, f] : freq) 
        {
            buckets[f].push_back(ch);
        }

        string result = "";
        for (int i = n; i >= 1; i--) 
        {
            for (char ch : buckets[i]) 
            {
                result.append(i, ch);  // append char `i` times
            }
        }

        return result;
    }
};

/*
Time Complexity: O(n)
Counting frequency: O(n)

Filling buckets: O(k) (≤ n)

Building result: O(n) (every character appears exactly once per unit of freq)

So total = O(n)

Space Complexity: O(n)
unordered_map<char, int> → O(k) ≤ O(n)

buckets[n+1] → worst case every char has freq 1 → O(n)

result string → O(n)
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;

        // Try every substring starting at i
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // frequency map for current substring

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // include s[j] in substring

                int maxFreq = 0;
                int minFreq = INT_MAX;

                // Calculate max and min frequencies (non-zero only)
                for (int k = 0; k < 26; k++) 
                {
                    if (freq[k] > 0) 
                    {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};

//Time: O(n² * 26) → effectively O(n²)
//Space: O(26) = O(1)

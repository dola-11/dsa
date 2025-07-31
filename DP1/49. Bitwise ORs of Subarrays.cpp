class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int>allORs;
        unordered_set<int>prev;

        for (int num:arr)
        {
            unordered_set<int>curr;
            curr.insert(num);

            for (int val:prev)
            {
                curr.insert(val | num);
            }

            for (int val:curr)
            {
                allORs.insert(val);
            }

            prev = move(curr);
        }

        return allORs.size();
    }
};

//TC : O(n * 32) ≈ O(n)
/*
✅ Time Complexity
1️⃣ Outer loop:

Runs once for every element → O(n)

2️⃣ Inner loop (for val : prev)

For each element, we OR current num with all values in prev.

prev can have at most 32 distinct values because bitwise OR can only set bits (there are max 32 bits in an int).

So inner loop is O(32) ≈ O(1).

3️⃣ Inserting into sets:

unordered_set insertions are average O(1).
*/
//SC : O(32 * n) ≈ **O(n)for the global set, constant extra for prev and curr

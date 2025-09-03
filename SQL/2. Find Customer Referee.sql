# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL

/*
Time Complexity:
Typically O(N) (full table scan).
With good index optimization → O(log N + K).
But since it’s an OR condition, many databases still just do a full table scan, so in practice, O(N)

Space Complexity:
O(1) execution overhead
O(K) to hold the results
*/

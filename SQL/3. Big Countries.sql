SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000
/*
Time Complexity:
Typically O(N) (full scan).
With good indexing → O(log N + K).

Space Complexity:
O(1) execution overhead
O(K) to store the results
*/

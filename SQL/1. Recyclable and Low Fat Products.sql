SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'

/*
Time Complexity
Without Indexes
The DB must scan all rows in the Products table.
For N rows → O(N).

With Indexes
product_id is the primary key → indexed automatically, but that doesn’t help filtering since you aren’t searching by product_id.
If you add an index on (low_fats, recyclable):
Finding qualifying rows → O(log N).
Collecting results (K rows matched) → + O(K).
Total → O(log N + K).
*/

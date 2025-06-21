/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return isInRange(root, LONG_MIN, LONG_MAX);
    }

    bool isInRange(TreeNode* root, long minVal, long maxVal)
    {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isInRange(root->left, minVal, root->val) && isInRange(root->right, root->val, maxVal);
    }
};

| Complexity | Value                            |
| ---------- | -------------------------------- |
| Time       | O(n)                             |
| Space      | O(h)  → O(log n) avg, O(n) worst |

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
    void getPaths(TreeNode* node, string path, vector<string>& result) 
    {
        if (!node) return;

        // Build the current path
        if (!path.empty()) path += "->";
        path += to_string(node->val);

        // If it's a leaf, save the path
        if (!node->left && !node->right) 
        {
            result.push_back(path);
            return;
        }

        // Recur for children
        getPaths(node->left, path, result);
        getPaths(node->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        getPaths(root, "", result);
        return result;
    }
};

/*
| Category          | Complexity |
| ----------------- | ---------- |
| Time              | O(N)       |
| Space (Recursion) | O(H)       |
| Space (Output)    | O(L × P)   |
*/

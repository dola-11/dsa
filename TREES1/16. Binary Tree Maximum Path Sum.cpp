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
    int maxPath(TreeNode* node, int& maxi)
    {
        if (node == NULL) return 0;

        int leftPath = max(0, maxPath(node->left,maxi));
        int rightPath = max(0, maxPath(node->right,maxi));

        maxi = max(maxi, leftPath + rightPath + node -> val);
        return max(leftPath,rightPath) + node -> val;
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
};

//TC : O(N)
//SC : O(N) - worst case. 	O(H)

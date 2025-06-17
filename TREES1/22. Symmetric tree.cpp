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
    bool isSymmetric(TreeNode* root) 
    {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right)
    {
        if (left == NULL || right == NULL) return left==right;          //symmetric only if both are NULL

        if (left->val != right->val) return false;
        
        return isSymmetricHelp(left->right,right->left) && isSymmetricHelp(left->left,right->right);
    }
};

//TC : O(N)
//SC : O(N)

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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        findMax(root,diameter);
        return diameter;
    }

    int findMax(TreeNode* root, int& maxi)
    {
        if (root == NULL) return 0;

        int lh = findMax(root->left,maxi);
        int rh = findMax(root->right,maxi);

        maxi = max(maxi, lh+rh);

        return 1+max(lh,rh);
    }
};

//Time - O(N); Space - O(N)->used for auxilliary stack space

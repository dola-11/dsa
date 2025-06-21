//Property of inorder traversal for BST - it returns the nodes in a sorted manner.

//Can use recursive, iterative or morris, just add the counter 

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
    int kthSmallest(TreeNode* root, int k) 
    {
        int count = 0;
        int result = -1;
        inOrderHelper(root,k,count,result);
        return result;
    }

    void inOrderHelper(TreeNode* root, int k, int& count, int&result)
    {
        if (root == NULL) return;
        inOrderHelper(root->left,k,count,result);
        count++;
        if(count==k)
        {
            result = root->val;
            return;
        }
        inOrderHelper(root->right,k,count,result);
    }
};

//TC - O(H+K) or O(N)- worst case
// SC - O(H) or O(N)

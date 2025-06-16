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

//Recursion

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == NULL)
        {
            return 0;
        }
        return (1+max(maxDepth(root->left),maxDepth(root->right)));         //1+max(leftHeight, rightHeight)
    }
};

//TC: O(n)
//SC: O(n)

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) 
        {
            int levelSize = q.size();  // number of nodes at current level
            for (int i = 0; i < levelSize; i++) 
            {
                TreeNode* current = q.front();
                q.pop();

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            depth++;  // finished processing one level
        }

        return depth;
    }
};

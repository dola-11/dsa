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
    void flatten(TreeNode* root) 
    {
        TreeNode* current = root;
        while(current != NULL)
        {
            if (current -> left != NULL)
            {
                TreeNode* prev = current -> left;
                while (prev -> right != NULL)
                {
                    prev = prev -> right;
                }
                prev -> right = current -> right;
                current -> right = current -> left;
                current -> left = NULL;
            }
            current = current -> right;
        }
    }
};

/*
At each node:
👉 If there’s a left subtree:

Find rightmost node of left subtree.

Attach right subtree to this node.

Move left subtree to the right.

Null out left pointer.

👉 Move to next right node.

✅  Time: O(n)

We visit each node once.

Inner loop visits nodes cumulatively O(n) (each edge followed once).

✅ Space: O(1)

No extra space used beyond variables.
*/

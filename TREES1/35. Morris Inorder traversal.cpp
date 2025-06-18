/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<int> getInorder(TreeNode* root) 
    {
    	//your code goes here
        vector<int>inorder;
        TreeNode* current = root;

        while(current != NULL)
        {
            if (current -> left == NULL)
            {
                inorder.push_back(current -> data);
                current = current -> right;
            }
            else
            {
                TreeNode* prev = current -> left;
                while(prev -> right && prev -> right != current)
                {
                    prev = prev -> right;
                }

                if (prev -> right == NULL)
                {
                    prev -> right = current;
                    current = current -> left;
                }
                else
                {
                    prev->right = NULL;
                    inorder.push_back(current -> data);
                    current = current -> right;
                }
            }
        }
        return inorder;
    }
};

//TC : O(N)
//SC : O(1)

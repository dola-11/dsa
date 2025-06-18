/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<int> preorder(TreeNode* root)
        {
	       //your code goes here
            vector<int>preorder;
            TreeNode* current = root;

            while(current != NULL)
            {
                if (current -> left == NULL)
                {
                    preorder.push_back(current -> data);
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
                        preorder.push_back(current -> data);
                        current = current -> left;
                    }
                    else
                    {
                        prev->right = NULL;
                        current = current -> right;
                    }
                }
            }
            return preorder;
		}
};

//TC : O(2N) ~ amortized
//SC : O(1)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToright = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int>currentLevel(size);
            for (int i=0; i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                int index = (leftToright) ? i : size-i-1;

                currentLevel[index] = node -> val;
                if (node -> left)
                {
                    q.push(node -> left);
                }
                if (node -> right)
                {
                    q.push(node -> right);
                }
            }

            leftToright = !leftToright;
            result.push_back(currentLevel);
        }
        return result;
    }
};

//TC : O(N)
//SC : O(N)

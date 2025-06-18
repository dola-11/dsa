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
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_map)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();

            if (current -> left != NULL)
            {
                parent_map[current -> left] = current;
                q.push(current -> left);
            }

            if (current -> right != NULL)
            {
                parent_map[current -> right] = current;
                q.push(current -> right);
            }
        }
    }

    TreeNode* findTarget(TreeNode* root, int val) 
    {
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode* left = findTarget(root->left, val);
        if (left) return left;
        return findTarget(root->right, val);
    }

    int amountOfTime(TreeNode* root, int start) 
    {
         // Map: node -> parent
        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParent(root, parent_map);

        // Find the target (start) node
        TreeNode* target = findTarget(root, start);
        if (!target) return 0;

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int mins = -1;

        while(!q.empty())
        {
            int size = q.size();
            mins++;

            for (int i=0; i<size; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                if(current -> left != NULL && !visited[current -> left])
                {
                    q.push(current -> left);
                    visited[current -> left] = true;
                }

                if(current -> right != NULL && !visited[current -> right])
                {
                    q.push(current -> right);
                    visited[current -> right] = true;
                }

                if (parent_map.count(current) && !visited[parent_map[current]])
                {
                    q.push(parent_map[current]);
                    visited[parent_map[current]] = true;
                }
            }
        }

        return mins;
    }
};

//Time Complexity: O(N), markParent(): O(N) + findTarget(): O(N) + BFS: O(N)
//Space Complexity: O(N)

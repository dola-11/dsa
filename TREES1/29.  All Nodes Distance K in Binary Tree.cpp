/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            if (current -> left)
            {
                parent_track[current -> left] = current;
                q.push(current -> left);
            }
            if (current -> right)
            {
                parent_track[current -> right] = current;
                q.push(current -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*, TreeNode*> parent_track; //node->parent;
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int cur_level = 0;

        while(!q.empty())
        {
            int size = q.size();
            if (cur_level ++ == k) break;
            for (int i=0; i<size; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                if (current -> left && !visited[current -> left])
                {
                    q.push(current -> left);
                    visited[current -> left] = true;
                }

                if (current -> right && !visited[current ->right])
                {
                    q.push(current -> right);
                    visited[current -> right] = true;
                }


                //This part of the code is responsible for traversing upward in the binary tree from the current node to its parent.
                if (parent_track.count(current) && !visited[parent_track[current]]) 
                {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int>result;
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current -> val);
        }
        return result;
    }
};

/*
Time Complexity: O(N) — we visit each node at most once.

Space Complexity: O(N) — due to queue and map storage.


1. parent_track.count(current)
parent_track is a map that keeps track of each node's parent.
count(current) checks if the current node has a recorded parent.
This avoids accessing a non-existent key (e.g., for the root node, which has no parent).

2. !visited[parent_track[current]]
Ensures that we haven't already visited the parent of the current node.
This prevents cycles and infinite loops in the BFS.

3. q.push(parent_track[current])
If both conditions above are met, the parent node is added to the BFS queue to explore it in the next level.

4. visited[parent_track[current]] = true
Marks the parent node as visited immediately to avoid processing it again.
*/

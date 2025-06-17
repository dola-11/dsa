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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int vert = p.second.first;
            int level = p.second.second;

            nodes[vert][level].insert(node->val);
            if(node -> left)
            {
                q.push({node->left,{vert-1,level+1}});
            }

            if(node -> right)
            {
                q.push({node -> right,{vert+1,level+1}});
            }
        }

        vector<vector<int>>ans;
        for (auto p:nodes)
        {
            vector<int> col;
            for (auto q:p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

/*

Time Complexity: O(n log n)
Space Complexity: O(n), For queue and nodes map


        3
       / \
      9   20
         /  \
        15   7

        

          3(0,0)
         /     \
     9(-1,1)   20(1,1)
             /      \
         15(0,2)   7(2,2)

//nodes
{
 -1: {1: {9}},
  0: {0: {3}, 2: {15}},
  1: {1: {20}},
  2: {2: {7}}
}

OUTPUT
[
  [9],
  [3, 15],
  [20],
  [7]
]


*/

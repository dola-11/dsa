//this one is for right
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
    void recursion(TreeNode* root, int level, vector<int>&result)
    {
        if (root == NULL) return;

        if (result.size() == level) result.push_back(root -> val);
        recursion(root -> right, level +1, result);
        recursion(root -> left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>result;
        recursion(root, 0, result);
        return result;
    }
};

//TC:O(N)
//SC: In worst case (skewed tree) = O(H), where H is height of the tree → up to O(N), Result vector: Stores at most H elements (one per level) → O(H)


//for left just call left before right

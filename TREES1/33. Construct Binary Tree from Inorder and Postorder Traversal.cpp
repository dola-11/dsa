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
    TreeNode* buildingTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& inMap)
    {
        if (inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root -> left = buildingTree(inorder, inStart, inRoot-1, postorder, postStart, postStart + numsLeft-1, inMap);
        root -> right = buildingTree(inorder, inRoot+1, inEnd, postorder, postStart + numsLeft, postEnd-1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (inorder.size() != postorder.size()) return NULL;

        map<int,int> inMap;

        for (int i=0; i<inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        return buildingTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1,inMap);
    }
};

//TC : O(N) or O(nlogn) depending on map
//SC : O(N)

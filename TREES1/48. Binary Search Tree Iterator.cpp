// a BST Iterator that gives the next smallest element in the BST, one at a time (in-order traversal using a stack).

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
class BSTIterator {
public:
    stack <TreeNode*> myStack;

    BSTIterator(TreeNode* root) 
    {
        pushAll(root);
    }
    
    int next() 
    {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode -> right);
        return tmpNode -> val;
    }
    
    bool hasNext() 
    {
        return !myStack.empty();
    }

    void pushAll(TreeNode* node)
    {
        for (; node != NULL; myStack.push(node), node = node -> left); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
while (node != NULL) {
    myStack.push(node);
    node = node->left;
}


✅ Time for next() and hasNext():

Each node is pushed/popped at most once → amortized O(1) per next()
✅ Space:

O(h) where h = height of tree → stack depth

*/

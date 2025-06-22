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
class BSTiterator
{
    public:
        stack<TreeNode*> myStack;
        //reverse -> true -> before
        //reverse -> false -> next
        bool reverse = true;

        BSTiterator(TreeNode* root, bool isReverse)
        {
            reverse = isReverse;
            pushAll(root);
        }

        void pushAll(TreeNode* node)
        {
            while(node != NULL)
            {
                myStack.push(node);
                if (reverse == true)
                {
                    node = node -> right;
                }
                else
                {
                    node = node -> left;
                }
            }
        }

        bool hasNext()
        {
            return !myStack.empty();
        }

        int next()
        {
            TreeNode* tmp = myStack.top();
            myStack.pop();
            if (!reverse)
            {
                pushAll(tmp -> right);
            }
            else
            {
                pushAll(tmp -> left);
            }
            return tmp -> val;
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if (!root) return false;
        //next
        BSTiterator l(root,false);
        //before
        BSTiterator r(root,true);

        int i = l.next();
        int j = r.next();
        while(i<j)
        {
            if (i+j == k) return true;
            else if (i+j<k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

/*
✅ Time:

Each node visited at most once → O(n)

✅ Space:

O(h) stack space for each iterator → O(h)

Where h = height of tree → O(log n) balanced, O(n) skewed
*/

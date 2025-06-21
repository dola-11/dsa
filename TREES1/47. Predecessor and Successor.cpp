/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* successor(Node* root, int key)
    {
        Node* succesor = NULL;
        
        while(root != NULL)
        {
            if (key >= root -> data)
            {
                root = root ->right;
            }
            else
            {
                succesor = root;
                root = root -> left;
            }
        }
        return succesor;
    }
    
    Node* predecessor(Node* root, int key)
    {
        Node* predecessor = NULL;
        
        while(root != NULL)
        {
            if ( key <= root -> data)
            {
                root = root -> left;
            }
            else
            {
                predecessor = root;
                root = root -> right;
            }
        }
        return predecessor;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) 
    {
        // code here
        vector<Node*>ans;
        
        ans.push_back(predecessor(root, key));
        ans.push_back(successor(root, key));
        
        return ans;
    }
};

//Time: O(h) → height of BST (log n if balanced, n if skewed)
//Space: O(1) → no extra space except pointers

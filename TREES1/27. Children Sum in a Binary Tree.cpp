/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.

    int isSumProperty(Node *root) 
    {
        // Add your code here
        if (!root) return 1;
        if (!root->left && !root->right) return 1;
        
        int left_data = 0, right_data = 0;
        
        if (root->left) left_data = root->left->data;
        if (root->right) right_data = root->right->data;
        
        if ((root->data == left_data + right_data) &&
            isSumProperty(root->left) &&
            isSumProperty(root->right))
            return 1;
        else
            return 0;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(H) Due to the recursion stack, where H is the height of the tree. In the worst case (skewed tree), H = N.

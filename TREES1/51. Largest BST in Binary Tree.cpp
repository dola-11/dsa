/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
  public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this -> minNode = minNode;
        this -> maxNode = maxNode;
        this -> maxSize = maxSize;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue largestBSTSubtreeHelper(Node* root)
    {
        //Empty tree is a BST of size 0
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        //get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root -> left);
        auto right = largestBSTSubtreeHelper(root -> right);
        
        //current node is greater than max in left AND smaller than min in right, it is a BST
        if (left.maxNode < root -> data && root -> data < right.minNode)
        {
            //it is a BST
            return NodeValue(min(root -> data, left.minNode), max(root -> data, right.maxNode),left.maxSize + right.maxSize + 1);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root) 
    {
        // Your code here
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

| Measure   | Complexity                                                             |
| --------- | ---------------------------------------------------------------------- |
| **Time**  | O(n) — Each node is visited once                                       |
| **Space** | O(h) — h = height of the tree (O(log n) for balanced, O(n) for skewed) |

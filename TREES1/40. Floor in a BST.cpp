// User function Template for C++

// Function to return the floor of given number in BST.
int floor(Node* root, int key) 
{
    // Your code goes here
    int floor = -1;
    while(root)
    {
        if (root -> data == key)
        {
            floor = root -> data;
            return floor;
        }
        if (root -> data > key)
        {
            root = root -> left;
        }
        else
        {
            floor = root -> data;
            root = root -> right;
        }
    }
    return floor;
}


//TC : O(logn)
//SC : O(1)

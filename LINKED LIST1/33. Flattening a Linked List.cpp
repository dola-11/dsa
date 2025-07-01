/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeTwo(Node* list1, Node* list2)
    {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        
        while(list1 != NULL && list2 != NULL)
        {
            if (list1 -> data < list2 -> data)
            {
                res -> bottom = list1;
                res = list1;
                list1 = list1 -> bottom;
            }
            else
            {
                res -> bottom = list2;
                res = list2;
                list2 = list2 -> bottom;
            }
            res -> next = nullptr;
        }
        
        if (list1) res -> bottom = list1;
        else
        {
            res -> bottom = list2;
        }
        if(dummyNode -> bottom)
        {
            dummyNode -> bottom -> next = nullptr;
        }
        
        return dummyNode -> bottom;
    }
    
    Node *flatten(Node *root) 
    {
        // Your code here
        if (root == NULL || root -> next == NULL)
        {
            return root;
        }
        
        Node* mergedHead = flatten(root -> next);
        root = mergeTwo(root,mergedHead);
        return root;
    }
};

//TC : O(N * M) where N is the number of columns and M is average depth — since each merge is linear
//SC :  O(1) extra (in-place) + O(N) recursive stack

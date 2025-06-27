// DELETING HEAD

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};

*/
// Complete this function
Node *deleteHead(Node *head) 
{
    // Your code here
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}
//TC : O(1)
//SC : O(1)


//DELETING TAIL

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};

*/
// Complete this function
Node *deleteTail(Node *head) 
{
    // Your code here
    if (head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp -> next;
    }    
    free(temp -> next);
    temp -> next = nullptr;
    return head;
}
//TC : O(N)
//SC : O(1)

//Deleting a node in a LL
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) 
    {
        // code here
        if (head == nullptr) return NULL;
        
        if (x == 1)
        {
            Node* temp = head;
            head = head -> next;
            free(temp);
            return head;
        }
        
        Node* temp= head;
        for (int i=1; temp!=nullptr && i<x-1; i++)
        {
            temp = temp -> next;
        }
        
        if (temp == nullptr || temp -> next == nullptr)
        {
            return head;
        }
        
        Node* nodeToDelete = temp -> next;
        temp -> next = temp -> next -> next;
        free(nodeToDelete);
        return head;
    }
};

//TC : O(n)
//SC : O(1)

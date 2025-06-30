/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) 
    {
        // Your code here
        Node* temp = head;
        
        while(temp!= NULL && temp -> next!= NULL)
        {
            Node* nextNode = temp -> next;
            
            while (nextNode != NULL && temp -> data == nextNode -> data)
            {
                Node* duplicate = nextNode;
                nextNode = nextNode -> next;
                delete duplicate;
            }
            
            temp -> next = nextNode;
            if (nextNode) nextNode -> prev = temp;
            
            temp = temp -> next;
        }
        
        return head;
    }
};

//TC : O(N)
//SC : O(1)

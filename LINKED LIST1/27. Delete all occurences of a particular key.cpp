// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) 
    {
        // Write your code here
        //head_ref is a pointer to the head pointer
        Node* current = *head_ref;
        
        while(current != NULL)
        {
            if (current -> data == x)
            {
                if (current -> prev == NULL)
                {
                    *head_ref = current -> next;
                }
                Node* nextNode = current -> next;
                Node* prevNode = current -> prev;
                
                if(nextNode!=NULL)
                {
                    nextNode -> prev = prevNode;
                }
                
                if(prevNode!=NULL)
                {
                    prevNode -> next = nextNode;
                }
                
                delete current;
                current = nextNode;
            }
            
            else
            {
                current = current -> next;
            }
        }
    }
};

//TC : O(N)
//SC : O(1)

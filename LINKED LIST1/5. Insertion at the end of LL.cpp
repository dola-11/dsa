/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) 
    {
        // Code here
        if (head == nullptr)
        {
            return new Node(x);
        }
        
        Node* temp = head;
        while(temp -> next!=NULL)
        {
            temp = temp -> next;
        }
        temp -> next = new Node(x);
        return head;
    }
};

//TC : O(N) - worst case
//SC : O(1)

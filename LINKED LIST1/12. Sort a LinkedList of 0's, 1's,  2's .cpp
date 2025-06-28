/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) 
    {
        // code here
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* temp = head;
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        while(temp!=nullptr)
        {
            if(temp->data == 0)
            {
                zero -> next = temp;
                temp = temp -> next;
                zero = zero -> next;
                
            }
            else if (temp -> data == 1)
            {
                one -> next = temp;
                temp = temp -> next;
                one = one -> next;
            }
            else if (temp -> data == 2)
            {
                two -> next = temp;
                temp = temp -> next;
                two = two -> next;
            }
        }
        zero -> next = oneHead -> next;
        one -> next = twoHead -> next;
        two->next = nullptr; 
        return zeroHead -> next;
    }
};

//TC : O(N)
//SC : O(1)

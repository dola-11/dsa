/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) 
    {
        // code here
        Node* newNode = new Node(data);
        Node* temp = head;
        
        int count = 0;
        while (temp != NULL && count < pos) 
        {
            temp = temp->next;
            count++;
        }
        
        Node* after = temp->next;
        temp -> next = newNode;
        newNode -> prev = temp;
        newNode->next = after;
        
        if (after != NULL) 
        {
            after->prev = newNode;
        }
        return head;
    }
};

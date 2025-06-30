/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* deleteHead(Node* head)
    {
        if (head == nullptr) return nullptr;
        
        Node* temp = head;
        head = head -> next;
        
        if (head != nullptr) 
        {
            head->prev = nullptr;
        }
        
        temp -> next = nullptr;
        delete temp;
        return head;
    }
    
    Node* deleteTail(Node* head)
    {
        if (head == nullptr || head->next == nullptr) 
        {
            // Only one node in list
            delete head;
            return nullptr;
        }
        
        Node* temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        
        Node* secondlast = temp -> prev;
        secondlast -> next = nullptr;
        temp -> prev = nullptr;
        delete temp;
        return head;
    }
    // Function to delete a node at given position.
    
    Node* deleteNode(Node* head, int x) 
    {
        // Your code here
        if (head == NULL)
        {
            return NULL;
        }
        
        if (x == 1) 
        {
            return deleteHead(head);
        }
        
        Node* current = head;
        int count = 1;
        
        while (current != nullptr && count < x) 
        {
            current = current->next;
            count++;
        }
        
        if (current == nullptr) 
        {
            // Invalid position
            return head;
        }
        
        if (current->next == nullptr) 
        {
            return deleteTail(head);
        }
        
        
        Node* back = current -> prev;
        Node* front = current -> next;
        
     
        back -> next = front;
        front -> prev = back;
        
        current -> next = nullptr;
        current -> prev = nullptr;
        delete current;
        return head;
    }
};

| Operation          | Time | Space |
| ------------------ | ---- | ----- |
| `deleteHead`       | O(1) | O(1)  |
| `deleteTail`       | O(n) | O(1)  |
| `deleteNode` (any) | O(n) | O(1)  |

class Solution {
  public:
    // Function to insert a node at the begining of the linked list.
    Node *insertAtBegining(Node *head, int x)
    {
        // Code here
        Node* temp = new Node(x);
        temp -> next = head;
        return temp;
    }
};

//O(1) - SC,TC

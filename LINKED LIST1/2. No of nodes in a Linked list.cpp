/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) 
    {
        int count = 0;
        Node* temp = head;
        // Code here
        while(temp!=nullptr)
        {
            temp = temp -> next;
            count++;
        }
        return count;
    }
};

//TC : O(N)
//SC : O(N)

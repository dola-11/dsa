/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int findLength(Node* slow, Node* fast)
    {
        int cnt = 1;
        fast = fast -> next;
        while(slow != fast)
        {
            cnt++;
            fast = fast -> next;
        }
        return cnt;
    }
    
    int countNodesinLoop(Node *head) 
    {
        // Code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!= NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) return findLength(slow, fast);
        }
        return 0;
    }
};

/*
In the worst case (i.e., no cycle), both pointers traverse the list once → O(n).
If a cycle exists, then:
Detecting the cycle takes O(m + k), where:
m = nodes before cycle starts,
k = length of the cycle.
Counting the cycle length takes O(k) (you traverse the cycle once).
Hence, total time is O(n), where n is the total number of nodes.
  
Space Complexity: O(1)
  */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertCopyBetween(Node* head)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            Node* copynode = new Node(temp -> val);
            copynode -> next = temp -> next;
            temp -> next = copynode;
            temp = temp -> next -> next;
        }
    }

    void connectRandomPtrs(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            Node* copynode = temp -> next;

            if (temp -> random == NULL)
            {
                copynode -> random = NULL;
            }
            else
            {
                copynode -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
    }

    Node* getDeepcopyList(Node* head)
    {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != NULL)
        {
            //creating a new list
            res -> next = temp -> next;
            res = res -> next;

            //disconnecting 
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }


    Node* copyRandomList(Node* head) 
    {
        if (head == NULL)
        {
            return NULL;
        }
        insertCopyBetween(head);
        connectRandomPtrs(head);
        return getDeepcopyList(head);
    }
};

//TC : O(3N)
//SC : O(N) - for making the clone

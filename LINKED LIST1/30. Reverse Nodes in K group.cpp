/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* temp)
    {
        ListNode* prev = NULL;
        ListNode* current = temp;

        while(current!=NULL)
        {
            ListNode* nextNode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextNode;
        }
        return temp;
    }
    ListNode* getKthNode(ListNode* temp, int k)
    {
        k = k-1;
        while(temp!=NULL && k>0)
        {
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        
        while(temp!=NULL)
        {
            ListNode* kthNode = getKthNode(temp,k);
            if (kthNode == NULL)
            {
                if(prevNode)
                {
                    prevNode -> next = temp;
                    break;
                }
            }
            ListNode* nextNode = kthNode -> next;
            kthNode -> next = NULL;

            reverseLL(temp);
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevNode -> next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

//TC : Total = (n/k) groups × O(2k) per group = O(2n)
//SC : O(1)

//try the recursive solution 

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            ListNode* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL || head -> next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reverseList(slow -> next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL)
        {
            if(first->val != second -> val)
            {
                reverseList(newHead);
                return false;
            }

            first = first -> next;
            second = second -> next;
        }

        reverseList(newHead);
        return true;
    }
};

//TC : O(2N)
//SC : O(1)

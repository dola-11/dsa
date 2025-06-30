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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k == 0) return head;

        int length = 1;
        ListNode* tail = head;

        while(tail -> next != NULL)
        {
            length ++;
            tail = tail -> next;
        }

        k = k%length;
        if (k == 0) return head;

        int tempPos = length - k - 1;       //0 indexed

        ListNode* temp = head;
        while(tempPos > 0)
        {
            tempPos --;
            temp = temp -> next;
        }

        ListNode* newHead = temp -> next;
        temp -> next = NULL;
        tail -> next = head;
        
        return newHead;
    }
};

| Metric               | Value                                                  |
| -------------------- | ------------------------------------------------------ |
| **Time Complexity**  | `O(n)` — one full pass for length, another for cutting |
| **Space Complexity** | `O(1)` — in-place manipulation                         |

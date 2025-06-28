/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head)
    {
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr!=nullptr)
        {
            Node* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    Node* addOne(Node* head) 
    {
        // Your Code here
        Node* newHead = reverseList(head);
        int carry = 1;
        Node* temp = newHead;
        while(temp != nullptr)
        {
            temp -> data = temp -> data + carry;
            if (temp -> data < 10)
            {
                carry = 0;
                break;
            }
            else
            {
                temp -> data = 0;
                carry = 1;
            }
            temp = temp -> next;
        }
        
        if (carry == 1)
        {
            Node* carryNode = new Node(1);
            head = reverseList(newHead);
            carryNode -> next = head;
            return carryNode;
        }
        
        head = reverseList(newHead);
        return head;
        // return head of list after adding one
    }
};

//TC : O(3N)
//SC : O(1)

//Recursive solution (backtracking)

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int addHelper(Node* temp)
    {
        if (temp == NULL)
        {
            return 1;
        }
        
        int carry = addHelper(temp -> next);
        temp -> data += carry;
        if (temp -> data < 10) return 0;
        else
        {
            temp -> data = 0;
            return 1;
        }
    }
    Node* addOne(Node* head) 
    {
        // Your Code here
        int carry = addHelper(head);
        if (carry == 1)
        {
            Node* newNode = new Node(1);
            newNode -> next = head;
            head = newNode;
        }
        return head;
        // return head of list after adding one
    }
};

//TC : O(N)
//SC : O(N)

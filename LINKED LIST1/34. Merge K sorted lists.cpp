/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) 
    {
        // Your code here
        priority_queue<pair<int,Node*>,
        vector<pair<int,Node*>>,
        greater<pair<int,Node*>>>pq;
        
        for (int i=0; i<arr.size(); i++)
        {
            if(arr[i])
            {
                pq.push({arr[i] -> data, arr[i]});
            }
        }
        
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(!pq.empty())
        {
            pair<int,Node*> p = pq.top();
            temp -> next = p.second;
            pq.pop();
            if (p.second -> next)
            {
                pq.push({p.second -> next -> data, p.second -> next});
            }
            temp = temp -> next;
        }
        
        return dummyNode -> next;
    }
};

//TC : K*LogK + N*K*logK*3
//SC : O(K)
//k is the number of lists, at the worst case the time complexity can tend to n^2, which is better than the recursive solution of merging 2 at a time which tends to n^3 

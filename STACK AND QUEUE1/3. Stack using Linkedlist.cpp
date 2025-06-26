class Node{
public:
    int data;
    Node* next;
    Node (int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedListStack {
public:
    Node* topNode;
    int size;

    LinkedListStack() 
    {
        topNode = nullptr;
        size = 0;
    }
    
    void push(int x) 
    {
        Node* temp = new Node(x);
        temp -> next = topNode;
        topNode = temp;
        size = size+1;
    }
    
    int pop() 
    {
        if (topNode == nullptr) return -1;

        int val = topNode -> data;
        Node* temp = topNode;
        topNode = topNode -> next;
        delete temp;
        size = size - 1;
        return val;
    }
    
    int top() 
    {
        if (topNode == nullptr) return -1;
        return topNode -> data;
    }
    
    bool isEmpty() 
    {
        return (size == 0);
    }
};

| Metric                 | Complexity |
| ---------------------- | ---------- |
| Time per operation     | O(1)       |
| Space (for N elements) | O(N)       |

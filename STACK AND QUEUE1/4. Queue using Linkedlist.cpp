class Node{
public:
    int data;
    Node* next;

    Node(int val)
    {
        next = nullptr;
        data = val;
    }
};

class LinkedListQueue {
public:
    Node* start;
    Node* end;
    int size;

    LinkedListQueue() 
    {
        start = nullptr;
        end = nullptr;
        size = 0;
    }
    
    void push(int x) 
    {
        Node* temp = new Node(x);
        if (start == nullptr)
        {
            start = end = temp;
        }
        else
        {
            end -> next = temp;
            end = temp;
        }
        size ++;
    }
    
    int pop() 
    {
        if (start == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        Node* temp = start;
        int val = temp -> data;
        start = start -> next;

        if (start == nullptr)
        {
            end = nullptr;
        }

        delete(temp);
        size--;
        return val;
    }
    
    int peek() 
    {
        if (start == nullptr) return -1;
        return start -> data;
    }
    
    bool isEmpty() 
    {
        return (start == nullptr);
    }
};

| Operation   | Time | Extra Space |
| ----------- | ---- | ----------- |
| `push()`    | O(1) | O(1)        |
| `pop()`     | O(1) | O(1)        |
| `peek()`    | O(1) | O(1)        |
| `isEmpty()` | O(1) | O(1)        |
Total space = O(N) where N = number of elements in the queue (for nodes).

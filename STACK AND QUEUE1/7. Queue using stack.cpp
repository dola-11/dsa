class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;

    MyQueue() {
        
    }
    
    void push(int x) 
    {
        s1.push(x);
    }
    
    int pop() 
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() 
    {
        if (s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() 
    {
       return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

| Operation | Time                                                                                     |
| --------- | ---------------------------------------------------------------------------------------- |
| `push(x)` | O(1)                                                                                     |
| `pop()`   | Amortized O(1) — O(N) when s2 is empty, but overall each element moves from s1 → s2 once |
| `peek()`  | Amortized O(1)                                                                           |
| `empty()` | O(1)                                                                                     |


  Space = O(N), where N is number of elements in queue (stored in the two stacks).


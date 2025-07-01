class Node{
public:
    string data;
    Node* next;
    Node* back;
    Node() : data(""), next(nullptr),  back(nullptr) {}
    Node(string x) : data(x), next(nullptr), back(nullptr) {}
    Node(string x, Node* next, Node* random) : data(x), next(next), back(random){}
};

class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) 
    {
        current = new Node(homepage);
    }
    
    void visit(string url) 
    {
        Node* newNode = new Node(url);
        current->next = nullptr; 
        newNode->back = current;
        current -> next = newNode;
        current = newNode;
    }
    
    string back(int steps) 
    {
        while(steps > 0 && current->back != nullptr)
        {
            current = current -> back;
            steps --;
        }
        return current ->data;
    }
    
    string forward(int steps) 
    {
        while(steps > 0 && current->next != nullptr)
        {
            current = current ->next;
            steps --;
        }
        return current -> data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

| Operation   | Time                 | Space |
| ----------- | -------------------- | ----- |
| `visit()`   | O(1)                 | O(1)  |
| `back()`    | O(k) where k = steps | O(1)  |
| `forward()` | O(k) where k = steps | O(1)  |

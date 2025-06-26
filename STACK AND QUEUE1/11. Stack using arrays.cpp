// Function to push an integer into the stack.
class ArrayStack {
public:
    int topPt;
    int arr[1000];
    ArrayStack() 
    {
        topPt = -1;
    }
    
    void push(int x) 
    {
        topPt = topPt + 1;
        arr[topPt] = x;
    }
    
    int pop() 
    {
        if (topPt == -1) return -1;
        int value = arr[topPt];
        topPt = topPt - 1;
        return value;
    }
    
    int top() 
    {
        if (topPt == -1) return -1;
        return arr[topPt];
    }
    
    bool isEmpty() 
    {
        return (topPt == -1);
    }
};


/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) 
{
    // Your Code
    top = top + 1;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if (top == -1) return -1;
    int value = arr[top];
    top = top - 1;
    return value;
}

//TC : O(1)
//SC : O(1)




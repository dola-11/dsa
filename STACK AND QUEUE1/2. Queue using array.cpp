class ArrayQueue {
public:
    int start;
    int end;
    int arr[1000];
    int cursize;
    const int size = 1000;

    ArrayQueue() 
    {
        start = -1;
        end = -1;
        cursize = 0;
    }
    
    void push(int x) 
    {
        if (cursize == size)
        {
            // Queue is full
            cout << "Queue Overflow" << endl;
            return;
        }

        if (cursize == 0)
        {
            start = 0;
            end = 0;
        }

        else
        {
            end = (end + 1) %size;
        }
        arr[end] = x;
        cursize ++;
    }
    
    int pop() 
    {
        if (cursize == 0) return -1;
        int el = arr[start];
        if (cursize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1)% size;
        }
        cursize --;
        return el;
    }
    
    int peek() 
    {
        if (cursize == 0) return -1;
        else
        {
            return arr[start];
        }
    }
    
    bool isEmpty() 
    {
        return (cursize == 0);
    }
};

//TC : O(1)
//SC : O(1)

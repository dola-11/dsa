//Method 1:

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

//Time Complexity: O(1)
//Space Complexity: O(2N)

//Method 2:
class MinStack {
public:
    stack<long long> st;
    long long min;

    MinStack() 
    {
        min = INT_MAX;
    }
    
    void push(int val) 
    {
        long long v = 1LL * val;
        if (st.empty())
        {
            min = v;
            st.push(v);
        }
        else if (v > min) st.push(v);
        else
        {
            st.push(2*v - min);
            min = v;
        }
    }
    
    void pop() 
    {
        if(st.empty())
        {
            return;
        }

        long long el = st.top();
        st.pop();
        if (el < min)
        {
            min = 2*min - el;
        }
    }
    
    int top() 
    {
        if(st.empty())
        {
            return -1;
        }
        long long el = st.top();
        if (el<min)
        {
            return min;
        }
        return el;
    }
    
    int getMin() 
    {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//Time Complexity: O(1)
//Space Complexity: O(N)

//largest

class Solution {
  public:
    int largest(vector<int> &arr) 
    {
        // code here
        int largest = 0;
        for (int i=0; i<arr.size();i++)
        {
            if(arr[i]>largest)
            {
                largest = arr[i];
            }
        }
        return largest;
    }
};
//TC : O(n)

//2nd largest

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) 
    {
        // code here
        int n = arr.size();
        int largest = INT_MIN;
        int secondlargest = INT_MIN;
        
        for (int i=0; i<n; i++)
        {
            if (arr[i]>largest)
            {
                secondlargest =largest;
                largest = arr[i];
            }
            else if (arr[i] > secondlargest && arr[i] != largest)
            {
                secondlargest = arr[i];
            }
        }
        return secondlargest == INT_MIN ? -1 : secondlargest;  //if all the elements end up being the same
    }
};

//TC : O(n)
//SC : O(1)

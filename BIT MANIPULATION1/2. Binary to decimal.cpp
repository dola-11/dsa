class Solution {
  public:
    int binaryToDecimal(string &b) 
    {
        // Code here.
        int len = b.length();
        int p2 = 1;
        int num = 0;
        
        for(int i = len-1; i>=0; i--)
        {
            if(b[i] == '1')
            {
                num += p2;
            }
            p2 = p2*2;
        }
        return num;
    }
};

//TC : O(len)
//SC : O(1)

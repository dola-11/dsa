// User function Template for C++

void toBinary(int n) 
{
    // your code here
    if (n==0)
    {
        cout << '0';
        return;
    }
    
    string res = "";
    while(n > 0)
    {
        if (n%2 == 1)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
        n = n/2;
    }
    
    reverse(res.begin(),res.end());
    cout << res;
}


//SC : O(log₂ n)
//TC :O(log₂ n)

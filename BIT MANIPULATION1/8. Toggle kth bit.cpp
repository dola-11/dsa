int toggleKthBit(int n, int k)
{
    return (n ^ (1 << (k-1)));
}

//TC : O(1)
//SC : O(1)

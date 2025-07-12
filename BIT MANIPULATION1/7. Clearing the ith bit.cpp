int clearBit(int n, int i) 
{
  int mask = ~(1 << i);
  return n & mask;
}

//SC : O(1)
//TC : O(1)

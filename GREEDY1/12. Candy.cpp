//Method 1
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int>candies(n,1);

        for (int i=1; i<n; i++)
        {
            if (ratings[i]>ratings[i-1])
            {
                candies[i] = candies[i-1] + 1;
            }
        }       
        
        for (int i=n-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candies[i] = max(candies[i],candies[i+1]+1);
            }
        }    

        int minCandies = 0;
        for (int i=0; i<n; i++)
        {
            minCandies += candies[i];
        }
        return minCandies;
    }
};

//TC : O(3N)
//Sc : O(N)

//Method 2
//slope method
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        int i=1;
        int sum=1;
        while(i<n) 
        {
            if(ratings[i]==ratings[i-1]) 
            {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]) 
            {
                peak+=1;
                i++;
                sum+=peak;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]) 
            {
                down+=1;
                i++;
                sum+=down;
            }
            down++;
            if(down>peak) {
                sum+=down-peak;
            }
        }
        return sum;
    }
};

//TC : O(N)
//SC : O(1)

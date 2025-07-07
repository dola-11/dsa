// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool comp(pair<int,int>a, pair<int,int>b)
    {
        double r1 = (double) a.first / a.second;
        double r2 = (double) b.first / b.second;
        return r1>r2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int n = val.size();
        vector<pair<int,int>> items(n);
        
        for(int i=0; i<n; i++)
        {
            items[i] = {val[i],wt[i]};
        }
        
        sort(items.begin(), items.end(), comp);
        
        double totalValue = 0.0;
        
        for (int i=0; i<n; i++)
        {
            int currValue = items[i].first;
            int currWeight = items[i].second;
            
            if (currWeight <= capacity)
            {
                totalValue += currValue;
                capacity = capacity - currWeight;
            }
            else
            {
                totalValue += (double)currValue * ((double)capacity/currWeight);
                break;
            }
        }
        
        return totalValue;
    }
};

//TC : 	O(n log n) + O(n)
//SC : O(1)


//struct approach

//given:
struct Item {
    int value;
    int weight;
};


class Solution {
  public:
    // Comparator to sort items by value-to-weight ratio in descending order
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2; // higher ratio comes first
    }

    double fractionalKnapsack(int capacity, Item items[], int n) 
    {
        // Step 1: Sort items by value/weight ratio
        sort(items, items + n, cmp);

        double totalValue = 0.0;

        // Step 2: Pick items greedily
        for (int i = 0; i < n; i++) {
            if (capacity >= items[i].weight) {
                // take full item
                capacity -= items[i].weight;
                totalValue += items[i].value;
            } else {
                // take fractional part
                totalValue += (double)items[i].value * ((double)capacity / items[i].weight);
                break; // knapsack is full
            }
        }

        return totalValue;
    }
};

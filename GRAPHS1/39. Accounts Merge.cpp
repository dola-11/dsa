class DisjointSet{
public:
    vector<int>parent, size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<n+1; i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if (parent[node] == node) return node;
        else
        {
            return parent[node] = findUparent(parent[node]);
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> mapMailNode;

        for (int i=0; i<n; i++)
        {
            for (int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for (auto it: mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUparent(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i=0; i<n; i++)
        {
            if (mergedMails[i].size() == 0) continue;
            sort (mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMails[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//TC : O(k α(n)) + O(k log k) = O(k⋅α(n)+klogk)
//O(n+k)

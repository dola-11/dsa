//basic code concept as in TUF

class Solution {
public:
    vector<int>topo(int k, vector<int>adj[])
    {
        vector<int>inDegree(k,0);
        for (int i=0; i<k; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<k; i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>topoSort;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topoSort;
    }

	string findOrder(string dict[], int N, int K) 
    {
		vector<int>adj[K];
        for (int i=0; i<N-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for (int ptr = 0; ptr <len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }

        vector<int>topoSort = topo(K,adj);
        string ans = "";
        for (auto it:topoSort)
        {
            ans = ans + char(it + 'a');
        }
        return ans;
	}
};

//GFG SOLUTION
class Solution {
  public:
    vector<int> topoSort(int k, vector<vector<int>>&adj, bool &hasCycle, vector<bool> &present)
    {
        vector<int>inDegree(k,0);
        
        for (int i=0; i<k; i++)
        {
            for (auto it: adj[i])
            {
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0; i<k; i++)
        {
            if (inDegree[i] == 0 && present[i])
            {
                q.push(i);
            }
        }
        
        vector<int>topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (auto it: adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        //count the no of elements that are true in the present vector
        int countPresent = count(present.begin(), present.end(), true);
        if (topo.size() != countPresent)
        {
            hasCycle = true;
        }
        
        return topo;
        
    }
    string findOrder(vector<string> &words) 
    {
        // code here
        const int K = 26;
        int N = words.size();
        vector<vector<int>>adj(K,vector<int>(0));
        vector<bool>present(K,false);
        
        //checking which letters are present in the provided words
        for (const string &word : words)
        {
            for (char c : word)
            {
                present[c-'a'] = true;
            }
        }
        
        //i'll make an adjacency list out of the order of letters according to the words
        for (int i=0; i<N-1; i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            
            bool found = false;
            for (int ptr=0; ptr<len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr]-'a');
                    found = true;
                    break;
                }
            }
            
            //1st fail condition
            //deals with cases where the larger string appears before the smaller string and everything is matching
            if (!found && s1.size()>s2.size())
            {
                return "";
            }
        }
        
        //2nd fail condition
        //cycle detection (toposort works only in DAGs)
        bool hasCycle = false;
        vector<int>topo = topoSort(K,adj,hasCycle, present);
        if (hasCycle) return "";
        
        string ans = "";
        for (int i : topo)
        {
            ans = ans + (char)(i + 'a');
        }
        
        return ans;
    }
};

// TC : Building graph: O(N * L) + Topological sort: O(V + E) ≈ O(E) = O(N * L + E) (Where E ≤ K * K)
//Adjacency list stores up to E edges: O(E) 
//The present array: O(K)
//The inDegree array: O(K)
//Queue and topo result: O(K)
//SC : 	O(E + K)
//Constants : K = 26 fixed small

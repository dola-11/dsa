class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push ({beginWord});
        vector<string> usedOnlevel;
        usedOnlevel.push_back(beginWord);

        int level = 0;
        vector<vector<string>>ans;

        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            //erase all words that have been used in the previous level to transform
            if (vec.size() > level)
            {
                level ++;
                for (auto it: usedOnlevel)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();

            if (word == endWord)
            {
                //first sequence where we reached the end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for (int i=0; i<word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);

                        //mark as visited on that particular level
                        usedOnlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//the above code gives TLE in leetcode but is accepted in interviews.


//cp level code

class Solution {
public:
    void dfs(string word, vector<string> & seq, string b, vector<vector<string>> &ans, unordered_map<string,int> &mpp)
    {
        if (word == b)
        {
            reverse (seq.begin(), seq.end());
            ans.push_back(seq);
            reverse (seq.begin(), seq.end());
            return;
        }

        int sz = b.size();
        int steps = mpp[word];
        for (int i = 0; i<sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <='z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word]+1 == steps) 
                {
                    seq.push_back(word);
                    dfs(word,seq,b,ans,mpp);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string,int>mpp;
        vector<vector<string>> ans;
        queue<string>q;
        string b = beginWord;
        q.push({beginWord});
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i<sz; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq,b,ans,mpp);
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root)
        {
			//your code goes here
            stack<pair<TreeNode*,int>> st;
            vector<vector<int>> ans;

            vector<int>preorder;
            vector<int>inorder;
            vector<int>postorder;

            if(root == NULL) return ans;

            st.push({root,1});
            while(!st.empty())
            {
                auto it = st.top();
                st.pop();

                //for pre, increment 1 to 2 and push the left side of the tree
                if (it.second == 1)
                {
                    preorder.push_back(it.first -> data);
                    st.push({it.first,2});

                    if(it.first -> left != NULL)
                    {
                        st.push({it.first -> left, 1});
                    }
                }

                //for in, increment 2 to 3 and push the right side of the tree
                else if (it.second == 2)
                {
                    inorder.push_back(it.first -> data);
                    it.second++;
                    st.push(it);

                    if(it.first -> right != NULL)
                    {
                        st.push({it.first -> right,1});
                    }
                }

                //dont push it back again
                else
                {
                    postorder.push_back(it.first -> data);
                }
            }
            ans.push_back(preorder);
            ans.push_back(inorder);
            ans.push_back(postorder);
            return ans;
		}
};


//TC : O(N)
//SC : O(N) (worst case)

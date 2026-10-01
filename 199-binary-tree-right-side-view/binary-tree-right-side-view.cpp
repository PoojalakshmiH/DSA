/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        if(root==NULL)
        {
            return ans;
        }

        q.push({root,0});

        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
           
            for(int i=0;i<n;i++)
            {
                 auto it =q.front();
                 TreeNode* node=it.first;
                 int dist=it.second;
                 q.pop();
                 level.push_back(node->val);

                 if(node->left!=NULL)
                 {
                    q.push({node->left,dist-1});
                 }

                  if(node->right!=NULL)
                 {
                    q.push({node->right,dist+1});
                 }
                 
            }

            ans.push_back(level.back());    
        }

        return ans;
        
    }
};
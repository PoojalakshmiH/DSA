/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

   void maketree(TreeNode* root , unordered_map<TreeNode*,TreeNode*>&parent)
   {
    if(root==NULL)
    {
        return;
    }

    if(root->left)
    {
      parent[root->left]=root;
      
    }

    if(root->right)
    {
      parent[root->right]=root;
   
    }

    maketree(root->left,parent);
    maketree(root->right,parent);
   }

   void findtarget(TreeNode*root,TreeNode*target,int k, unordered_map<TreeNode*,TreeNode*> &mp,unordered_set<TreeNode*> &vis, vector<int>&ans)
   {

     queue<pair<TreeNode*,int>>q;
     q.push({target,0});
     vis.insert(target);
    

    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        TreeNode* node=it.first;
        int dist=it.second;

        if(dist==k)
        {
            ans.push_back(node->val);
            continue;
        }

        if(node->left!=NULL)
        {   
            if( !vis.count(node->left))
            {
                q.push({node->left,dist+1});
                vis.insert(node->left);
            }
            
        }


         if(node->right!=NULL)
        {   
            if(!vis.count(node->right))
            {
                q.push({node->right,dist+1});
                vis.insert(node->right);
            }
        }

        if(mp.find(node)!=mp.end() && !vis.count(mp[node]))
        {
            q.push({mp[node],dist+1});
            vis.insert(mp[node]);
        }
        



        
    }
   }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>mp;
        
        unordered_set<TreeNode*>vis;
        vector<int>ans;
        

        maketree(root,mp);
        findtarget(root,target,k,mp,vis,ans);
        return ans;
    }
};
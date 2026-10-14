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

    void sum(TreeNode* root, int targetSum, vector<vector<int>>&ans, vector<int> level,int treesum)
    {
        if(root==NULL)
        {
            
            return;
        }
        
        level.push_back(root->val);
        treesum+=root->val;

         if(root->left==NULL && root->right==NULL)
        {
            if(treesum==targetSum)
            {
                
               ans.push_back(level);
            }
            return;
        }
       
        
        sum(root->left,targetSum,ans,level,treesum);
        sum(root->right,targetSum,ans,level,treesum);

        

    }
       
        
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>ans;
       vector<int>level;
       sum(root,targetSum,ans,level,0);
       return ans;
        
    }
};
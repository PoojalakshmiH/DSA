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
     void traversal(TreeNode*root, vector<int> &ans)
     {
        if(root==NULL)
        {
            return;
        }

       
        traversal(root->left,ans);
         ans.push_back(root->val);
        traversal(root->right,ans);

        
     }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>ans;

        traversal(root,ans);
        

       for(int i=0;i<ans.size();i++)
       {
         if(i==k-1)
           return ans[i];
       }

    return 0;
    }
};
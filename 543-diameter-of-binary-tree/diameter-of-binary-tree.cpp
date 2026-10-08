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
    int finddiameter(TreeNode* root,int &ans)
    {
        if(root==NULL)
      {
        return 0;
      }

      int leftval=finddiameter(root->left,ans);
      int rightval=finddiameter(root->right,ans);

      ans=max(ans,leftval+rightval);

      return 1+max(leftval,rightval);


    }
   
    int diameterOfBinaryTree(TreeNode* root) {
      
      if(root==NULL)
      {
        return 0;
      }
      int ans=0;

      finddiameter(root,ans);
      return ans;

        
    }
};
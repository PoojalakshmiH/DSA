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

   int sum(TreeNode* root,int &ans)
   {
     if(root==NULL)
       return 0;

       int leftsum=sum(root->left,ans);
       int rightsum=sum(root->right,ans);

       ans+=abs(leftsum-rightsum);

       return leftsum+rightsum+root->val;
   }
    

    int findTilt(TreeNode* root) {
         int ans=0;
       sum(root,ans);
       return ans;
    }
};
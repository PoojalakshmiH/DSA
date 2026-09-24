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

    void helper(TreeNode* & templeft,TreeNode* &tempright)
    {
        if(templeft ==NULL &&  tempright==NULL)
        {
            return;
        }
        if(templeft!=NULL)
        helper(templeft->left,templeft->right);
         if(tempright!=NULL)
        helper(tempright->left,tempright->right);
        
        TreeNode* temp=templeft;
        templeft=tempright;
        tempright=temp;
    

    }

    TreeNode* invertTree(TreeNode* root) {
        if(root ==NULL)
        {
            return NULL;
        }
        helper(root->left,root->right);
        return root;

    }
};
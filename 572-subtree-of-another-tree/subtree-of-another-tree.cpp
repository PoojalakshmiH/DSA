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

   bool isidentical(TreeNode* p, TreeNode* q)
   {
    if(p==NULL || q==NULL)
    {
        return p==q;
    }

    if(p->val!=q->val)
    {
        return false;
    }

    bool isleftsame =isidentical(p->left,q->left);
    bool isrightsame=isidentical(p->right,q->right);

    return isleftsame&&isrightsame;
   }


 
    bool findsubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL)
        {
            return false;
        }

    if(root->val==subRoot->val&& isidentical(root,subRoot))
    {
        return true;
    }

      return findsubtree(root->left , subRoot) ||findsubtree(root->right ,subRoot);

    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root ==NULL&&subRoot ==NULL)
        {
            return true;
        }
        return findsubtree(root ,subRoot);
    }
};
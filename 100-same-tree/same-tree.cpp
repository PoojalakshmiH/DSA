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

    bool checksame(TreeNode* p, TreeNode* q)
    {
        if(p==NULL ||q==NULL)
        {
            return p==q;
        } 

        if(p->val!=q->val)
        {
            return false;
        }  

        bool leftsame = checksame(p->left,q->left);
        bool rightsame = checksame(p->right,q->right);

        return leftsame&&rightsame;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
      
        return checksame(p,q);
        
    }
};
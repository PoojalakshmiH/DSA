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
    TreeNode* buildtree(vector<int>& nums,int low,int high)
    {
        if(low>high)
        {
            return NULL;
        }

        int maxval=nums[low];
        int idx=low;
        for(int i=low;i<=high;i++)
        {
            if(nums[i] > maxval)
            {
                maxval=max(nums[i],maxval);
                idx=i;
            }
        }
         TreeNode* root = new TreeNode(maxval);
        
        
         root->left =buildtree(nums,low,idx-1);
         root->right =buildtree(nums,idx+1,high);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        
        return buildtree(nums,0,nums.size()-1);
        
        
    }
};
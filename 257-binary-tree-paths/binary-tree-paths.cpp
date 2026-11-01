class Solution {
public:

    void treepaths(TreeNode* root, vector<string>& ans, string path)
    {
        if(root == NULL)
            return;

        // Leaf node
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
            return;
        }

        if(root->left != NULL)
        {
            treepaths(root->left, ans, path + "->" + to_string(root->left->val));
        }

        if(root->right != NULL)
        {
            treepaths(root->right, ans, path + "->" + to_string(root->right->val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        if(root == NULL)
            return ans;

        string path = to_string(root->val);

        treepaths(root, ans, path);

        return ans;
    }
};
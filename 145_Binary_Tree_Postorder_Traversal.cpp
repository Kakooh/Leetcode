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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        postorderTraverse(root, res);
        
        return res;
        
    }
    
private:
    void postorderTraverse(TreeNode* root, vector<int>& res)
    {
        if(root==NULL)
        {
            return;
        }
        
        postorderTraverse(root->left, res);
        postorderTraverse(root->right, res);
        res.push_back(root->val);
    }
};

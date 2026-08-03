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
    
    bool dfs(TreeNode *root,int left,int right)
    {
        if(root==NULL)return true;
        
        if(root->val<=left || root->val>=right)
        {
            return false;
        }
        bool l=true;
        bool r=true;
        if(root->left!=NULL)
        {
            l=dfs(root->left,left,root->val);
        }
        if(root->right!=NULL)
        { 
            r=dfs(root->right,root->val,right);
        }

        return l&r;

    }
    bool isValidBST(TreeNode* root) {

        return dfs(root,INT_MIN,INT_MAX);
    }
};

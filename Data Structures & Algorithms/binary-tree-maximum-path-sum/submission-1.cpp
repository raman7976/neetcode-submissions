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
    int dfs(TreeNode *root,int &maxi)
    {
        if(root==NULL)return INT_MIN;
        maxi = max(maxi,root->val);
         
        int left = dfs(root->left,maxi);
        maxi=max(left,maxi);
        int right = dfs(root->right,maxi);
        maxi=max(right,maxi);
        if(left>=0 && right>=0)
        {
            maxi=max(left+right+root->val,maxi);
        }

        
        int t = max(left,right);
        if(t>0)
        { 
            maxi = max(root->val+t,maxi);
            return root->val + t;

        }
        
        return root->val;

    }
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        int x = dfs(root,maxi);
        return maxi;


    }
};

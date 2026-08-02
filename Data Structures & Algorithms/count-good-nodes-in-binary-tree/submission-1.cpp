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
    void dfs(TreeNode *root,int &count,int maxS)
    {
        if(root==NULL)return;
        if(root->val >=maxS)
        {
            count++;
        }
        maxS = max(maxS,root->val);
        
        if(root->left!=NULL)dfs(root->left,count,maxS);
        if(root->right!=NULL)dfs(root->right,count,maxS);
        return;

    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxS = INT_MIN;
        dfs(root,count,maxS);
        return count;

        
    }
};

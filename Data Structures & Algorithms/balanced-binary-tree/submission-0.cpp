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
    int dfs(TreeNode* root,bool &balanced)
    {
        if(root==NULL)return 0;

        int left = dfs(root->left,balanced);
        int right = dfs(root->right,balanced);
        
        if(abs(left-right)>1)balanced=false;

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool b=true;
        int x;
        x = dfs(root,b);
        return b;

    }
};

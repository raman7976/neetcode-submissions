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
    bool check(TreeNode *p,TreeNode *q)
    {
        if(p==NULL && q==NULL)return true;
        else if(p!=NULL && q==NULL)return false;
        else if(p==NULL && q!=NULL)return false;
        else if(p->val != q->val)return false;

        return check(p->right,q->right) && check(p->left,q->left);
    }

    void dfs(TreeNode *root,TreeNode *subRoot,bool &same)
    {
        if(root==NULL) return;
        
        if(root->val == subRoot->val)
        {
            if(same!=true)
            same = check(root,subRoot);
        }

        dfs(root->left,subRoot,same);

        dfs(root->right,subRoot,same);
        return;
    
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot == NULL) return true;

        bool same = false;
        dfs(root,subRoot,same);
        return same;
    }
};

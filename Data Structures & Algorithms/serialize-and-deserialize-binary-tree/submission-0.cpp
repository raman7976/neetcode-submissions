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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL)
        {
            ans+='#';
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();

            for(int i=0;i<sz;i++)
            {
               TreeNode *x = q.front();
               q.pop();
               if(x!=NULL)
               {ans += to_string(x->val)+",";
                q.push(x->left);
                q.push(x->right);
               }
               else{
                ans+="#,";
               }

            }

        }

        return ans;
       
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#")return NULL;

        vector<string> nodes;
        string temp="";

        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                nodes.push_back(temp);
                temp="";
            }
            else{
                temp+=data[i];
            }
        }

        queue<TreeNode *> q;
        TreeNode *x = new TreeNode(stoi(nodes[0]));
        q.push(x);
        int i=1;

        while(!q.empty())
        {
            TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "#") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "#") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
        }

        return x;

        
    }
};

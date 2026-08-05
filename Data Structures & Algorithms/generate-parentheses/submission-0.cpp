class Solution {
public:
    void f(int oc,int cc,string &path,vector<string> &ans,int n)
    {

        if(oc == n && cc == n)
        {
            ans.push_back(path); 
            return;
        }

        
        // Try adding an open parenthesis '('
        if (oc < n) {
            path.push_back('(');
            f(oc + 1, cc, path, ans, n);
            path.pop_back(); // Backtrack step: undo addition
        }

        // Try adding a close parenthesis ')'
        if (cc < oc) {
            path.push_back(')');
            f(oc, cc + 1, path, ans, n);
            path.pop_back(); // Backtrack step: undo addition
        }
    
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc =0;
        int cc=0;
        string path="";
        f(oc,cc,path,ans,n);
        return ans;
        
    }
};

class PrefixTree {
public:
    struct Node{
        vector<Node *> nei;
        
        bool end;

        public :
        Node()
        {
           
          nei.resize(26, nullptr);
    
    

            end=false;
        }
    };

    Node *head = new Node();

    PrefixTree() {
        
    }
    void dfs(Node* root,int ind,string &word)
    {
        if(ind == word.size())
        {
            root->end=true;
            return;
        }

        if(root->nei[word[ind]-'a']!=NULL)
        {
            dfs(root->nei[word[ind]-'a'],ind+1,word);
        }
        else{
            root->nei[word[ind]-'a']=new Node();
            dfs(root->nei[word[ind]-'a'],ind+1,word);
        }

        return;
    }


    bool dfs1(Node* root,int ind,string &word)
    {
        if(ind == word.size())
        {
            return root->end;
        }
    

        if(root->nei[word[ind]-'a']!=NULL)
        {
            return dfs1(root->nei[word[ind]-'a'],ind+1,word);
        }

        return false ;
    }

    bool dfs2(Node* root,int ind,string &word)
    {
        if(ind == word.size())
        {
            return true;
        }
    

        if(root->nei[word[ind]-'a']!=NULL)
        {
            return dfs2(root->nei[word[ind]-'a'],ind+1,word);
        }

        return false ;
    }


    
    void insert(string word) {
        int ind = 0;
        dfs(head,ind,word);
    }
    
    bool search(string word) {
        return dfs1(head,0,word);
    }
    
    bool startsWith(string prefix) {
        return dfs2(head,0,prefix);
    }
};

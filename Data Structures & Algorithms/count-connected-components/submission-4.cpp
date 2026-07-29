class Solution {
public:

    int findSet(int a,vector<int> &par)
    {
        if(a==par[a]) return a;

        return par[a] =findSet(par[a],par);
    }

    void unionSet(int a ,int b ,vector<int> &par,vector<int> &sz)
    {
        int x = findSet(a,par);
        int y = findSet(b,par);

        if(findSet(a,par)==findSet(b,par))
        {
            return;
        }
        else{
            if(sz[x]==sz[y])
            {
                par[y]=x;
                sz[x]++;
            }
            else if(sz[x]>sz[y])
            {
                par[y]=x;
             
            }
            else{
                par[x]=y;
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> sz(n,0);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }

        for(int i=0;i<edges.size();i++)
        {
            unionSet(edges[i][0],edges[i][1],par,sz);
        }

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[findSet(i, par)]++;
        }

        return mpp.size();

    }
};

class Solution {
public:
    bool dfs(int i,int par,vector<bool> &visi,vector<vector<int>> &edge)
    {
        visi[i]=true;

        for(auto &it : edge[i])
        {
            if(it==par)continue;

            else if(visi[it]==true )
            {
               return false;
            }
            else if(!dfs(it,i,visi,edge))
            {
                return false;
            }
        }
        return true;
    }



    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visi(n,false);
        vector<vector<int>> edge(n);


        for(int i=0;i<edges.size();i++)
        {
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);

        }

        bool x = dfs(0,-1,visi,edge);

        if(x == false)
        return false;


        for(int i=0;i<visi.size();i++)
        {
            if(visi[i]==false)
            return false;
        }

        return true;
        

    }
};

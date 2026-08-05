class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r = grid.size();
        int c = grid[0].size();

        bool fresh = false;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh=true;
                }

            }

        }

        if(!fresh)return 0;

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,-1,0,1};
        int maxi = 0;
        int cur=0;
        while(!q.empty())
        {
            int sz  = q.size();
            

            for(int i=0;i<sz;i++)
            {
              pair<int,int> xt = q.front();
              q.pop();
              int x = xt.first;
              int y = xt.second;
              for(int k=0;k<4;k++)
              {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && nx <r && ny >=0 && ny< c && grid[nx][ny]==1)
                {
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
              }
             
            }
            cur++;
            maxi = max(cur,maxi);
        }
         






        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
                
            }

        }

        return maxi-1;
        
    }
};

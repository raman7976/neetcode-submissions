class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi =0;
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,-1,0,1};
        queue<pair<int,int>> q;
        int r = grid.size();
        int c = grid[0].size();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    int cur = 1;
                    
                    q.push({i,j});
                    grid[i][j]=-1;
                    
                    while(!q.empty())
                    {
                        
                        int sz = q.size();
                        
                        for(int a=0;a<sz;a++)
                        {
                            pair<int,int> xt = q.front();
                            q.pop();
                            int x = xt.first;
                            int y = xt.second;

                           for(int k=0;k<4;k++)
                           {

                                int nx=x+dx[k];
                                int ny=y+dy[k];

                               if(nx<r && nx>=0 && ny<c && ny>=0 && grid[nx][ny]==1)
                              {
                                grid[nx][ny]=-1;
                                q.push({nx,ny});
                                cur++;
                             }
                         }

                        }

                    }

                    maxi = max(maxi,cur);

                }
            }

        }

        return maxi;
        
    }
};

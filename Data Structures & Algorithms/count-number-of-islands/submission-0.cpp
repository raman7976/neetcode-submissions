class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int count=0;

       vector<int> dx = {1,0,-1,0};
       vector<int> dy = {0,-1,0,1};

       queue<pair<int,int>> q;
       
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {

            if(grid[i][j]=='1')
            {
                q.push({i,j});
                count++;
                while(!q.empty())
                {
                    int sz = q.size();
                    for(int k = 0; k<sz;k++)
                    {
                        auto x = q.front();
                        q.pop();
                        
                        grid[x.first][x.second]='#';

                        for(int a =0;a<4;a++)
                        {
                            int nx = x.first +dx[a];
                            int ny = x.second + dy[a];

                            if(nx<n && nx>=0 && ny>=0 && ny<m && grid[nx][ny]=='1')
                            {
                          
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }

        }
       }

       return count;

       
    }
};
